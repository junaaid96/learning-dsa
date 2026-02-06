// Dynamic Programming: Longest Increasing Subsequence (LIS) in O(n^2).
//
// State:
//   dp[i] = length of LIS ending at index i.
//
// Transition:
//   dp[i] = 1 + max(dp[j]) for all j < i with nums[j] < nums[i],
//           or 1 if none.
//
// Compile: g++ -std=c++17 -O2 dp_lis_n2.cpp -o lis
// Run:     ./lis

#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, std::vector<int>> lis(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) {
        return {0, {}};
    }

    std::vector<int> dp(static_cast<std::size_t>(n), 1);
    std::vector<int> parent(static_cast<std::size_t>(n), -1);

    int bestLength = 1;
    int bestEndIndex = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[static_cast<std::size_t>(j)] < nums[static_cast<std::size_t>(i)] &&
                dp[static_cast<std::size_t>(j)] + 1 > dp[static_cast<std::size_t>(i)]) {
                dp[static_cast<std::size_t>(i)] = dp[static_cast<std::size_t>(j)] + 1;
                parent[static_cast<std::size_t>(i)] = j;
            }
        }
        if (dp[static_cast<std::size_t>(i)] > bestLength) {
            bestLength = dp[static_cast<std::size_t>(i)];
            bestEndIndex = i;
        }
    }

    std::vector<int> sequence;
    for (int i = bestEndIndex; i != -1; i = parent[static_cast<std::size_t>(i)]) {
        sequence.push_back(nums[static_cast<std::size_t>(i)]);
    }
    std::reverse(sequence.begin(), sequence.end());

    return {bestLength, sequence};
}

int main() {
    const std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    const auto [length, sequence] = lis(nums);

    std::cout << "Array: ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    std::cout << "LIS length = " << length << "\n";
    std::cout << "One LIS: ";
    for (int value : sequence) {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    return 0;
}

