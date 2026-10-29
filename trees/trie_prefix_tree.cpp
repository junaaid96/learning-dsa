// Trie (prefix tree) + maximum XOR of two numbers (binary trie).
//
// Links: https://leetcode.com/problems/implement-trie-prefix-tree/
//        https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//        https://cses.fi/problemset/task/1731  (Word Combinations, trie + DP)
//
// Idea:
//   Each node has 26 child slots; a path from the root spells a prefix.
//   Binary trie: insert numbers bit by bit from the top; for max XOR walk
//   toward the opposite bit whenever possible (greedy on high bits).
//
// Time: O(L) per word op; O(n * 31) for max XOR    Space: O(total characters)
//
// Compile: g++ -std=c++17 -Wall -Wextra trie_prefix_tree.cpp -o trie && ./trie

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Trie {
    struct N { std::array<int, 26> next; bool end = false; N() { next.fill(-1); } };
    std::vector<N> t{N()};                                   // node 0 = root
    int walk(const std::string& s) const {                   // node for s, or -1
        int v = 0;
        for (char ch : s) { v = t[v].next[ch - 'a']; if (v == -1) return -1; }
        return v;
    }
public:
    void insert(const std::string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) { t[v].next[c] = static_cast<int>(t.size()); t.emplace_back(); }
            v = t[v].next[c];
        }
        t[v].end = true;                                     // a word ends here
    }
    bool search(const std::string& s) const { int v = walk(s); return v != -1 && t[v].end; }
    bool startsWith(const std::string& p) const { return walk(p) != -1; }
};

int findMaximumXOR(const std::vector<int>& nums) {
    std::vector<std::array<int, 2>> t(1, {-1, -1});
    auto insert = [&](int x) {
        int v = 0;
        for (int b = 30; b >= 0; --b) {
            int bit = x >> b & 1;
            if (t[v][bit] == -1) { t[v][bit] = static_cast<int>(t.size()); t.push_back({-1, -1}); }
            v = t[v][bit];
        }
    };
    auto best = [&](int x) {
        int v = 0, res = 0;
        for (int b = 30; b >= 0; --b) {
            int want = (x >> b & 1) ^ 1;                     // opposite bit gives a 1 in XOR
            if (t[v][want] != -1) { res |= 1 << b; v = t[v][want]; }
            else v = t[v][want ^ 1];
        }
        return res;
    };
    int ans = 0;
    for (int x : nums) { insert(x); ans = std::max(ans, best(x)); }
    return ans;
}

int main() {
    Trie tr;
    tr.insert("apple");
    assert(tr.search("apple") && !tr.search("app") && tr.startsWith("app"));
    tr.insert("app");
    assert(tr.search("app"));
    assert(findMaximumXOR({3, 10, 5, 25, 2, 8}) == 28);
    assert(findMaximumXOR({14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70}) == 127);
    std::cout << "trie_prefix_tree: all tests passed\n";
    return 0;
}
