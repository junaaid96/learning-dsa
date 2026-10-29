// XPSC Week 02 Day 04 - Codeforces 1676B Equal Candies
// Link: https://codeforces.com/contest/1676/problem/B
//
// Problem: you may only eat candies; make all boxes equal eating the minimum.
// Idea:    every box must go down to the minimum -> sum(a) - n * min(a).
// Time: O(n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1676B_equal_candies.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

long long equalCandies(const std::vector<long long>& a) {
    long long mn = *std::min_element(a.begin(), a.end());
    long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    return sum - mn * static_cast<long long>(a.size());
}

int main() {
    assert(equalCandies({1, 2, 3, 4, 5}) == 10);
    assert(equalCandies({1000, 1000, 5, 1000, 1000, 1000}) == 4975);
    assert(equalCandies({1, 2, 3, 5, 1, 2, 7, 9, 13, 5}) == 38);
    assert(equalCandies({8, 8, 8}) == 0);
    std::cout << "cf_1676B_equal_candies: all tests passed\n";
    return 0;
}
