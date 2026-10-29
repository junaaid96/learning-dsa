// Segment Tree: point update + range minimum query (and a lazy range-add sum tree).
//
// Problems:
//   (1) Dynamic Range Minimum Queries.  Link: https://cses.fi/problemset/task/1649
//   (2) Range Update Queries (add on a range, query a sum).
//       Link: https://cses.fi/problemset/task/1651
//
// Idea:
//   Node `v` covers [l, r]; children cover the two halves. A query splits
//   into O(log n) fully covered nodes. Lazy propagation stores pending
//   "add to whole node" values and pushes them down only when needed.
//
// Time: O(log n) per op    Space: O(4n)
//
// Compile: g++ -std=c++17 -Wall -Wextra segment_tree.cpp -o seg && ./seg

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

struct MinSegTree {
    int n;
    std::vector<int> t;
    explicit MinSegTree(const std::vector<int>& a) : n(static_cast<int>(a.size())), t(4 * a.size(), INT_MAX) {
        build(a, 1, 0, n - 1);
    }
    void build(const std::vector<int>& a, int v, int l, int r) {
        if (l == r) { t[v] = a[l]; return; }                 // leaf
        int m = (l + r) / 2;
        build(a, 2 * v, l, m); build(a, 2 * v + 1, m + 1, r);
        t[v] = std::min(t[2 * v], t[2 * v + 1]);             // combine children
    }
    void update(int pos, int val, int v, int l, int r) {
        if (l == r) { t[v] = val; return; }
        int m = (l + r) / 2;
        if (pos <= m) update(pos, val, 2 * v, l, m); else update(pos, val, 2 * v + 1, m + 1, r);
        t[v] = std::min(t[2 * v], t[2 * v + 1]);
    }
    int query(int ql, int qr, int v, int l, int r) const {
        if (qr < l || r < ql) return INT_MAX;                // no overlap: neutral value
        if (ql <= l && r <= qr) return t[v];                 // full overlap
        int m = (l + r) / 2;                                 // partial: ask both children
        return std::min(query(ql, qr, 2 * v, l, m), query(ql, qr, 2 * v + 1, m + 1, r));
    }
    void update(int pos, int val) { update(pos, val, 1, 0, n - 1); }
    int query(int l, int r) const { return query(l, r, 1, 0, n - 1); }
};

struct LazySumTree {
    int n;
    std::vector<long long> sum, lazy;
    explicit LazySumTree(int n) : n(n), sum(4 * n, 0), lazy(4 * n, 0) {}
    void apply(int v, int l, int r, long long add) { sum[v] += add * (r - l + 1); lazy[v] += add; }
    void push(int v, int l, int r) {                         // hand pending adds to children
        if (!lazy[v]) return;
        int m = (l + r) / 2;
        apply(2 * v, l, m, lazy[v]); apply(2 * v + 1, m + 1, r, lazy[v]);
        lazy[v] = 0;
    }
    void add(int ql, int qr, long long val, int v, int l, int r) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(v, l, r, val); return; }
        push(v, l, r);
        int m = (l + r) / 2;
        add(ql, qr, val, 2 * v, l, m); add(ql, qr, val, 2 * v + 1, m + 1, r);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }
    long long query(int ql, int qr, int v, int l, int r) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return sum[v];
        push(v, l, r);
        int m = (l + r) / 2;
        return query(ql, qr, 2 * v, l, m) + query(ql, qr, 2 * v + 1, m + 1, r);
    }
    void add(int l, int r, long long v) { add(l, r, v, 1, 0, n - 1); }
    long long query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};

int main() {
    MinSegTree st({3, 2, 4, 5, 1, 1, 5, 3});
    assert(st.query(1, 3) == 2);
    assert(st.query(0, 7) == 1);
    st.update(4, 9); st.update(5, 9);
    assert(st.query(3, 6) == 5);
    LazySumTree lz(5);
    lz.add(0, 4, 1);                    // [1,1,1,1,1]
    lz.add(1, 3, 2);                    // [1,3,3,3,1]
    assert(lz.query(0, 4) == 11);
    assert(lz.query(2, 2) == 3);
    std::cout << "segment_tree: all tests passed\n";
    return 0;
}
