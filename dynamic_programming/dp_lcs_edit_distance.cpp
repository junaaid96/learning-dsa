// 2D string DP: Longest Common Subsequence and Edit Distance.
//
// Problems:
//   (1) Length of the longest common subsequence of a and b.
//       Link: https://leetcode.com/problems/longest-common-subsequence/
//   (2) Minimum insert/delete/replace operations to turn a into b.
//       Links: https://leetcode.com/problems/edit-distance/  https://cses.fi/problemset/task/1639
//
// Idea:
//   dp[i][j] = answer for prefixes a[0..i) and b[0..j).
//   LCS:  equal last chars -> dp[i-1][j-1] + 1, else max(dp[i-1][j], dp[i][j-1]).
//   Edit: equal -> dp[i-1][j-1]; else 1 + min(delete dp[i-1][j],
//         insert dp[i][j-1], replace dp[i-1][j-1]).
//
// Time: O(n*m)    Space: O(n*m) (can be reduced to O(m) with two rows)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_lcs_edit_distance.cpp -o lcs && ./lcs

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int lcs(const std::string& a, const std::string& b) {
    const int n = static_cast<int>(a.size()), m = static_cast<int>(b.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));  // empty prefix -> 0
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] + 1
                                              : std::max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}

int editDistance(const std::string& a, const std::string& b) {
    const int n = static_cast<int>(a.size()), m = static_cast<int>(b.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) dp[i][0] = i;        // delete all i chars
    for (int j = 0; j <= m; ++j) dp[0][j] = j;        // insert all j chars
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1])
                ? dp[i - 1][j - 1]                                        // nothing to do
                : 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    return dp[n][m];
}

int main() {
    assert(lcs("abcde", "ace") == 3);
    assert(lcs("abc", "def") == 0);
    assert(editDistance("horse", "ros") == 3);
    assert(editDistance("intention", "execution") == 5);
    assert(editDistance("LOVE", "MOVIE") == 2);    // CSES sample
    std::cout << "dp_lcs_edit_distance: all tests passed\n";
    return 0;
}
