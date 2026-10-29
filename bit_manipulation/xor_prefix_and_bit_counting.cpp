// XOR prefix queries and per-bit contribution counting.
//
// Links: https://leetcode.com/problems/xor-queries-of-a-subarray/
//        https://cses.fi/problemset/task/1650  (Range Xor Queries)
//        https://leetcode.com/problems/total-hamming-distance/
//        https://leetcode.com/problems/sum-of-all-subset-xor-totals/
//
// Idea:
//   px[i] = a[0]^...^a[i-1]; xor(l..r) = px[r+1] ^ px[l] (XOR is its own inverse).
//   Per-bit counting: for bit b with c ones among n numbers, c*(n-c) pairs differ.
//   Subset XOR sum: each bit present anywhere contributes 2^(n-1) times -> OR << (n-1).
//
// Time: O(n) / O(32 n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra xor_prefix_and_bit_counting.cpp -o xorp && ./xorp

#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> xorQueries(const std::vector<int>& a, const std::vector<std::vector<int>>& q) {
    std::vector<int> px(a.size() + 1, 0), out;
    for (size_t i = 0; i < a.size(); ++i) px[i + 1] = px[i] ^ a[i];
    for (const auto& lr : q) out.push_back(px[lr[1] + 1] ^ px[lr[0]]);
    return out;
}

long long totalHamming(const std::vector<int>& a) {
    long long res = 0, n = static_cast<long long>(a.size());
    for (int b = 0; b < 31; ++b) {
        long long ones = 0;
        for (int x : a) ones += x >> b & 1;
        res += ones * (n - ones);                 // each (1, 0) pair differs in bit b
    }
    return res;
}

int subsetXorSum(const std::vector<int>& a) {
    int o = 0;
    for (int x : a) o |= x;
    return o << (static_cast<int>(a.size()) - 1);
}

int main() {
    assert((xorQueries({1, 3, 4, 8}, {{0, 1}, {1, 2}, {0, 3}, {3, 3}}) == std::vector<int>{2, 7, 14, 8}));
    assert(totalHamming({4, 14, 2}) == 6);
    assert(subsetXorSum({1, 3}) == 6 && subsetXorSum({5, 1, 6}) == 28);
    std::cout << "xor_prefix_and_bit_counting: all tests passed\n";
    return 0;
}
