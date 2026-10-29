// Count inversions with merge sort.
//
// Problem:
//   Count pairs (i < j) with a[i] > a[j].
// Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
//
// Idea:
//   During the merge step, when the right element R[j] is taken before the
//   left element L[i], R[j] is smaller than ALL remaining left elements, so it
//   forms (size(L) - i) inversions at once.
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra count_inversions_merge_sort.cpp -o inv && ./inv

#include <cassert>
#include <iostream>
#include <vector>

long long sortCount(std::vector<int>& a, std::vector<int>& tmp, int lo, int hi) {
    if (hi - lo <= 1) return 0;                          // [lo, hi) with <= 1 element
    int mid = (lo + hi) / 2;
    long long inv = sortCount(a, tmp, lo, mid) + sortCount(a, tmp, mid, hi);
    int i = lo, j = mid, k = lo;
    while (i < mid && j < hi) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];             // no inversion (<= keeps stability)
        else { tmp[k++] = a[j++]; inv += mid - i; }      // a[j] smaller than all left leftovers
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < hi) tmp[k++] = a[j++];
    for (int t = lo; t < hi; ++t) a[t] = tmp[t];         // copy merged block back
    return inv;
}

long long countInversions(std::vector<int> a) {
    std::vector<int> tmp(a.size());
    return sortCount(a, tmp, 0, static_cast<int>(a.size()));
}

int main() {
    assert(countInversions({2, 4, 1, 3, 5}) == 3);
    assert(countInversions({2, 3, 4, 5, 6}) == 0);
    assert(countInversions({10, 10, 10}) == 0);
    assert(countInversions({5, 4, 3, 2, 1}) == 10);
    std::cout << "count_inversions_merge_sort: all tests passed\n";
    return 0;
}
