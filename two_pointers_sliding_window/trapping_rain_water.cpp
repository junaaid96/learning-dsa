// Trapping Rain Water (two pointers with running maxima).
//
// Problem:
//   Given bar heights, compute how much water is trapped after raining.
// Link: https://leetcode.com/problems/trapping-rain-water/
//
// Idea:
//   Water above i = min(maxLeft, maxRight) - h[i]. Move the side whose max is
//   smaller: that side's water level is already decided by its own max.
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra trapping_rain_water.cpp -o trw && ./trw

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long trap(const std::vector<int>& h) {
    int l = 0, r = static_cast<int>(h.size()) - 1;
    int leftMax = 0, rightMax = 0;                 // tallest bar seen from each side
    long long water = 0;
    while (l < r) {
        if (h[l] < h[r]) {                         // left side is the bottleneck
            leftMax = std::max(leftMax, h[l]);
            water += leftMax - h[l];               // water above bar l
            ++l;
        } else {                                   // right side is the bottleneck
            rightMax = std::max(rightMax, h[r]);
            water += rightMax - h[r];
            --r;
        }
    }
    return water;
}

int main() {
    assert(trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);
    assert(trap({4, 2, 0, 3, 2, 5}) == 9);
    assert(trap({}) == 0);
    std::cout << "trapping_rain_water: all tests passed\n";
    return 0;
}
