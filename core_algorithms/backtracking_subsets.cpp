// Backtracking: generate all subsets (power set) of a given set of integers.
//
// Compile: g++ -std=c++17 -O2 backtracking_subsets.cpp -o subsets
// Run:     ./subsets

#include <iostream>
#include <vector>

void backtrackSubsets(
    const std::vector<int>& nums,
    int index,
    std::vector<int>& current,
    std::vector<std::vector<int>>& all
) {
    if (index == static_cast<int>(nums.size())) {
        all.push_back(current);
        return;
    }

    // Choice 1: exclude nums[index]
    backtrackSubsets(nums, index + 1, current, all);

    // Choice 2: include nums[index]
    current.push_back(nums[static_cast<std::size_t>(index)]);
    backtrackSubsets(nums, index + 1, current, all);
    current.pop_back();
}

int main() {
    const std::vector<int> nums{1, 2, 3};
    std::vector<int> current;
    std::vector<std::vector<int>> all;

    backtrackSubsets(nums, 0, current, all);

    std::cout << "Subsets:\n";
    for (const std::vector<int>& subset : all) {
        std::cout << "{ ";
        for (int value : subset) {
            std::cout << value << ' ';
        }
        std::cout << "}\n";
    }

    return 0;
}

