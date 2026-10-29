// Bitmask subset enumeration, submask iteration, max AND/OR/XOR patterns.
//
// Links: https://leetcode.com/problems/subsets/
//        https://cses.fi/problemset/task/1623  (Apple Division)
//        https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
//        https://codeforces.com/problemset/problem/1097/B  (Petr and a Combination Lock)
//
// Idea:
//   mask from 0 to 2^n - 1 lists every subset; bit i says "take item i".
//   for (s = m; s; s = (s - 1) & m) visits every non-empty submask of m;
//   over all m that totals 3^n.
//
// Time: O(2^n * n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra subset_enumeration_bitmask.cpp -o masks && ./masks

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

long long appleDivision(const std::vector<long long>& p) {
    const int n = static_cast<int>(p.size());
    long long total = 0, best = LLONG_MAX;
    for (long long x : p) total += x;
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long s = 0;
        for (int i = 0; i < n; ++i) if (mask >> i & 1) s += p[i];   // group A
        best = std::min(best, std::llabs(total - 2 * s));            // |A - B|
    }
    return best;
}

int countMaxOrSubsets(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    int target = 0, cnt = 0;
    for (int x : a) target |= x;                  // OR of everything is the max
    for (int mask = 1; mask < (1 << n); ++mask) {
        int o = 0;
        for (int i = 0; i < n; ++i) if (mask >> i & 1) o |= a[i];
        cnt += (o == target);
    }
    return cnt;
}

int countSubmasks(int m) {
    int c = 0;
    for (int s = m; s; s = (s - 1) & m) ++c;      // all non-empty submasks
    return c + 1;                                 // + the empty one
}

int main() {
    assert(appleDivision({3, 2, 7, 4, 1}) == 1);  // CSES 1623 sample
    assert(countMaxOrSubsets({3, 1}) == 2 && countMaxOrSubsets({2, 2, 2}) == 7);
    assert(countSubmasks(0b1011) == 8);           // 2^popcount
    std::cout << "subset_enumeration_bitmask: all tests passed\n";
    return 0;
}
