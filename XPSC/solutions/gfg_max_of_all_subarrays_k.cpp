// XPSC Week 01 Day 01 - Maximum of all subarrays of size k (GfG)
// Link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1
//
// Problem: maximum of every window of size k.
// Idea:    monotonic deque of indices with decreasing values; front is the max.
// Time: O(n)   Space: O(k)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_max_of_all_subarrays_k.cpp && ./a.out

#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

std::vector<int> maxOfSubarrays(const std::vector<int>& a, int k) {
    std::deque<int> dq;
    std::vector<int> out;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();   // can never be max again
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();                     // slid out
        if (i >= k - 1) out.push_back(a[dq.front()]);
    }
    return out;
}

int main() {
    assert((maxOfSubarrays({1, 2, 3, 1, 4, 5, 2, 3, 6}, 3) == std::vector<int>{3, 3, 4, 5, 5, 5, 6}));
    assert((maxOfSubarrays({8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, 4) == std::vector<int>{10, 10, 10, 15, 15, 90, 90}));
    std::cout << "gfg_max_of_all_subarrays_k: all tests passed\n";
    return 0;
}
