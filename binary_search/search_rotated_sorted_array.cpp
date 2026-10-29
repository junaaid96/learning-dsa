// Search in Rotated Sorted Array.
//
// Problem:
//   A sorted array of distinct values was rotated. Find target's index or -1.
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// Idea:
//   At every mid, one of the halves [lo, mid] or [mid, hi] is sorted. Check if
//   the target lies inside the sorted half; keep that half, else the other.
//
// Time: O(log n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra search_rotated_sorted_array.cpp -o srsa && ./srsa

#include <cassert>
#include <iostream>
#include <vector>

int search(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[lo] <= a[mid]) {                                // left half is sorted
            if (a[lo] <= target && target < a[mid]) hi = mid - 1;  // target inside it
            else lo = mid + 1;
        } else {                                              // right half is sorted
            if (a[mid] < target && target <= a[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    assert(search({4, 5, 6, 7, 0, 1, 2}, 0) == 4);
    assert(search({4, 5, 6, 7, 0, 1, 2}, 3) == -1);
    assert(search({1}, 0) == -1);
    assert(search({3, 1}, 1) == 1);
    std::cout << "search_rotated_sorted_array: all tests passed\n";
    return 0;
}
