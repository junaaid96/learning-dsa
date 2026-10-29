// Subsets II (with duplicates) and Word Search (grid backtracking).
//
// Problems:
//   (1) All unique subsets of an array that may contain duplicates.
//       Link: https://leetcode.com/problems/subsets-ii/
//   (2) Does a word exist in a letter grid via adjacent cells (no reuse)?
//       Link: https://leetcode.com/problems/word-search/
//
// Idea:
//   (1) Every node of the recursion tree is a subset; record it on entry.
//   (2) DFS from each cell, temporarily mark the cell as used ('#'), and
//       restore it when returning.
//
// Time: (1) O(n * 2^n)  (2) O(R*C*4^L)    Space: O(n) / O(L)
//
// Compile: g++ -std=c++17 -Wall -Wextra subsets_and_word_search.cpp -o sws && ./sws

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void subs(const std::vector<int>& a, int start, std::vector<int>& path,
          std::vector<std::vector<int>>& out) {
    out.push_back(path);                                       // current subset
    for (int i = start; i < static_cast<int>(a.size()); ++i) {
        if (i > start && a[i] == a[i - 1]) continue;           // same value at same depth
        path.push_back(a[i]);
        subs(a, i + 1, path, out);
        path.pop_back();
    }
}

bool dfs(std::vector<std::string>& g, const std::string& w, int r, int c, int k) {
    if (k == static_cast<int>(w.size())) return true;          // matched every letter
    if (r < 0 || c < 0 || r >= static_cast<int>(g.size()) || c >= static_cast<int>(g[0].size())) return false;
    if (g[r][c] != w[k]) return false;                         // wrong letter / used ('#')
    const char saved = g[r][c];
    g[r][c] = '#';                                             // mark as used
    bool found = dfs(g, w, r + 1, c, k + 1) || dfs(g, w, r - 1, c, k + 1) ||
                 dfs(g, w, r, c + 1, k + 1) || dfs(g, w, r, c - 1, k + 1);
    g[r][c] = saved;                                           // restore
    return found;
}

bool exist(std::vector<std::string> g, const std::string& w) {
    for (int r = 0; r < static_cast<int>(g.size()); ++r)
        for (int c = 0; c < static_cast<int>(g[0].size()); ++c)
            if (dfs(g, w, r, c, 0)) return true;
    return false;
}

int main() {
    std::vector<int> a{1, 2, 2};
    std::sort(a.begin(), a.end());
    std::vector<int> path; std::vector<std::vector<int>> out;
    subs(a, 0, path, out);
    assert(out.size() == 6);                                   // [],[1],[1,2],[1,2,2],[2],[2,2]
    std::vector<std::string> board{"ABCE", "SFCS", "ADEE"};
    assert(exist(board, "ABCCED"));
    assert(exist(board, "SEE"));
    assert(!exist(board, "ABCB"));
    std::cout << "subsets_and_word_search: all tests passed\n";
    return 0;
}
