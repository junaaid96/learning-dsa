// Bit tricks: single number (XOR), counting bits, power of two, missing number.
//
// Links: https://leetcode.com/problems/single-number/
//        https://leetcode.com/problems/counting-bits/
//        https://leetcode.com/problems/missing-number/
//        https://leetcode.com/problems/number-of-1-bits/
//        https://leetcode.com/problems/single-number-iii/
//
// Idea:
//   x ^ x = 0 and x ^ 0 = x  -> pairs cancel.
//   x & (x - 1) clears the lowest set bit; x & -x isolates it.
//   bits[i] = bits[i >> 1] + (i & 1).
//
// Time: O(n)    Space: O(1) (O(n) for counting bits output)
//
// Compile: g++ -std=c++17 -Wall -Wextra bit_tricks_single_number.cpp -o bits && ./bits

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

int singleNumber(const std::vector<int>& a) {
    int x = 0;
    for (int v : a) x ^= v;                         // every pair cancels
    return x;
}

std::pair<int, int> singleNumberIII(const std::vector<int>& a) {   // two uniques
    long long x = 0;
    for (int v : a) x ^= v;                         // x = p ^ q (non-zero)
    long long low = x & -x;                         // a bit where p and q differ
    int p = 0, q = 0;
    for (int v : a) (v & low ? p : q) ^= v;         // split into two groups
    return p < q ? std::make_pair(p, q) : std::make_pair(q, p);
}

std::vector<int> countBits(int n) {
    std::vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; ++i) b[i] = b[i >> 1] + (i & 1);   // drop last bit, add it back
    return b;
}

int popcount(unsigned x) { int c = 0; while (x) { x &= x - 1; ++c; } return c; }   // Kernighan
bool isPowerOfTwo(long long n) { return n > 0 && (n & (n - 1)) == 0; }

int missingNumber(const std::vector<int>& a) {
    int x = static_cast<int>(a.size());
    for (int i = 0; i < static_cast<int>(a.size()); ++i) x ^= i ^ a[i];   // 0..n xor all values
    return x;
}

int main() {
    assert(singleNumber({4, 1, 2, 1, 2}) == 4);
    assert(singleNumberIII({1, 2, 1, 3, 2, 5}) == std::make_pair(3, 5));
    assert((countBits(5) == std::vector<int>{0, 1, 1, 2, 1, 2}));
    assert(popcount(11u) == 3 && __builtin_popcount(11u) == 3);
    assert(isPowerOfTwo(16) && !isPowerOfTwo(6) && !isPowerOfTwo(0));
    assert(missingNumber({3, 0, 1}) == 2 && missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}) == 8);
    std::cout << "bit_tricks_single_number: all tests passed\n";
    return 0;
}
