// Range Sum Query 2D - Immutable (2D prefix sums).
//
// Problem:
//   Answer many queries "sum of the sub-rectangle (r1,c1)..(r2,c2)".
// Link: https://leetcode.com/problems/range-sum-query-2d-immutable/
//
// Idea:
//   P[i][j] = sum of the rectangle (0,0)..(i-1,j-1) (1-indexed padding).
//   Build: P[i][j] = a + P[i-1][j] + P[i][j-1] - P[i-1][j-1].
//   Query by inclusion-exclusion of four corners.
//
// Time: O(R*C) build, O(1) per query    Space: O(R*C)
//
// Compile: g++ -std=c++17 -Wall -Wextra range_sum_2d.cpp -o rs2d && ./rs2d

#include <cassert>
#include <iostream>
#include <vector>

struct NumMatrix {
    std::vector<std::vector<long long>> P;       // padded prefix table
    explicit NumMatrix(const std::vector<std::vector<int>>& m) {
        const int R = static_cast<int>(m.size()), C = R ? static_cast<int>(m[0].size()) : 0;
        P.assign(R + 1, std::vector<long long>(C + 1, 0));   // row/col 0 are zeros
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j)
                P[i][j] = m[i - 1][j - 1] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }
    long long sumRegion(int r1, int c1, int r2, int c2) const {
        // big rectangle minus top strip minus left strip plus the doubly removed corner
        return P[r2 + 1][c2 + 1] - P[r1][c2 + 1] - P[r2 + 1][c1] + P[r1][c1];
    }
};

int main() {
    NumMatrix nm({{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}});
    assert(nm.sumRegion(2, 1, 4, 3) == 8);
    assert(nm.sumRegion(1, 1, 2, 2) == 11);
    assert(nm.sumRegion(1, 2, 2, 4) == 12);
    std::cout << "range_sum_2d: all tests passed\n";
    return 0;
}
