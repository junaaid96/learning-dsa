// Matrix exponentiation: n-th Fibonacci in O(log n) and counting paths of length k.
//
// Links: https://cses.fi/problemset/task/1722  (Fibonacci Numbers)
//        https://cses.fi/problemset/task/1723  (Graph Paths I)
//        https://leetcode.com/problems/fibonacci-number/
//
// Idea:
//   [F(n+1) F(n); F(n) F(n-1)] = [[1,1],[1,0]]^n. Any linear recurrence of
//   order d becomes a d x d matrix power. Adjacency^k counts walks of length k.
//
// Time: O(d^3 log n)    Space: O(d^2)
//
// Compile: g++ -std=c++17 -Wall -Wextra matrix_exponentiation_fibonacci.cpp -o mexp && ./mexp

#include <cassert>
#include <iostream>
#include <vector>

const long long MOD = 1'000'000'007LL;
using M = std::vector<std::vector<long long>>;

M mul(const M& a, const M& b) {
    const size_t n = a.size();
    M c(n, std::vector<long long>(n, 0));
    for (size_t i = 0; i < n; ++i)
        for (size_t k = 0; k < n; ++k) {
            if (!a[i][k]) continue;
            for (size_t j = 0; j < n; ++j) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        }
    return c;
}

M mpow(M a, long long e) {
    const size_t n = a.size();
    M r(n, std::vector<long long>(n, 0));
    for (size_t i = 0; i < n; ++i) r[i][i] = 1;    // identity
    while (e > 0) { if (e & 1) r = mul(r, a); a = mul(a, a); e >>= 1; }
    return r;
}

long long fib(long long n) { return n == 0 ? 0 : mpow({{1, 1}, {1, 0}}, n)[0][1]; }

int main() {
    assert(fib(0) == 0 && fib(1) == 1 && fib(10) == 55);
    assert(fib(50) == 12586269025LL % MOD);
    // directed 3-cycle 0 -> 1 -> 2 -> 0: exactly one walk of length 2 from 0 to 2
    M adj{{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    assert(mpow(adj, 2)[0][2] == 1 && mpow(adj, 3)[0][0] == 1 && mpow(adj, 3)[0][1] == 0);
    std::cout << "matrix_exponentiation_fibonacci: all tests passed\n";
    return 0;
}
