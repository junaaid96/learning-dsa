// XPSC Week 15 Day 05 - CSES 1645 Nearest Smaller Values
// Link: https://cses.fi/problemset/task/1645
//
// Problem: for each position, the nearest position to the LEFT with a smaller value (0 if none).
// Idea:    monotonic increasing stack of indices; pop while top >= current.
// Time: O(n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1645_nearest_smaller_values.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> nearestSmaller(const std::vector<int>& a) {
    std::vector<int> st, out;                             // st holds 1-indexed positions
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!st.empty() && a[st.back() - 1] >= a[i]) st.pop_back();   // not smaller -> useless
        out.push_back(st.empty() ? 0 : st.back());
        st.push_back(i + 1);
    }
    return out;
}

int main() {
    assert((nearestSmaller({2, 5, 1, 4, 8, 3, 2, 5}) == std::vector<int>{0, 1, 0, 3, 4, 3, 3, 7}));
    std::cout << "cses_1645_nearest_smaller_values: all tests passed\n";
    return 0;
}
