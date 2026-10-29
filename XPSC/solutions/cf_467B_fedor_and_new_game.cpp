// XPSC Week 07 Day 01 - Codeforces 467B Fedor and New Game
// Link: https://codeforces.com/problemset/problem/467/B
//
// Problem: armies are bitmasks; count players whose army differs from Fedor's
//          (the last one) in at most k bits.
// Idea:    differing bits = popcount(x ^ fedor).
// Time: O(m)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_467B_fedor_and_new_game.cpp && ./a.out

#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>

int friends(const std::vector<unsigned>& armies, int k) {   // last element is Fedor
    unsigned fedor = armies.back();
    int cnt = 0;
    for (size_t i = 0; i + 1 < armies.size(); ++i)
        if (static_cast<int>(std::bitset<32>(armies[i] ^ fedor).count()) <= k) ++cnt;
    return cnt;
}

int main() {
    assert(friends({8, 5, 111, 17}, 1) == 0);
    assert(friends({1, 2, 3, 4}, 3) == 3);
    std::cout << "cf_467B_fedor_and_new_game: all tests passed\n";
    return 0;
}
