// Heaps / priority_queue: Kth Largest Element and Merge K Sorted Arrays.
//
// Problems:
//   (1) Kth largest element in an array.
//       Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
//   (2) Merge k sorted lists (here: arrays) into one sorted list.
//       Link: https://leetcode.com/problems/merge-k-sorted-lists/
//
// Idea:
//   (1) Keep a MIN-heap of size k: its top is the kth largest seen so far.
//   (2) Push the head of every list into a min-heap; repeatedly pop the
//       smallest and push the next element from the same list.
//
// Time: (1) O(n log k)  (2) O(N log k)    Space: O(k)
//
// Compile: g++ -std=c++17 -Wall -Wextra kth_largest_and_merge_k_lists.cpp -o heap1 && ./heap1

#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int findKthLargest(const std::vector<int>& a, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;  // min-heap
    for (int x : a) {
        pq.push(x);
        if (static_cast<int>(pq.size()) > k) pq.pop();   // drop the smallest -> keep k largest
    }
    return pq.top();
}

std::vector<int> mergeK(const std::vector<std::vector<int>>& lists) {
    using T = std::tuple<int, int, int>;                  // (value, list id, index in list)
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    for (int i = 0; i < static_cast<int>(lists.size()); ++i)
        if (!lists[i].empty()) pq.emplace(lists[i][0], i, 0);
    std::vector<int> out;
    while (!pq.empty()) {
        auto [v, li, idx] = pq.top(); pq.pop();          // smallest current head
        out.push_back(v);
        if (idx + 1 < static_cast<int>(lists[li].size()))
            pq.emplace(lists[li][idx + 1], li, idx + 1); // advance in that list
    }
    return out;
}

int main() {
    assert(findKthLargest({3, 2, 1, 5, 6, 4}, 2) == 5);
    assert(findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) == 4);
    assert((mergeK({{1, 4, 5}, {1, 3, 4}, {2, 6}}) == std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6}));
    std::cout << "kth_largest_and_merge_k_lists: all tests passed\n";
    return 0;
}
