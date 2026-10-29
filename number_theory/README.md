# Number Theory

[← back to roadmap](../README.md)

## What it is

Primes, divisibility, modular arithmetic: sieve, factorisation, gcd/lcm, fast power, modular inverse, nCr.

## When to use it

- Answers "modulo 1e9+7"
- Divisors / primes / coprimality
- Combinatorics with large n

## Intuition

Work modulo a prime p: multiply freely, and divide by multiplying with a^(p-2) (Fermat).

## Common patterns

- Sieve of Eratosthenes / smallest prime factor
- Binary exponentiation
- Factorial + inverse factorial tables
- Extended Euclid for ax+by=g

## Template

```cpp
long long power(long long b, long long e, long long m) {
    long long r = 1; b %= m;
    while (e) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; }
    return r;
}
```

## Pitfalls

- Overflow before % (cast to long long / __int128)
- Negative mod: ((x % m) + m) % m
- Inverse only exists when gcd(a, m) = 1

## Complexity

Sieve O(n log log n); modpow O(log e); gcd O(log min).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`gcd_lcm_extended_euclid.cpp`](gcd_lcm_extended_euclid.cpp) | GCD, LCM, extended Euclid (solve a*x + b*y = gcd) and divisor enumeration. | [link](https://leetcode.com/problems/find-greatest-common-divisor-of-array/) |
| [`modpow_modinv_ncr.cpp`](modpow_modinv_ncr.cpp) | Modular arithmetic: fast power, inverse (Fermat), nCr mod p with factorials. | [link](https://cses.fi/problemset/task/1095) |
| [`sieve_and_factorization.cpp`](sieve_and_factorization.cpp) | Sieve of Eratosthenes, smallest-prime-factor sieve, trial-division factorization. | [link](https://leetcode.com/problems/count-primes/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh number_theory` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Count Primes](https://leetcode.com/problems/count-primes/)
- [ ] [Find Greatest Common Divisor Of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)

**Medium**

- [ ] [CSES 1095 – Exponentiation](https://cses.fi/problemset/task/1095)
- [ ] [CSES 1713 – Counting Divisors](https://cses.fi/problemset/task/1713)
- [ ] [CF 1742D – Coprime](https://codeforces.com/problemset/problem/1742/D)

**Hard**

- [ ] [CSES 1079 – Binomial Coefficients](https://cses.fi/problemset/task/1079)
- [ ] [CSES 1712 – Exponentiation II](https://cses.fi/problemset/task/1712)
- [ ] [CSES 1081 – Common Divisors](https://cses.fi/problemset/task/1081)
