// Activity selection / Movie Festival (sort by end time, take greedily).
//
// Problem:
//   n movies with [start, end). Watch as many whole movies as possible.
// Link: https://cses.fi/problemset/task/1629
//
// Idea:
//   Always pick the movie that ends earliest among those that start after the
//   last chosen end. Finishing early leaves the most room for the rest
//   (exchange argument).
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra activity_selection_movie_festival.cpp -o act && ./act

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

int maxMovies(std::vector<std::pair<int, int>> mv) {
    std::sort(mv.begin(), mv.end(), [](auto& a, auto& b) { return a.second < b.second; });
    int count = 0, lastEnd = 0;                   // times are >= 1 in CSES
    for (auto [s, e] : mv)
        if (s >= lastEnd) { ++count; lastEnd = e; }  // compatible -> watch it
    return count;
}

int main() {
    assert(maxMovies({{3, 5}, {4, 9}, {5, 8}}) == 2);   // CSES sample
    assert(maxMovies({{1, 2}, {2, 3}, {3, 4}}) == 3);
    std::cout << "activity_selection_movie_festival: all tests passed\n";
    return 0;
}
