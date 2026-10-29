// Z-function: z[i] = longest common prefix of s and s[i..].
//
// Links: https://cses.fi/problemset/task/2107  (Finding Borders)
//        https://cses.fi/problemset/task/1733  (Finding Periods)
//        https://codeforces.com/problemset/problem/126/B  (Password)
//
// Idea:
//   Keep the rightmost window [l, r) that matches a prefix. For i inside it,
//   start from min(r - i, z[i - l]) and extend naively; r only moves right.
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra z_function.cpp -o z && ./z

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> zFunction(const std::string& s) {
    const int n = static_cast<int>(s.size());
    std::vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i < r) z[i] = std::min(r - i, z[i - l]);               // reuse known match
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];     // extend
        if (i + z[i] > r) { l = i; r = i + z[i]; }                 // new rightmost window
    }
    return z;
}

// periods p such that s is a prefix of s repeated with period p (CSES 1733)
std::vector<int> periods(const std::string& s) {
    std::vector<int> z = zFunction(s), out;
    const int n = static_cast<int>(s.size());
    for (int p = 1; p < n; ++p) if (p + z[p] == n) out.push_back(p);   // suffix matches prefix
    out.push_back(n);
    return out;
}

int main() {
    assert((zFunction("aaabaab") == std::vector<int>{0, 2, 1, 0, 2, 1, 0}));
    assert((periods("abcabca") == std::vector<int>{3, 6, 7}));     // CSES 1733 sample
    std::cout << "z_function: all tests passed\n";
    return 0;
}
