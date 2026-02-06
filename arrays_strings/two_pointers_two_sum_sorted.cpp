// Two pointers: two-sum in a sorted array.
//
// Problem:
//   Given a sorted array of integers and a target, find any pair (i, j)
//   such that nums[i] + nums[j] == target. Return indices or report none.
//
// Approach:
//   Use two pointers: left at start, right at end.
//   If sum < target -> move left++  (need larger sum)
//   If sum > target -> move right-- (need smaller sum)
//   If equal        -> answer found
//
// Time:  O(n)
// Space: O(1)
//
// Compile: g++ -std=c++17 -O2 two_pointers_two_sum_sorted.cpp -o two_sum_sorted
// Run:     ./two_sum_sorted

#include <iostream>
#include <vector>
#include <utility>
#include <optional>

std::optional<std::pair<int, int>> twoSumSorted(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left < right) {
        const int sum = nums[left] + nums[right];
        if (sum == target) {
            return std::make_pair(left, right);
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return std::nullopt;
}

int main() {
    const std::vector<int> nums{1, 2, 3, 4, 6, 8, 11};
    const int target = 10;

    const auto result = twoSumSorted(nums, target);
    std::cout << "Array (sorted): ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\nTarget = " << target << "\n";

    if (result.has_value()) {
        const auto [i, j] = result.value();
        std::cout << "Found pair at indices (" << i << ", " << j << ") with values "
                  << nums[i] << " + " << nums[j] << " = " << target << "\n";
    } else {
        std::cout << "No pair found that sums to target.\n";
    }

    return 0;
}

