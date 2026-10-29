// Two Sum (unsorted array) using a hash map.
//
// Problem:
//   Given nums and target, return indices i < j with nums[i] + nums[j] == target.
//   Exactly one answer exists.
// Link: https://leetcode.com/problems/two-sum/
//
// Idea:
//   Walk left to right. For each value x we need (target - x). If we have
//   already seen that complement, we are done; otherwise remember x's index.
//
// Time:  O(n) average (each hash lookup/insert is O(1) on average)
// Space: O(n) for the hash map
//
// Compile: g++ -std=c++17 -Wall -Wextra two_sum_hashmap.cpp -o two_sum && ./two_sum

#include <cassert>        // assert() for self-checks
#include <iostream>       // std::cout
#include <unordered_map>  // hash map: value -> index
#include <vector>         // std::vector

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;                 // value -> index where we saw it
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        const int need = target - nums[i];             // the partner we are looking for
        auto it = seen.find(need);                     // O(1) average lookup
        if (it != seen.end()) return {it->second, i};  // found: earlier index first
        seen[nums[i]] = i;                             // remember current value
    }
    return {};                                         // no pair (not expected by problem)
}

int main() {
    assert((twoSum({2, 7, 11, 15}, 9) == std::vector<int>{0, 1}));
    assert((twoSum({3, 2, 4}, 6) == std::vector<int>{1, 2}));
    assert((twoSum({3, 3}, 6) == std::vector<int>{0, 1}));
    std::cout << "two_sum_hashmap: all tests passed\n";
    return 0;
}
