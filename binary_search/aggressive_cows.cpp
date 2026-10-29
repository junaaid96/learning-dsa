// Aggressive Cows (maximize the minimum distance; binary search on answer).
//
// Problem:
//   n stalls at positions x[i], place c cows so that the minimum distance
//   between any two cows is as large as possible. Print that distance.
// Link: https://www.spoj.com/problems/AGGRCOW/
//
// Idea:
//   Predicate canPlace(d): greedily put a cow in the first stall, then in the
//   next stall at distance >= d, and so on. If it works for d it works for
//   any smaller d, so search for the LAST d where it is true.
//
// Time: O(n log n + n log range)    Space: O(1) extra
//
// Compile: g++ -std=c++17 -Wall -Wextra aggressive_cows.cpp -o cows && ./cows

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long largestMinDistance(std::vector<long long> x, int cows) {
    std::sort(x.begin(), x.end());                           // greedy needs sorted stalls
    auto canPlace = [&](long long d) {
        int placed = 1;                                      // first cow in first stall
        long long last = x[0];
        for (std::size_t i = 1; i < x.size(); ++i)
            if (x[i] - last >= d) { ++placed; last = x[i]; } // far enough -> place
        return placed >= cows;
    };
    long long lo = 0, hi = x.back() - x.front();             // answer lies in [0, span]
    while (lo < hi) {                                        // find last true
        long long mid = lo + (hi - lo + 1) / 2;              // upper mid avoids infinite loop
        if (canPlace(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    assert(largestMinDistance({1, 2, 8, 4, 9}, 3) == 3);    // SPOJ sample
    assert(largestMinDistance({0, 3, 4, 7, 10, 9}, 4) == 3);
    std::cout << "aggressive_cows: all tests passed\n";
    return 0;
}
