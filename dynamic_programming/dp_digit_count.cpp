// Digit DP intro: count numbers in [0, N] whose digit sum equals S.
//
// Problem:
//   Given N and S, count x in [0, N] with digitsum(x) == S. Classic digit DP
//   (see also "Counting Numbers" - no two adjacent equal digits).
// Links: https://cses.fi/problemset/task/2220
//        https://www.geeksforgeeks.org/digit-dp-introduction/
//
// Idea:
//   Build the number digit by digit from the most significant. State:
//   (position, sum so far, tight). `tight` means the prefix equals N's prefix,
//   so the next digit is limited by N's digit; otherwise any 0..9 is allowed.
//   Memoize only the non-tight states (tight states are visited once).
//
// Time: O(digits * S * 10)    Space: O(digits * S)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_digit_count.cpp -o digit && ./digit

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::string D;                                    // digits of N
std::vector<std::vector<long long>> memo;         // memo[pos][sum] for non-tight states
int target;

long long go(int pos, int sum, bool tight) {
    if (sum > target) return 0;                   // overshot: prune
    if (pos == static_cast<int>(D.size())) return sum == target ? 1 : 0;
    if (!tight && memo[pos][sum] != -1) return memo[pos][sum];
    int limit = tight ? D[pos] - '0' : 9;         // highest digit allowed here
    long long res = 0;
    for (int d = 0; d <= limit; ++d)
        res += go(pos + 1, sum + d, tight && d == limit);  // stay tight only on the max digit
    if (!tight) memo[pos][sum] = res;
    return res;
}

long long countDigitSum(long long N, int S) {
    D = std::to_string(N); target = S;
    memo.assign(D.size(), std::vector<long long>(S + 1, -1));
    return go(0, 0, true);
}

long long brute(long long N, int S) {             // checker for small N
    long long c = 0;
    for (long long x = 0; x <= N; ++x) { int s = 0; for (long long y = x; y; y /= 10) s += y % 10; c += (s == S); }
    return c;
}

int main() {
    assert(countDigitSum(100, 1) == 3);           // 1, 10, 100
    for (long long N : {0LL, 9LL, 57LL, 999LL, 4321LL})
        for (int S = 0; S <= 20; ++S) assert(countDigitSum(N, S) == brute(N, S));
    std::cout << "dp_digit_count: all tests passed\n";
    return 0;
}
