// Modular arithmetic: fast power, inverse (Fermat), nCr mod p with factorials.
//
// Links: https://cses.fi/problemset/task/1095  (Exponentiation)
//        https://cses.fi/problemset/task/1712  (Exponentiation II)
//        https://cses.fi/problemset/task/1079  (Binomial Coefficients)
//        https://leetcode.com/problems/powx-n/
//
// Idea:
//   a^b: square-and-multiply over the bits of b.
//   p prime -> a^(p-2) is the inverse of a (Fermat's little theorem).
//   Precompute fact[] and invFact[] once, then C(n, r) in O(1).
//   a^(b^c) mod p: reduce the exponent mod (p - 1) (Fermat again).
//
// Time: O(log b) per power, O(N) precompute    Space: O(N)
//
// Compile: g++ -std=c++17 -Wall -Wextra modpow_modinv_ncr.cpp -o mod && ./mod

#include <cassert>
#include <iostream>
#include <vector>

const long long MOD = 1'000'000'007LL;

long long power(long long a, long long b, long long m = MOD) {
    long long res = 1 % m;
    a %= m;
    if (a < 0) a += m;
    while (b > 0) {
        if (b & 1) res = res * a % m;     // this bit is set -> multiply in
        a = a * a % m;                     // a^(2^k)
        b >>= 1;
    }
    return res;
}

long long inverse(long long a) { return power(a, MOD - 2); }   // only for prime MOD

struct Comb {
    std::vector<long long> f, inv;
    explicit Comb(int n) : f(n + 1, 1), inv(n + 1, 1) {
        for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * i % MOD;
        inv[n] = inverse(f[n]);
        for (int i = n; i > 0; --i) inv[i - 1] = inv[i] * i % MOD;   // 1/(i-1)! = i/i!
    }
    long long C(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return f[n] * inv[r] % MOD * inv[n - r] % MOD;
    }
};

int main() {
    assert(power(3, 4) == 81 && power(2, 8) == 256 && power(123, 0) == 1);
    assert(inverse(2) * 2 % MOD == 1);
    // CSES 1712 sample: 3^(7^1) = 2187 ; 15^(2^2) = 50625 ; 3^(4^5) mod p = 763327764
    assert(power(3, power(7, 1, MOD - 1)) == 2187);
    assert(power(15, power(2, 2, MOD - 1)) == 50625);
    assert(power(3, power(4, 5, MOD - 1)) == 763327764);
    Comb c(100);
    assert(c.C(5, 3) == 10 && c.C(8, 1) == 8 && c.C(9, 5) == 126 && c.C(3, 5) == 0);   // CSES 1079 sample
    std::cout << "modpow_modinv_ncr: all tests passed\n";
    return 0;
}
