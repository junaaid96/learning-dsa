// Sparse Table: O(1) range minimum queries on a static array.
//
// Problem (Static Range Minimum Queries):
//   Answer min(x[a..b]) for many queries; the array never changes.
// Link: https://cses.fi/problemset/task/1647
//
// Idea:
//   sp[j][i] = min of the block of length 2^j starting at i.
//   A query [l, r] is covered by two overlapping blocks of length 2^k where
//   k = floor(log2(r - l + 1)). Overlap is fine because min is idempotent.
//
// Time: O(n log n) build, O(1) query    Space: O(n log n)
//
// Compile: g++ -std=c++17 -Wall -Wextra sparse_table_rmq.cpp -o sp && ./sp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

struct SparseTable {
    std::vector<std::vector<int>> sp;
    std::vector<int> lg;                                   // lg[x] = floor(log2 x)
    explicit SparseTable(const std::vector<int>& a) {
        const int n = static_cast<int>(a.size());
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        sp.assign(lg[n] + 1, a);                           // level 0 = the array itself
        for (int j = 1; j <= lg[n]; ++j)
            for (int i = 0; i + (1 << j) <= n; ++i)
                sp[j][i] = std::min(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);  // two halves
    }
    int query(int l, int r) const {                        // inclusive [l, r]
        int k = lg[r - l + 1];
        return std::min(sp[k][l], sp[k][r - (1 << k) + 1]);
    }
};

int main() {
    SparseTable st({3, 2, 4, 5, 1, 1, 5, 3});
    assert(st.query(1, 3) == 2);
    assert(st.query(4, 7) == 1);
    assert(st.query(6, 7) == 3);
    assert(st.query(2, 2) == 4);
    std::cout << "sparse_table_rmq: all tests passed\n";
    return 0;
}
