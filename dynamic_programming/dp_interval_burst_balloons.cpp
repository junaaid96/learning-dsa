// Interval DP: Burst Balloons / Matrix chain style.
//
// Problem:
//   Bursting balloon i gives nums[left]*nums[i]*nums[right] coins with its
//   current neighbours. Maximize total coins.
// Link: https://leetcode.com/problems/burst-balloons/
//
// Idea:
//   Pad with 1 on both ends. dp[l][r] = best for the open interval (l, r).
//   Choose k = the LAST balloon burst inside (l, r): its neighbours are then
//   exactly l and r, splitting into independent (l, k) and (k, r).
//
// Time: O(n^3)    Space: O(n^2)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_interval_burst_balloons.cpp -o burst && ./burst

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int maxCoins(std::vector<int> nums) {
    nums.insert(nums.begin(), 1); nums.push_back(1);        // virtual balloons of value 1
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int len = 2; len < n; ++len)                        // interval length r - l
        for (int l = 0; l + len < n; ++l) {
            int r = l + len;
            for (int k = l + 1; k < r; ++k)                  // k burst last in (l, r)
                dp[l][r] = std::max(dp[l][r], dp[l][k] + nums[l] * nums[k] * nums[r] + dp[k][r]);
        }
    return dp[0][n - 1];
}

int main() {
    assert(maxCoins({3, 1, 5, 8}) == 167);
    assert(maxCoins({1, 5}) == 10);
    std::cout << "dp_interval_burst_balloons: all tests passed\n";
    return 0;
}
