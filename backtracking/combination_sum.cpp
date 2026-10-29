// Combination Sum (unlimited reuse) and Combination Sum II (each used once).
//
// Problems:
//   Find all unique combinations of candidates that sum to target.
// Links: https://leetcode.com/problems/combination-sum/
//        https://leetcode.com/problems/combination-sum-ii/
//
// Idea:
//   Recurse with a start index so combinations are built in non-decreasing
//   index order (avoids permutations of the same set). For reuse, recurse
//   with the same index i; for single use recurse with i + 1 and skip equal
//   neighbours at the same depth. Sorting lets us stop early (break).
//
// Time: exponential (output-sensitive)    Space: O(target) recursion
//
// Compile: g++ -std=c++17 -Wall -Wextra combination_sum.cpp -o cs && ./cs

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using VVI = std::vector<std::vector<int>>;

void go(const std::vector<int>& c, int start, int remain, bool reuse,
        std::vector<int>& path, VVI& out) {
    if (remain == 0) { out.push_back(path); return; }           // exact sum reached
    for (int i = start; i < static_cast<int>(c.size()); ++i) {
        if (c[i] > remain) break;                                // sorted: rest too big
        if (!reuse && i > start && c[i] == c[i - 1]) continue;   // skip duplicate choice
        path.push_back(c[i]);
        go(c, reuse ? i : i + 1, remain - c[i], reuse, path, out);
        path.pop_back();
    }
}

VVI combinationSum(std::vector<int> c, int target, bool reuse) {
    std::sort(c.begin(), c.end());
    VVI out; std::vector<int> path;
    go(c, 0, target, reuse, path, out);
    return out;
}

int main() {
    assert((combinationSum({2, 3, 6, 7}, 7, true) == VVI{{2, 2, 3}, {7}}));
    assert((combinationSum({2, 3, 5}, 8, true) == VVI{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}));
    assert((combinationSum({10, 1, 2, 7, 6, 1, 5}, 8, false) == VVI{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}));
    std::cout << "combination_sum: all tests passed\n";
    return 0;
}
