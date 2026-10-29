// 3Sum (sort + two pointers).
//
// Problem:
//   Return all unique triplets [a, b, c] in nums with a + b + c == 0.
// Link: https://leetcode.com/problems/3sum/
//
// Idea:
//   Sort. Fix the first element i, then find pairs in (i, n) summing to
//   -nums[i] with two pointers l and r moving toward each other. Skip equal
//   values to avoid duplicate triplets.
//
// Time: O(n^2)    Space: O(1) extra (besides output)
//
// Compile: g++ -std=c++17 -Wall -Wextra three_sum.cpp -o three_sum && ./three_sum

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());                      // sorting enables two pointers
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;        // same first value -> duplicates
        int l = i + 1, r = n - 1;                             // search window right of i
        while (l < r) {
            const long long s = 0LL + nums[i] + nums[l] + nums[r];
            if (s < 0) ++l;                                   // need bigger sum -> move l right
            else if (s > 0) --r;                              // need smaller sum -> move r left
            else {
                res.push_back({nums[i], nums[l], nums[r]});  // found one triplet
                ++l; --r;
                while (l < r && nums[l] == nums[l - 1]) ++l;  // skip duplicate seconds
                while (l < r && nums[r] == nums[r + 1]) --r;  // skip duplicate thirds
            }
        }
    }
    return res;
}

int main() {
    auto r = threeSum({-1, 0, 1, 2, -1, -4});
    assert((r == std::vector<std::vector<int>>{{-1, -1, 2}, {-1, 0, 1}}));
    assert(threeSum({0, 1, 1}).empty());
    assert((threeSum({0, 0, 0, 0}) == std::vector<std::vector<int>>{{0, 0, 0}}));
    std::cout << "three_sum: all tests passed\n";
    return 0;
}
