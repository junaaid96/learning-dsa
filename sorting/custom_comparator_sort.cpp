// Sorting with custom comparators: Sort Characters By Frequency + multi-key sort.
//
// Problem:
//   Sort a string so characters with higher frequency come first (ties by
//   character for a deterministic answer).
// Link: https://leetcode.com/problems/sort-characters-by-frequency/
//
// Idea:
//   A comparator cmp(a, b) returns true when a must come BEFORE b. It must be
//   a strict weak ordering: never return true for equal elements.
//   std::tie builds tuples that compare lexicographically: great for multi-keys.
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra custom_comparator_sort.cpp -o ccs && ./ccs

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

std::string frequencySort(std::string s) {
    std::array<int, 256> f{};
    for (unsigned char c : s) f[c]++;                         // count characters
    std::sort(s.begin(), s.end(), [&](unsigned char a, unsigned char b) {
        if (f[a] != f[b]) return f[a] > f[b];                 // higher frequency first
        return a < b;                                         // tie -> smaller char first
    });
    return s;
}

struct Student { std::string name; int score; int age; };

void sortStudents(std::vector<Student>& v) {
    // score descending, then age ascending, then name ascending
    std::sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
        return std::tie(b.score, a.age, a.name) < std::tie(a.score, b.age, b.name);
    });
}

int main() {
    assert(frequencySort("tree") == "eert");
    assert(frequencySort("cccaaa") == "aaaccc");
    std::vector<Student> v{{"bob", 90, 20}, {"amy", 95, 22}, {"cat", 90, 19}, {"dan", 90, 19}};
    sortStudents(v);
    assert(v[0].name == "amy" && v[1].name == "cat" && v[2].name == "dan" && v[3].name == "bob");
    std::cout << "custom_comparator_sort: all tests passed\n";
    return 0;
}
