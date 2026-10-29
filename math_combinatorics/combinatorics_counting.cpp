// Counting: Pascal's triangle, Catalan numbers, stars and bars, derangements.
//
// Links: https://leetcode.com/problems/pascals-triangle/
//        https://leetcode.com/problems/unique-binary-search-trees/   (Catalan)
//        https://cses.fi/problemset/task/2064  (Bracket Sequences I, Catalan)
//        https://cses.fi/problemset/task/1716  (Distributing Apples, stars and bars)
//        https://cses.fi/problemset/task/1717  (Christmas Party, derangements)
//
// Idea:
//   C(n, k) = C(n-1, k-1) + C(n-1, k).
//   Catalan(n) = C(2n, n) / (n + 1): balanced brackets, BST shapes, ...
//   Distribute m identical items into n boxes: C(n + m - 1, m).
//   Derangements D(n) = (n - 1) * (D(n-1) + D(n-2)).
//
// Time: O(n^2) Pascal, O(n) others    Space: O(n^2) / O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra combinatorics_counting.cpp -o comb && ./comb

#include <cassert>
#include <iostream>
#include <vector>

const long long MOD = 1'000'000'007LL;

std::vector<std::vector<long long>> pascal(int n) {
    std::vector<std::vector<long long>> C(n + 1);
    for (int i = 0; i <= n; ++i) {
        C[i].assign(i + 1, 1);                            // edges are 1
        for (int k = 1; k < i; ++k) C[i][k] = (C[i - 1][k - 1] + C[i - 1][k]) % MOD;
    }
    return C;
}

long long catalan(int n) {                                // DP: C_{i+1} = sum C_j C_{i-j}
    std::vector<long long> c(n + 1, 0);
    c[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j) c[i] = (c[i] + c[j] * c[i - 1 - j]) % MOD;   // split by root
    return c[n];
}

long long derangements(int n) {
    if (n == 1) return 0;
    long long a = 1, b = 0;                               // D(0) = 1, D(1) = 0
    for (int i = 2; i <= n; ++i) { long long c = (i - 1) * (a + b) % MOD; a = b; b = c; }
    return b;
}

int main() {
    auto C = pascal(10);
    assert(C[4][2] == 6 && C[10][3] == 120);
    assert(catalan(3) == 5 && catalan(19) == 1767263190LL % MOD);
    assert(C[3 + 2 - 1][2] == 6);                         // CSES 1716: n = 3 kids, m = 2 apples
    assert(derangements(4) == 9 && derangements(3) == 2); // CSES 1717
    std::cout << "combinatorics_counting: all tests passed\n";
    return 0;
}
