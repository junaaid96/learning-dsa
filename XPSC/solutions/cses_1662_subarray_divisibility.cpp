// XPSC Week 16 Day 02 - CSES 1662 Subarray Divisibility
// Link: https://cses.fi/problemset/task/1662
//
// Problem: count subarrays whose sum is divisible by n.
// Idea:    two prefixes with the same remainder mod n bound such a subarray.
//          Normalise negatives: ((p % n) + n) % n.
// Time: O(n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1662_subarray_divisibility.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

long long divisibleSubarrays(const std::vector<long long>& a) {
    const long long n = static_cast<long long>(a.size());
    std::vector<long long> cnt(n, 0);
    cnt[0] = 1;                                           // empty prefix
    long long pre = 0, ans = 0;
    for (long long x : a) {
        pre = ((pre + x) % n + n) % n;
        ans += cnt[pre]++;                                // pair with earlier equal remainders
    }
    return ans;
}

int main() {
    assert(divisibleSubarrays({3, 1, 2, 7, 4}) == 1);
    assert(divisibleSubarrays({-1, 1}) == 1 + 0 + 0 + 0 + 0);   // only [-1, 1]
    std::cout << "cses_1662_subarray_divisibility: all tests passed\n";
    return 0;
}
