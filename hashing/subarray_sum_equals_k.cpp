// Subarray Sum Equals K (prefix sum + hash map counting).
//
// Problem:
//   Count contiguous subarrays whose sum equals k (values may be negative).
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
//
// Idea:
//   Let P[i] be the prefix sum. Subarray (j, i] sums to k iff P[j] = P[i] - k.
//   While scanning, keep how many times each prefix sum occurred so far.
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra subarray_sum_equals_k.cpp -o ssk && ./ssk

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

long long subarraySum(const std::vector<int>& nums, long long k) {
    std::unordered_map<long long, long long> freq;  // prefix sum -> how many times seen
    freq[0] = 1;                                    // empty prefix (sum 0) exists once
    long long prefix = 0, count = 0;
    for (int x : nums) {
        prefix += x;                                // running prefix sum P[i]
        auto it = freq.find(prefix - k);            // earlier prefixes P[j] = P[i] - k
        if (it != freq.end()) count += it->second;  // each one gives a valid subarray
        freq[prefix]++;                             // record current prefix
    }
    return count;
}

int main() {
    assert(subarraySum({1, 1, 1}, 2) == 2);
    assert(subarraySum({1, 2, 3}, 3) == 2);
    assert(subarraySum({1, -1, 0}, 0) == 3);
    std::cout << "subarray_sum_equals_k: all tests passed\n";
    return 0;
}
