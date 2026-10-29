// XPSC Week 01 Day 01 - First negative integer in every window of size k (GfG)
// Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
//
// Problem: for each window of size k print its first negative number (0 if none).
// Idea:    keep indices of negatives in a queue; drop indices that left the window.
// Time: O(n)   Space: O(k)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_first_negative_in_window.cpp && ./a.out

#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

std::vector<long long> firstNegative(const std::vector<long long>& a, int k) {
    std::deque<int> neg;                              // indices of negatives, in order
    std::vector<long long> out;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (a[i] < 0) neg.push_back(i);
        if (!neg.empty() && neg.front() <= i - k) neg.pop_front();   // outside window
        if (i >= k - 1) out.push_back(neg.empty() ? 0 : a[neg.front()]);
    }
    return out;
}

int main() {
    assert((firstNegative({-8, 2, 3, -6, 10}, 2) == std::vector<long long>{-8, 0, -6, -6}));
    assert((firstNegative({12, -1, -7, 8, -15, 30, 16, 28}, 3) == std::vector<long long>{-1, -1, -7, -15, -15, 0}));
    std::cout << "gfg_first_negative_in_window: all tests passed\n";
    return 0;
}
