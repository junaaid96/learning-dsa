// Math basics: digit sums, palindrome number, sum formulas, ceil division, sqrt.
//
// Links: https://leetcode.com/problems/palindrome-number/
//        https://leetcode.com/problems/sqrtx/
//        https://cses.fi/problemset/task/1083  (Missing Number)
//        https://codeforces.com/problemset/problem/1/A  (Theatre Square)
//
// Idea:
//   x % 10 = last digit, x / 10 drops it. 1 + ... + n = n(n+1)/2.
//   ceil(a / b) = (a + b - 1) / b for positive ints.
//   Integer sqrt via binary search avoids floating-point error.
//
// Time: O(digits) / O(log x)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra math_basics_digits_series.cpp -o mb && ./mb

#include <cassert>
#include <iostream>
#include <vector>

int digitSum(long long x) { int s = 0; while (x > 0) { s += static_cast<int>(x % 10); x /= 10; } return s; }

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int rev = 0;
    while (x > rev) { rev = rev * 10 + x % 10; x /= 10; }   // reverse only half
    return x == rev || x == rev / 10;                       // even or odd length
}

long long ceilDiv(long long a, long long b) { return (a + b - 1) / b; }

long long theatreSquare(long long n, long long m, long long a) { return ceilDiv(n, a) * ceilDiv(m, a); }

long long missingNumber(long long n, const std::vector<long long>& v) {
    long long s = n * (n + 1) / 2;                          // expected sum
    for (long long x : v) s -= x;
    return s;
}

int isqrt(long long x) {                                     // largest r with r*r <= x
    long long lo = 0, hi = 2'000'000'000LL;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (mid * mid <= x) lo = mid; else hi = mid - 1;
    }
    return static_cast<int>(lo);
}

int main() {
    assert(digitSum(9875) == 29);
    assert(isPalindrome(121) && !isPalindrome(-121) && !isPalindrome(10) && isPalindrome(0));
    assert(theatreSquare(6, 6, 4) == 4);
    assert(missingNumber(5, {2, 3, 1, 5}) == 4);
    assert(isqrt(8) == 2 && isqrt(16) == 4 && isqrt(2147395599) == 46339);
    std::cout << "math_basics_digits_series: all tests passed\n";
    return 0;
}
