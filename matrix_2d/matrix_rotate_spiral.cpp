// Matrix manipulation: rotate 90 degrees in place, spiral order, set zeroes, search 2D.
//
// Links: https://leetcode.com/problems/rotate-image/
//        https://leetcode.com/problems/spiral-matrix/
//        https://leetcode.com/problems/set-matrix-zeroes/
//        https://leetcode.com/problems/search-a-2d-matrix-ii/
//
// Idea:
//   Rotate clockwise = transpose + reverse each row.
//   Spiral: shrink four boundaries (top, bottom, left, right) after each side.
//   Set zeroes: use the first row/column as marker storage for O(1) space.
//   Sorted rows+cols: start at top-right; go left if too big, down if too small.
//
// Time: O(R*C) ; search O(R + C)    Space: O(1) extra
//
// Compile: g++ -std=c++17 -Wall -Wextra matrix_rotate_spiral.cpp -o mat && ./mat

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using Mat = std::vector<std::vector<int>>;

void rotate(Mat& m) {
    const int n = static_cast<int>(m.size());
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) std::swap(m[i][j], m[j][i]);   // transpose
    for (auto& row : m) std::reverse(row.begin(), row.end());          // mirror
}

std::vector<int> spiral(const Mat& m) {
    std::vector<int> out;
    int top = 0, bot = static_cast<int>(m.size()) - 1, left = 0, right = static_cast<int>(m[0].size()) - 1;
    while (top <= bot && left <= right) {
        for (int j = left; j <= right; ++j) out.push_back(m[top][j]);
        ++top;
        for (int i = top; i <= bot; ++i) out.push_back(m[i][right]);
        --right;
        if (top <= bot) { for (int j = right; j >= left; --j) out.push_back(m[bot][j]); --bot; }
        if (left <= right) { for (int i = bot; i >= top; --i) out.push_back(m[i][left]); ++left; }
    }
    return out;
}

void setZeroes(Mat& m) {
    const int R = static_cast<int>(m.size()), C = static_cast<int>(m[0].size());
    bool firstCol = false;                          // m[0][0] marks row 0; this flag marks col 0
    for (int i = 0; i < R; ++i) {
        if (m[i][0] == 0) firstCol = true;
        for (int j = 1; j < C; ++j) if (m[i][j] == 0) m[i][0] = m[0][j] = 0;   // markers
    }
    for (int i = R - 1; i >= 0; --i) {              // bottom-up so row 0 markers survive
        for (int j = C - 1; j >= 1; --j) if (m[i][0] == 0 || m[0][j] == 0) m[i][j] = 0;
        if (firstCol) m[i][0] = 0;
    }
}

bool searchMatrix(const Mat& m, int target) {
    int r = 0, c = static_cast<int>(m[0].size()) - 1;
    while (r < static_cast<int>(m.size()) && c >= 0) {
        if (m[r][c] == target) return true;
        if (m[r][c] > target) --c; else ++r;        // drop a column or a row each step
    }
    return false;
}

int main() {
    Mat a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(a);
    assert((a == Mat{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}));
    assert((spiral({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}) == std::vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));
    Mat z{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(z);
    assert((z == Mat{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}));
    Mat s{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    assert(searchMatrix(s, 5) && !searchMatrix(s, 20));
    std::cout << "matrix_rotate_spiral: all tests passed\n";
    return 0;
}
