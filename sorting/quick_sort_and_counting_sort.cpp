// Quick sort (Lomuto partition, random pivot) and counting sort.
//
// Problem:
//   Sort an array of integers.
// Link: https://leetcode.com/problems/sort-an-array/
//
// Idea:
//   Quick sort: pick a pivot, move smaller items left of it, recurse on both
//   sides. Random pivot makes the O(n^2) worst case very unlikely.
//   Counting sort: when values lie in a small range [lo, hi], count each value
//   and write them back in order: O(n + range), no comparisons.
//
// Time: quick sort O(n log n) expected; counting sort O(n + range)
// Space: O(log n) recursion; O(range)
//
// Compile: g++ -std=c++17 -Wall -Wextra quick_sort_and_counting_sort.cpp -o qs && ./qs

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

std::mt19937 rng(12345);                                   // fixed seed for reproducibility

int partition(std::vector<int>& a, int lo, int hi) {
    int p = std::uniform_int_distribution<int>(lo, hi)(rng);  // random pivot index
    std::swap(a[p], a[hi]);                                // move pivot to the end
    int store = lo;                                        // next slot for a smaller value
    for (int i = lo; i < hi; ++i)
        if (a[i] < a[hi]) std::swap(a[i], a[store++]);     // smaller -> left block
    std::swap(a[store], a[hi]);                            // pivot into its final place
    return store;
}

void quickSort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;                                  // 0 or 1 element: sorted
    int p = partition(a, lo, hi);
    quickSort(a, lo, p - 1);
    quickSort(a, p + 1, hi);
}

void countingSort(std::vector<int>& a) {
    if (a.empty()) return;
    auto [mn, mx] = std::minmax_element(a.begin(), a.end());
    int lo = *mn, hi = *mx;
    std::vector<int> cnt(hi - lo + 1, 0);
    for (int x : a) cnt[x - lo]++;                         // shift so index starts at 0
    int k = 0;
    for (int v = 0; v <= hi - lo; ++v)
        while (cnt[v]--) a[k++] = v + lo;                  // write values back in order
}

int main() {
    std::vector<int> a{5, 2, 3, 1, 9, -4, 3, 0};
    std::vector<int> b = a, expected = a;
    std::sort(expected.begin(), expected.end());
    quickSort(a, 0, static_cast<int>(a.size()) - 1);
    countingSort(b);
    assert(a == expected && b == expected);
    std::cout << "quick_sort_and_counting_sort: all tests passed\n";
    return 0;
}
