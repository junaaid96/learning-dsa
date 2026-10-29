// Container With Most Water (opposite-direction two pointers).
//
// Problem:
//   Lines of height h[i] at x = i. Pick two lines forming a container with the
//   largest area = min(h[l], h[r]) * (r - l).
// Link: https://leetcode.com/problems/container-with-most-water/
//
// Idea:
//   Start with the widest pair. The shorter line limits the area, and moving
//   the taller one inward can never help, so always move the shorter side.
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra container_with_most_water.cpp -o cwm && ./cwm

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long maxArea(const std::vector<int>& h) {
    int l = 0, r = static_cast<int>(h.size()) - 1;   // widest possible container
    long long best = 0;
    while (l < r) {
        const long long area = 1LL * std::min(h[l], h[r]) * (r - l);  // current area
        best = std::max(best, area);
        if (h[l] < h[r]) ++l; else --r;              // discard the shorter wall
    }
    return best;
}

int main() {
    assert(maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    assert(maxArea({1, 1}) == 1);
    std::cout << "container_with_most_water: all tests passed\n";
    return 0;
}
