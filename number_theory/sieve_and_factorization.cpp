// Sieve of Eratosthenes, smallest-prime-factor sieve, trial-division factorization.
//
// Links: https://leetcode.com/problems/count-primes/
//        https://cses.fi/problemset/task/1713  (Counting Divisors)
//        https://codeforces.com/problemset/problem/26/A  (Almost Prime)
//
// Idea:
//   Sieve: for each prime p, cross out p*p, p*p+p, ... (smaller multiples are
//   already crossed). SPF sieve stores the smallest prime factor so any x <= N
//   factorises in O(log x). Trial division up to sqrt(x) handles single big x.
//   #divisors = product of (exponent + 1).
//
// Time: O(N log log N) sieve, O(sqrt x) trial division    Space: O(N)
//
// Compile: g++ -std=c++17 -Wall -Wextra sieve_and_factorization.cpp -o sieve && ./sieve

#include <cassert>
#include <iostream>
#include <map>
#include <vector>

std::vector<bool> sieve(int n) {                    // isPrime[0..n]
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (long long p = 2; p * p <= n; ++p)
        if (isPrime[p])
            for (long long q = p * p; q <= n; q += p) isPrime[q] = false;
    return isPrime;
}

std::vector<int> spfSieve(int n) {
    std::vector<int> spf(n + 1, 0);
    for (int i = 2; i <= n; ++i)
        if (spf[i] == 0)                            // i is prime
            for (int j = i; j <= n; j += i) if (spf[j] == 0) spf[j] = i;
    return spf;
}

std::map<long long, int> factorize(long long x) {   // trial division
    std::map<long long, int> f;
    for (long long p = 2; p * p <= x; ++p)
        while (x % p == 0) { ++f[p]; x /= p; }
    if (x > 1) ++f[x];                              // leftover prime > sqrt
    return f;
}

int countDivisors(int x, const std::vector<int>& spf) {
    int res = 1;
    while (x > 1) {
        int p = spf[x], e = 0;
        while (x % p == 0) { x /= p; ++e; }
        res *= e + 1;
    }
    return res;
}

int main() {
    auto pr = sieve(10);
    int cnt = 0;
    for (int i = 0; i < 10; ++i) cnt += pr[i];
    assert(cnt == 4);                               // LeetCode 204: n = 10 -> 4
    auto spf = spfSieve(100);
    assert(countDivisors(16, spf) == 5 && countDivisors(17, spf) == 2 && countDivisors(18, spf) == 6);
    auto f = factorize(360);                        // 2^3 * 3^2 * 5
    assert(f[2] == 3 && f[3] == 2 && f[5] == 1 && f.size() == 3);
    // CF 26A: numbers in [1, 10] with exactly two distinct prime factors -> 6, 10
    int almost = 0;
    for (int i = 1; i <= 10; ++i) almost += factorize(i).size() == 2;
    assert(almost == 2);
    std::cout << "sieve_and_factorization: all tests passed\n";
    return 0;
}
