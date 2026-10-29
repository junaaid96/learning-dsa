// Fenwick Tree (Binary Indexed Tree): point update + prefix sum.
//
// Problem (Dynamic Range Sum Queries):
//   Update x[k] = u, and query sum x[a..b], many times.
// Links: https://cses.fi/problemset/task/1648
//        https://leetcode.com/problems/range-sum-query-mutable/
//
// Idea:
//   tree[i] stores the sum of the block (i - lowbit(i), i], where
//   lowbit(i) = i & -i. Prefix query walks i -= lowbit(i); update walks
//   i += lowbit(i). Both touch O(log n) nodes. 1-indexed!
//
// Time: O(log n) per op    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra fenwick_tree_bit.cpp -o bit && ./bit

#include <cassert>
#include <iostream>
#include <vector>

struct Fenwick {
    int n;
    std::vector<long long> t;
    explicit Fenwick(int n) : n(n), t(n + 1, 0) {}
    void add(int i, long long delta) {                 // x[i] += delta  (1-indexed)
        for (; i <= n; i += i & -i) t[i] += delta;     // climb to every covering block
    }
    long long prefix(int i) const {                    // x[1] + ... + x[i]
        long long s = 0;
        for (; i > 0; i -= i & -i) s += t[i];          // drop the lowest set bit each step
        return s;
    }
    long long range(int l, int r) const { return prefix(r) - prefix(l - 1); }
};

int main() {
    std::vector<int> x{3, 2, 4, 5, 1, 1, 5, 3};         // CSES sample array
    Fenwick fw(static_cast<int>(x.size()));
    for (int i = 0; i < static_cast<int>(x.size()); ++i) fw.add(i + 1, x[i]);
    assert(fw.range(2, 5) == 12);
    fw.add(4, 3 - x[3]); x[3] = 3;                      // set x[4] = 3 (add the difference)
    assert(fw.range(2, 5) == 10);
    assert(fw.range(1, 8) == 22);
    std::cout << "fenwick_tree_bit: all tests passed\n";
    return 0;
}
