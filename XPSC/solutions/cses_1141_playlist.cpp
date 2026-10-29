// XPSC Week 14 Day 07 - CSES 1141 Playlist
// Link: https://cses.fi/problemset/task/1141
//
// Problem: longest contiguous run of songs with no repeats.
// Idea:    variable sliding window; map value -> last index; jump left past a repeat.
// Time: O(n log n) with map   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1141_playlist.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

int longestUnique(const std::vector<int>& a) {
    std::map<int, int> last;
    int best = 0;
    for (int l = 0, r = 0; r < static_cast<int>(a.size()); ++r) {
        auto it = last.find(a[r]);
        if (it != last.end() && it->second >= l) l = it->second + 1;   // repeat inside window
        last[a[r]] = r;
        best = std::max(best, r - l + 1);
    }
    return best;
}

int main() {
    assert(longestUnique({1, 2, 1, 3, 2, 7, 4, 2}) == 5);
    assert(longestUnique({5, 5, 5}) == 1);
    std::cout << "cses_1141_playlist: all tests passed\n";
    return 0;
}
