// N-Queens (backtracking with column/diagonal markers).
//
// Problem:
//   Count the ways to place n queens on an n x n board so none attack.
// Links: https://leetcode.com/problems/n-queens-ii/
//        https://cses.fi/problemset/task/1624  (with blocked squares)
//
// Idea:
//   Place one queen per row. A square (r, c) is safe if column c, diagonal
//   r - c and anti-diagonal r + c are all free. Mark them, recurse to the
//   next row, unmark.
//
// Time: O(n!) worst case (heavily pruned)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra n_queens.cpp -o nq && ./nq

#include <cassert>
#include <iostream>
#include <vector>

int solve(int r, int n, std::vector<bool>& col, std::vector<bool>& d1, std::vector<bool>& d2) {
    if (r == n) return 1;                                    // all rows filled: one solution
    int ways = 0;
    for (int c = 0; c < n; ++c) {
        if (col[c] || d1[r - c + n - 1] || d2[r + c]) continue;  // attacked square
        col[c] = d1[r - c + n - 1] = d2[r + c] = true;           // place queen
        ways += solve(r + 1, n, col, d1, d2);
        col[c] = d1[r - c + n - 1] = d2[r + c] = false;          // remove queen
    }
    return ways;
}

int totalNQueens(int n) {
    std::vector<bool> col(n), d1(2 * n - 1), d2(2 * n - 1);  // d1 index shifted by n-1
    return solve(0, n, col, d1, d2);
}

int main() {
    assert(totalNQueens(1) == 1);
    assert(totalNQueens(4) == 2);
    assert(totalNQueens(8) == 92);
    std::cout << "n_queens: all tests passed\n";
    return 0;
}
