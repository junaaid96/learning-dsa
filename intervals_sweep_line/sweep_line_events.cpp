// Sweep line: max overlap (Restaurant Customers) and skyline-style coverage length.
//
// Links: https://cses.fi/problemset/task/1619  (Restaurant Customers)
//        https://leetcode.com/problems/car-pooling/
//        https://leetcode.com/problems/my-calendar-ii/
//
// Idea:
//   Turn every interval into two events (time, +delta) and (time, -delta),
//   sort, and scan while maintaining the current load. With a std::map you can
//   do it online (difference map).
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra sweep_line_events.cpp -o sweep && ./sweep

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int maxCustomers(const std::vector<std::pair<int, int>>& v) {   // all times distinct (CSES)
    std::vector<std::pair<int, int>> ev;
    for (auto [a, b] : v) { ev.push_back({a, 1}); ev.push_back({b, -1}); }
    std::sort(ev.begin(), ev.end());
    int cur = 0, best = 0;
    for (const auto& e : ev) { cur += e.second; best = std::max(best, cur); }
    return best;
}

bool carPooling(const std::vector<std::vector<int>>& trips, int capacity) {
    std::map<int, int> diff;                          // location -> passenger change
    for (const auto& t : trips) { diff[t[1]] += t[0]; diff[t[2]] -= t[0]; }   // drop-off frees seats
    int cur = 0;
    for (const auto& [loc, d] : diff) { (void)loc; cur += d; if (cur > capacity) return false; }
    return true;
}

// total length covered by the union of [l, r) segments
long long coveredLength(std::vector<std::pair<int, int>> seg) {
    std::vector<std::pair<int, int>> ev;
    for (auto [l, r] : seg) { ev.push_back({l, 1}); ev.push_back({r, -1}); }
    std::sort(ev.begin(), ev.end());
    long long total = 0;
    int cur = 0, prev = 0;
    for (auto [x, d] : ev) {
        if (cur > 0) total += x - prev;               // previous stretch was covered
        cur += d; prev = x;
    }
    return total;
}

int main() {
    assert(maxCustomers({{5, 8}, {2, 4}, {3, 9}}) == 2);          // CSES 1619 sample
    assert(!carPooling({{2, 1, 5}, {3, 3, 7}}, 4) && carPooling({{2, 1, 5}, {3, 3, 7}}, 5));
    assert(coveredLength({{1, 3}, {2, 5}, {7, 8}}) == 5);
    std::cout << "sweep_line_events: all tests passed\n";
    return 0;
}
