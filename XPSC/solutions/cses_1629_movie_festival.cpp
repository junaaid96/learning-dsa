// XPSC Week 15 Day 01 - CSES 1629 Movie Festival
// Link: https://cses.fi/problemset/task/1629
//
// Problem: maximum number of non-overlapping movies you can watch fully.
// Idea:    classic activity selection - sort by end time, take whatever fits.
// Time: O(n log n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1629_movie_festival.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

int maxMovies(std::vector<std::pair<int, int>> m) {
    std::sort(m.begin(), m.end(), [](auto& a, auto& b) { return a.second < b.second; });
    int cnt = 0, freeAt = 0;
    for (auto [s, e] : m) if (s >= freeAt) { ++cnt; freeAt = e; }   // earliest finish first
    return cnt;
}

int main() {
    assert(maxMovies({{3, 5}, {4, 9}, {5, 8}}) == 2);
    std::cout << "cses_1629_movie_festival: all tests passed\n";
    return 0;
}
