// XPSC Week 15 Day 06 - CSES 1660 Subarray Sums I
// Link: https://cses.fi/problemset/task/1660
//
// Problem: count subarrays with sum x (all values positive).
// Idea:    positives -> sliding window: grow right, shrink left while sum > x.
// Time: O(n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1660_subarray_sums_i.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

int countSumX(const std::vector<long long>& a, long long x) {
    long long sum = 0;
    int cnt = 0;
    for (size_t l = 0, r = 0; r < a.size(); ++r) {
        sum += a[r];
        while (sum > x) sum -= a[l++];                    // too big -> drop from left
        if (sum == x) ++cnt;
    }
    return cnt;
}

int main() {
    assert(countSumX({2, 4, 1, 2, 7}, 7) == 3);
    std::cout << "cses_1660_subarray_sums_i: all tests passed\n";
    return 0;
}
