// GCD, LCM, extended Euclid (solve a*x + b*y = gcd) and divisor enumeration.
//
// Links: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
//        https://codeforces.com/problemset/problem/1458/A  (Row GCD)
//        https://cses.fi/problemset/task/1081  (Common Divisors)
//
// Idea:
//   gcd(a, b) = gcd(b, a % b). lcm = a / gcd * b (divide first: no overflow).
//   gcd(a + x, b + x) = gcd(a + x, b - a) -> Row GCD trick.
//   Extended Euclid carries coefficients back up the recursion.
//
// Time: O(log min(a, b))    Space: O(log) recursion
//
// Compile: g++ -std=c++17 -Wall -Wextra gcd_lcm_extended_euclid.cpp -o gcd && ./gcd

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

long long gcdLL(long long a, long long b) { return b == 0 ? std::llabs(a) : gcdLL(b, a % b); }
long long lcmLL(long long a, long long b) { return a / gcdLL(a, b) * b; }

// returns g = gcd(a, b) and fills x, y with a*x + b*y = g
long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = extGcd(b, a % b, x1, y1);
    x = y1;                                  // from b*x1 + (a % b)*y1 = g
    y = x1 - (a / b) * y1;
    return g;
}

// CF 1458A: answers gcd(a1 + bj, ..., an + bj) for each bj
std::vector<long long> rowGcd(const std::vector<long long>& a, const std::vector<long long>& b) {
    long long g = 0;
    for (size_t i = 1; i < a.size(); ++i) g = gcdLL(g, a[i] - a[0]);   // differences don't change
    std::vector<long long> out;
    for (long long x : b) out.push_back(gcdLL(a[0] + x, g));
    return out;
}

int main() {
    assert(gcdLL(12, 18) == 6 && lcmLL(4, 6) == 12 && std::gcd(0, 5) == 5);
    long long x, y;
    long long g = extGcd(30, 12, x, y);
    assert(g == 6 && 30 * x + 12 * y == 6);
    assert((rowGcd({1, 25, 121, 169}, {1, 2, 7, 23}) == std::vector<long long>{2, 3, 8, 24}));
    std::cout << "gcd_lcm_extended_euclid: all tests passed\n";
    return 0;
}
