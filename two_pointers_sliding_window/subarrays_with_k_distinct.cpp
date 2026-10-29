// Subarrays with K Different Integers ("exactly K = atMost(K) - atMost(K-1)").
//
// Problem:
//   Count subarrays containing exactly k distinct integers.
// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
//
// Idea:
//   Counting "exactly" with a window is awkward, but "at most k distinct" is
//   easy: for each r, the number of valid windows ending at r is r - l + 1.
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra subarrays_with_k_distinct.cpp -o skd && ./skd

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

long long atMost(const std::vector<int>& a, int k) {
    if (k < 0) return 0;
    std::unordered_map<int, int> cnt;              // value -> count inside window
    long long total = 0;
    int l = 0;
    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        if (cnt[a[r]]++ == 0) --k;                 // new distinct value uses one "slot"
        while (k < 0) {                            // too many distinct -> shrink
            if (--cnt[a[l]] == 0) ++k;             // value fully removed frees a slot
            ++l;
        }
        total += r - l + 1;                        // all windows [x, r] with x >= l
    }
    return total;
}

long long subarraysWithKDistinct(const std::vector<int>& a, int k) {
    return atMost(a, k) - atMost(a, k - 1);
}

int main() {
    assert(subarraysWithKDistinct({1, 2, 1, 2, 3}, 2) == 7);
    assert(subarraysWithKDistinct({1, 2, 1, 3, 4}, 3) == 3);
    std::cout << "subarrays_with_k_distinct: all tests passed\n";
    return 0;
}
