// Koko Eating Bananas (binary search on the answer).
//
// Problem:
//   piles[i] bananas; Koko eats at speed k per hour (one pile per hour max).
//   Find the minimum k so she finishes within h hours.
// Link: https://leetcode.com/problems/koko-eating-bananas/
//
// Idea:
//   If speed k works, any faster speed works too (monotonic predicate). So
//   binary search the smallest k in [1, max(piles)] where hoursNeeded(k) <= h.
//
// Time: O(n log max)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra koko_eating_bananas.cpp -o koko && ./koko

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int minEatingSpeed(const std::vector<int>& piles, long long h) {
    auto ok = [&](long long k) {                   // can she finish at speed k?
        long long hours = 0;
        for (int p : piles) hours += (p + k - 1) / k;   // ceil(p / k) hours per pile
        return hours <= h;
    };
    long long lo = 1, hi = *std::max_element(piles.begin(), piles.end());
    while (lo < hi) {                              // find first true in [lo, hi]
        long long mid = lo + (hi - lo) / 2;        // avoids overflow of lo + hi
        if (ok(mid)) hi = mid;                     // mid works -> answer <= mid
        else lo = mid + 1;                         // mid fails -> answer > mid
    }
    return static_cast<int>(lo);
}

int main() {
    assert(minEatingSpeed({3, 6, 7, 11}, 8) == 4);
    assert(minEatingSpeed({30, 11, 23, 4, 20}, 5) == 30);
    assert(minEatingSpeed({30, 11, 23, 4, 20}, 6) == 23);
    std::cout << "koko_eating_bananas: all tests passed\n";
    return 0;
}
