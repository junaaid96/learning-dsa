// Subset Sum / Partition Equal Subset Sum (0/1 knapsack on booleans).
//
// Problem:
//   Can the array be split into two subsets with equal sum?
// Link: https://leetcode.com/problems/partition-equal-subset-sum/
//
// Idea:
//   Need a subset with sum total/2. can[s] = some subset sums to s. For each
//   number, iterate s DOWNWARD so each item is used at most once.
//   std::bitset does the same in one shift: bits |= bits << x.
//
// Time: O(n * sum)  (bitset: O(n * sum / 64))    Space: O(sum)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_partition_subset_sum.cpp -o part && ./part

#include <bitset>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

bool canPartition(const std::vector<int>& a) {
    int total = std::accumulate(a.begin(), a.end(), 0);
    if (total % 2) return false;                     // odd total cannot split evenly
    int target = total / 2;
    std::vector<bool> can(target + 1, false);
    can[0] = true;                                   // empty subset
    for (int x : a)
        for (int s = target; s >= x; --s)            // downward: x used at most once
            if (can[s - x]) can[s] = true;
    return can[target];
}

bool canPartitionBitset(const std::vector<int>& a) {
    int total = std::accumulate(a.begin(), a.end(), 0);
    if (total % 2) return false;
    std::bitset<20001> bits;                         // bit s set <=> sum s reachable
    bits[0] = 1;
    for (int x : a) bits |= bits << x;               // add x to every reachable sum
    return bits[total / 2];
}

int main() {
    assert(canPartition({1, 5, 11, 5}));
    assert(!canPartition({1, 2, 3, 5}));
    assert(canPartitionBitset({1, 5, 11, 5}));
    assert(!canPartitionBitset({1, 2, 3, 5}));
    std::cout << "dp_partition_subset_sum: all tests passed\n";
    return 0;
}
