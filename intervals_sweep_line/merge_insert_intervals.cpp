// Intervals: merge, insert, non-overlapping removal, meeting rooms (min rooms).
//
// Links: https://leetcode.com/problems/merge-intervals/
//        https://leetcode.com/problems/insert-interval/
//        https://leetcode.com/problems/non-overlapping-intervals/
//        https://leetcode.com/problems/meeting-rooms-ii/  (premium; same as CSES 1164 Room Allocation)
//        https://cses.fi/problemset/task/1164
//
// Idea:
//   Sort by start, then a new interval either extends the last one or starts a
//   fresh block. Removal: greedy by earliest END (keep what frees time soonest).
//   Rooms: sweep +1 at start, -1 at end; answer is the running max.
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra merge_insert_intervals.cpp -o iv && ./iv

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using Iv = std::vector<int>;

std::vector<Iv> mergeIntervals(std::vector<Iv> a) {
    std::sort(a.begin(), a.end());
    std::vector<Iv> out;
    for (const Iv& x : a) {
        if (!out.empty() && x[0] <= out.back()[1]) out.back()[1] = std::max(out.back()[1], x[1]);  // overlap
        else out.push_back(x);                                                                   // gap
    }
    return out;
}

std::vector<Iv> insertInterval(const std::vector<Iv>& a, Iv nw) {   // a sorted, disjoint
    std::vector<Iv> out;
    size_t i = 0;
    while (i < a.size() && a[i][1] < nw[0]) out.push_back(a[i++]);         // fully left
    while (i < a.size() && a[i][0] <= nw[1]) {                            // overlapping: absorb
        nw[0] = std::min(nw[0], a[i][0]); nw[1] = std::max(nw[1], a[i][1]); ++i;
    }
    out.push_back(nw);
    while (i < a.size()) out.push_back(a[i++]);                           // fully right
    return out;
}

int eraseOverlap(std::vector<Iv> a) {
    std::sort(a.begin(), a.end(), [](const Iv& x, const Iv& y) { return x[1] < y[1]; });
    int kept = 0, end = -1'000'000'000;
    for (const Iv& x : a) if (x[0] >= end) { ++kept; end = x[1]; }     // compatible -> keep
    return static_cast<int>(a.size()) - kept;
}

int minRooms(const std::vector<Iv>& a) {             // half-open [s, e)
    std::vector<std::pair<int, int>> ev;
    for (const Iv& x : a) { ev.push_back({x[0], +1}); ev.push_back({x[1], -1}); }
    std::sort(ev.begin(), ev.end());                 // at equal time, -1 sorts before +1
    int cur = 0, best = 0;
    for (auto [t, d] : ev) { (void)t; cur += d; best = std::max(best, cur); }
    return best;
}

int main() {
    assert((mergeIntervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}) == std::vector<Iv>{{1, 6}, {8, 10}, {15, 18}}));
    assert((mergeIntervals({{1, 4}, {4, 5}}) == std::vector<Iv>{{1, 5}}));
    assert((insertInterval({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}) == std::vector<Iv>{{1, 2}, {3, 10}, {12, 16}}));
    assert(eraseOverlap({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) == 1);
    assert(minRooms({{0, 30}, {5, 10}, {15, 20}}) == 2 && minRooms({{7, 10}, {2, 4}}) == 1);
    std::cout << "merge_insert_intervals: all tests passed\n";
    return 0;
}
