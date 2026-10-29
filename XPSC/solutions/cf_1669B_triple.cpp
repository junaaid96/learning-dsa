// XPSC Week 02 Day 04 - Codeforces 1669B Triple
// Link: https://codeforces.com/problemset/problem/1669/B
//
// Problem: print any value that appears at least 3 times, or -1.
// Idea:    frequency array (values <= n).
// Time: O(n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1669B_triple.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

int triple(const std::vector<int>& a) {
    std::vector<int> f(a.size() + 1, 0);
    for (int x : a) if (++f[x] == 3) return x;            // first to reach 3
    return -1;
}

int main() {
    assert(triple({1}) == -1);
    assert(triple({2, 2, 3, 3, 4, 2, 2}) == 2);
    assert(triple({1, 4, 3, 4, 3, 2, 4, 1}) == 4);
    assert(triple({1, 1, 2, 2, 2, 3, 3, 3, 4}) == 2);
    std::cout << "cf_1669B_triple: all tests passed\n";
    return 0;
}
