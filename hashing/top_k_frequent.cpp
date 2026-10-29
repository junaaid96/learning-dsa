// Top K Frequent Elements (hash map + bucket sort).
//
// Problem:
//   Return the k most frequent elements of an array.
// Link: https://leetcode.com/problems/top-k-frequent-elements/
//
// Idea:
//   Count frequencies with a hash map. A frequency is between 1 and n, so put
//   each value into bucket[freq] and read buckets from high to low.
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra top_k_frequent.cpp -o topk && ./topk

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;                       // value -> count
    for (int x : nums) freq[x]++;
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> bucket(n + 1);             // bucket[c] = values with count c
    for (auto& [val, c] : freq) bucket[c].push_back(val);
    std::vector<int> out;
    for (int c = n; c >= 1 && static_cast<int>(out.size()) < k; --c)  // highest counts first
        for (int v : bucket[c])
            if (static_cast<int>(out.size()) < k) out.push_back(v);
    return out;
}

int main() {
    auto r = topKFrequent({1, 1, 1, 2, 2, 3}, 2);
    std::sort(r.begin(), r.end());
    assert((r == std::vector<int>{1, 2}));
    assert((topKFrequent({1}, 1) == std::vector<int>{1}));
    std::cout << "top_k_frequent: all tests passed\n";
    return 0;
}
