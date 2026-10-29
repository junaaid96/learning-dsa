// XPSC Week 01 Day 01 - Max Sum Subarray of size K (GfG)
// Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
//
// Problem: maximum sum among all contiguous subarrays of length exactly k.
// Idea:    fixed-size sliding window - add the entering element, remove the leaving one.
// Time: O(n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_max_sum_subarray_size_k.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long maxSumK(const std::vector<int>& a, int k) {
    long long window = 0, best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        window += a[i];                          // element enters on the right
        if (i >= k) window -= a[i - k];          // element leaves on the left
        if (i == k - 1) best = window;           // first full window
        else if (i >= k) best = std::max(best, window);
    }
    return best;
}

int main() {
    assert(maxSumK({100, 200, 300, 400}, 2) == 700);
    assert(maxSumK({100, 200, 300, 400}, 4) == 1000);
    assert(maxSumK({1, 9, -1, 2}, 1) == 9);
    std::cout << "gfg_max_sum_subarray_size_k: all tests passed\n";
    return 0;
}
