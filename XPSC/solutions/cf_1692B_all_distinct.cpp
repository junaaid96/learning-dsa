// XPSC Week 02 Day 04 - Codeforces 1692B All Distinct
// Link: https://codeforces.com/contest/1692/problem/B
//
// Problem: repeatedly delete any two elements; maximise length with all distinct.
// Idea:    d = distinct count, extra = n - d duplicates. Each operation removes 2,
//          so if extra is odd we must sacrifice one distinct value: d - 1, else d.
// Time: O(n log n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1692B_all_distinct.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <set>
#include <vector>

int allDistinct(const std::vector<int>& a) {
    int d = static_cast<int>(std::set<int>(a.begin(), a.end()).size());
    int extra = static_cast<int>(a.size()) - d;
    return extra % 2 == 0 ? d : d - 1;                // parity decides
}

int main() {
    assert(allDistinct({2, 2, 2, 3, 3, 3}) == 2);
    assert(allDistinct({9, 1, 9, 9, 1}) == 1);
    assert(allDistinct({15, 16, 16, 15}) == 2);
    assert(allDistinct({10, 100, 1000, 10000}) == 4);
    std::cout << "cf_1692B_all_distinct: all tests passed\n";
    return 0;
}
