// Permutations (backtracking with a "used" array) + unique permutations.
//
// Problems:
//   All permutations of distinct numbers / of numbers with duplicates.
// Links: https://leetcode.com/problems/permutations/
//        https://leetcode.com/problems/permutations-ii/
//
// Idea:
//   Build the permutation position by position. Choose any unused element,
//   recurse, then UNDO the choice (the "back" in backtracking).
//   For duplicates: sort, and skip a[i] if it equals a[i-1] and a[i-1] is
//   not used in the current path (that branch was already explored).
//
// Time: O(n * n!)    Space: O(n) recursion
//
// Compile: g++ -std=c++17 -Wall -Wextra permutations.cpp -o perm && ./perm

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void dfs(const std::vector<int>& a, std::vector<bool>& used, std::vector<int>& path,
         std::vector<std::vector<int>>& out) {
    if (path.size() == a.size()) { out.push_back(path); return; }   // full permutation
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (used[i]) continue;                                     // already in path
        if (i > 0 && a[i] == a[i - 1] && !used[i - 1]) continue;   // duplicate branch
        used[i] = true; path.push_back(a[i]);                      // choose
        dfs(a, used, path, out);                                   // explore
        path.pop_back(); used[i] = false;                          // un-choose
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> a) {
    std::sort(a.begin(), a.end());                // equal values become neighbours
    std::vector<bool> used(a.size(), false);
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    dfs(a, used, path, out);
    return out;
}

int main() {
    assert(permuteUnique({1, 2, 3}).size() == 6);
    assert((permuteUnique({1, 1, 2}) == std::vector<std::vector<int>>{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}}));
    // std::next_permutation gives the same result in lexicographic order
    std::vector<int> v{1, 2, 3}; int cnt = 0;
    do { ++cnt; } while (std::next_permutation(v.begin(), v.end()));
    assert(cnt == 6);
    std::cout << "permutations: all tests passed\n";
    return 0;
}
