// Polynomial rolling hash: O(1) substring comparisons after O(n) precompute.
//
// Links: https://leetcode.com/problems/repeated-dna-sequences/
//        https://leetcode.com/problems/longest-duplicate-substring/
//        https://cses.fi/problemset/task/1753
//
// Idea:
//   h[i] = hash of s[0..i). hash(l, r) = h[r] - h[l] * B^(r-l) (mod M).
//   Use a large prime mod (here 2^61-1 with 128-bit multiply) to make
//   collisions very unlikely. Combine with binary search for "longest" tasks.
//
// Time: O(n) build, O(1) query    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra rolling_hash.cpp -o hash && ./hash

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Hasher {
    static constexpr uint64_t MOD = (1ULL << 61) - 1;
    static constexpr uint64_t B = 131;
    std::vector<uint64_t> h, pw;
    static uint64_t mul(uint64_t a, uint64_t b) {
        __uint128_t c = static_cast<__uint128_t>(a) * b;          // no overflow
        uint64_t lo = static_cast<uint64_t>(c & MOD), hi = static_cast<uint64_t>(c >> 61);
        uint64_t r = lo + hi;                                      // fast mod for 2^61-1
        return r >= MOD ? r - MOD : r;
    }
    explicit Hasher(const std::string& s) : h(s.size() + 1, 0), pw(s.size() + 1, 1) {
        for (size_t i = 0; i < s.size(); ++i) {
            h[i + 1] = (mul(h[i], B) + static_cast<unsigned char>(s[i])) % MOD;
            pw[i + 1] = mul(pw[i], B);
        }
    }
    uint64_t get(int l, int r) const {                            // hash of s[l..r)
        return (h[r] + MOD - mul(h[l], pw[r - l])) % MOD;
    }
};

// LeetCode 187: all 10-letter substrings appearing more than once (count only)
int repeatedDna(const std::string& s) {
    if (s.size() < 10) return 0;
    Hasher hs(s);
    std::unordered_set<uint64_t> seen, reported;
    for (int i = 0; i + 10 <= static_cast<int>(s.size()); ++i) {
        uint64_t x = hs.get(i, i + 10);
        if (!seen.insert(x).second) reported.insert(x);           // seen before
    }
    return static_cast<int>(reported.size());
}

int main() {
    Hasher hs("abcabc");
    assert(hs.get(0, 3) == hs.get(3, 6));                        // "abc" == "abc"
    assert(hs.get(0, 2) != hs.get(1, 3));                        // "ab" != "bc"
    assert(repeatedDna("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") == 2);
    assert(repeatedDna("AAAAAAAAAAAAA") == 1);
    std::cout << "rolling_hash: all tests passed\n";
    return 0;
}
