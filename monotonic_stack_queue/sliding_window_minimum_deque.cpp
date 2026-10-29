// Sliding Window Minimum + Shortest Subarray with Sum >= K (monotonic deque).
//
// Problems:
//   (1) Minimum of every window of size k.
//       Link: https://cses.fi/problemset/task/3221
//   (2) Shortest non-empty subarray with sum >= K (negatives allowed).
//       Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
//
// Idea:
//   A deque of indices whose values are increasing. Front = current minimum.
//   Pop from the back while the new value is smaller (those can never be a
//   minimum again). Pop from the front when the index leaves the window.
//   For (2) we keep prefix sums increasing in the deque and pop the front
//   while P[i] - P[front] >= K (best possible start for this front).
//
// Time: O(n)    Space: O(k) / O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra sliding_window_minimum_deque.cpp -o swm && ./swm

#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>

std::vector<int> windowMins(const std::vector<int>& a, int k) {
    std::deque<int> dq;                                  // indices, values increasing
    std::vector<int> out;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();  // useless elements
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();         // left the window
        if (i >= k - 1) out.push_back(a[dq.front()]);    // window [i-k+1, i] complete
    }
    return out;
}

int shortestSubarray(const std::vector<int>& a, long long K) {
    const int n = static_cast<int>(a.size());
    std::vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) P[i + 1] = P[i] + a[i];
    std::deque<int> dq;
    int best = n + 1;
    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && P[i] - P[dq.front()] >= K) {   // valid -> record, then drop
            best = std::min(best, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && P[dq.back()] >= P[i]) dq.pop_back();  // keep P increasing
        dq.push_back(i);
    }
    return best == n + 1 ? -1 : best;
}

int main() {
    assert((windowMins({1, 3, -1, -3, 5, 3, 6, 7}, 3) == std::vector<int>{-1, -3, -3, -3, 3, 3}));
    assert(shortestSubarray({1}, 1) == 1);
    assert(shortestSubarray({1, 2}, 4) == -1);
    assert(shortestSubarray({2, -1, 2}, 3) == 3);
    std::cout << "sliding_window_minimum_deque: all tests passed\n";
    return 0;
}
