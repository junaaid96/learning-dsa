// XPSC Week 16 Day 02 - Codeforces 474B Worms
// Link: https://codeforces.com/problemset/problem/474/B
//
// Problem: worms are labelled consecutively pile by pile; for each label say its pile.
// Idea:    prefix sums of pile sizes are sorted -> lower_bound gives the pile.
// Time: O(n + q log n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cf_474B_worms.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> whichPile(const std::vector<int>& piles, const std::vector<int>& q) {
    std::vector<long long> pre;
    long long s = 0;
    for (int x : piles) pre.push_back(s += x);            // last label of each pile
    std::vector<int> out;
    for (int label : q)                                   // first pile whose end >= label
        out.push_back(static_cast<int>(std::lower_bound(pre.begin(), pre.end(), label) - pre.begin()) + 1);
    return out;
}

int main() {
    assert((whichPile({2, 7, 3, 4, 9}, {1, 25, 11}) == std::vector<int>{1, 5, 3}));
    std::cout << "cf_474B_worms: all tests passed\n";
    return 0;
}
