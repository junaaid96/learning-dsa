// XPSC Week 05 Day 05 - Codeforces 1742D Coprime
// Link: https://codeforces.com/contest/1742/problem/D
//
// Problem: maximise i + j (1-indexed) with gcd(a_i, a_j) = 1, or -1.
// Idea:    values are <= 1000: keep only the LAST index of every value, then try
//          all 1000 x 1000 value pairs.
// Time: O(n + 1000^2 log)   Space: O(1000)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1742D_coprime.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

int coprimeMax(const std::vector<int>& a) {
    std::vector<int> last(1001, 0);
    for (int i = 0; i < static_cast<int>(a.size()); ++i) last[a[i]] = i + 1;   // latest index wins
    int best = -1;
    for (int x = 1; x <= 1000; ++x) if (last[x])
        for (int y = x; y <= 1000; ++y) if (last[y] && std::gcd(x, y) == 1)
            best = std::max(best, last[x] + last[y]);
    return best;
}

int main() {
    assert(coprimeMax({3, 2, 1}) == 6);
    assert(coprimeMax({1, 3, 5, 2, 4, 7, 7}) == 12);
    assert(coprimeMax({1, 2, 3, 4, 5}) == 9);
    assert(coprimeMax({2, 4, 6, 8}) == -1);
    std::cout << "cf_1742D_coprime: all tests passed\n";
    return 0;
}
