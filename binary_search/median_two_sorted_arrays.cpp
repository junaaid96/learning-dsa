// Median of Two Sorted Arrays (binary search on the partition).
//
// Problem:
//   Find the median of two sorted arrays in O(log(min(m, n))).
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// Idea:
//   Cut A at i and B at j = half - i so the left parts hold half the
//   elements. The cut is right when maxLeftA <= minRightB and
//   maxLeftB <= minRightA. Binary search i over the smaller array.
//
// Time: O(log min(m, n))    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra median_two_sorted_arrays.cpp -o med && ./med

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

double findMedianSortedArrays(const std::vector<int>& A, const std::vector<int>& B) {
    if (A.size() > B.size()) return findMedianSortedArrays(B, A);  // search the smaller one
    const int m = static_cast<int>(A.size()), n = static_cast<int>(B.size());
    const int half = (m + n + 1) / 2;                  // size of the left part
    int lo = 0, hi = m;
    while (lo <= hi) {
        int i = (lo + hi) / 2, j = half - i;           // i from A, j from B on the left
        int aL = i ? A[i - 1] : INT_MIN, aR = i < m ? A[i] : INT_MAX;
        int bL = j ? B[j - 1] : INT_MIN, bR = j < n ? B[j] : INT_MAX;
        if (aL <= bR && bL <= aR) {                    // valid partition
            if ((m + n) % 2) return std::max(aL, bL);  // odd total: max of left
            return (std::max(aL, bL) + 0.0 + std::min(aR, bR)) / 2.0;
        }
        if (aL > bR) hi = i - 1;                       // took too many from A
        else lo = i + 1;                               // took too few from A
    }
    return 0.0;                                        // unreachable for valid input
}

int main() {
    assert(std::fabs(findMedianSortedArrays({1, 3}, {2}) - 2.0) < 1e-9);
    assert(std::fabs(findMedianSortedArrays({1, 2}, {3, 4}) - 2.5) < 1e-9);
    assert(std::fabs(findMedianSortedArrays({}, {1}) - 1.0) < 1e-9);
    std::cout << "median_two_sorted_arrays: all tests passed\n";
    return 0;
}
