// Difference array: many "add v to range [l, r]" updates, then read all values.
//
// Problem (Corporate Flight Bookings):
//   bookings[i] = {first, last, seats}: add seats to flights first..last
//   (1-indexed). Return total seats per flight.
// Link: https://leetcode.com/problems/corporate-flight-bookings/
//
// Idea:
//   d[l] += v, d[r+1] -= v marks where an addition starts and stops. The
//   prefix sum of d recovers the final array.
//
// Time: O(n + q)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra difference_array_range_add.cpp -o diff && ./diff

#include <cassert>
#include <iostream>
#include <vector>

std::vector<long long> corpFlightBookings(const std::vector<std::vector<int>>& bookings, int n) {
    std::vector<long long> d(n + 2, 0);              // one extra slot for r + 1
    for (const auto& b : bookings) {
        d[b[0]] += b[2];                             // start adding at first
        d[b[1] + 1] -= b[2];                         // stop after last
    }
    std::vector<long long> ans(n);
    long long run = 0;
    for (int i = 1; i <= n; ++i) {
        run += d[i];                                 // prefix sum = actual value
        ans[i - 1] = run;
    }
    return ans;
}

int main() {
    auto r = corpFlightBookings({{1, 2, 10}, {2, 3, 20}, {2, 5, 25}}, 5);
    assert((r == std::vector<long long>{10, 55, 45, 25, 25}));
    std::cout << "difference_array_range_add: all tests passed\n";
    return 0;
}
