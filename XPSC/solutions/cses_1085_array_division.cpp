// XPSC Week 14 Day 06 - CSES 1085 Array Division
// Link: https://cses.fi/problemset/task/1085
//
// Problem: split the array into k contiguous parts minimising the largest part sum.
// Idea:    binary search the answer S; greedily cut whenever the running sum would
//          exceed S and check we used <= k parts.
// Time: O(n log(sum))   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1085_array_division.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

long long arrayDivision(const std::vector<long long>& a, int k) {
    auto parts = [&](long long S) {
        int cnt = 1; long long cur = 0;
        for (long long x : a) {
            if (cur + x > S) { ++cnt; cur = 0; }          // start a new part
            cur += x;
        }
        return cnt;
    };
    long long lo = *std::max_element(a.begin(), a.end());  // a part holds at least one element
    long long hi = std::accumulate(a.begin(), a.end(), 0LL);
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (parts(mid) <= k) hi = mid; else lo = mid + 1;
    }
    return lo;
}

int main() {
    assert(arrayDivision({2, 4, 7, 3, 5}, 3) == 8);
    assert(arrayDivision({1, 1, 1, 1}, 4) == 1);
    std::cout << "cses_1085_array_division: all tests passed\n";
    return 0;
}
