// Group Anagrams.
//
// Problem:
//   Given a list of words, group the words that are anagrams of each other.
// Link: https://leetcode.com/problems/group-anagrams/
//
// Idea:
//   Two words are anagrams iff they have the same letter counts. Build a
//   canonical key (the 26 counts encoded as a string) and bucket words by it.
//
// Time:  O(total characters)    Space: O(total characters)
//
// Compile: g++ -std=c++17 -Wall -Wextra group_anagrams.cpp -o ga && ./ga

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& words) {
    std::unordered_map<std::string, std::vector<std::string>> buckets;  // key -> words
    for (const std::string& w : words) {
        std::array<int, 26> cnt{};                     // letter frequencies, all zero
        for (char c : w) cnt[c - 'a']++;               // count each lowercase letter
        std::string key;                               // encode counts as "1#0#2#..."
        for (int x : cnt) { key += std::to_string(x); key += '#'; }
        buckets[key].push_back(w);                     // same key => anagram group
    }
    std::vector<std::vector<std::string>> out;
    for (auto& [key, group] : buckets) {               // structured binding (C++17)
        std::sort(group.begin(), group.end());         // sort for deterministic output
        out.push_back(group);
    }
    std::sort(out.begin(), out.end());                 // deterministic order of groups
    return out;
}

int main() {
    auto g = groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    std::vector<std::vector<std::string>> expected{{"ate", "eat", "tea"}, {"bat"}, {"nat", "tan"}};
    assert(g == expected);
    std::cout << "group_anagrams: all tests passed\n";
    return 0;
}
