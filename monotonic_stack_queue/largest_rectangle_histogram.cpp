// Largest Rectangle in Histogram (monotonic increasing stack).
//
// Problem:
//   Bars of width 1 and heights h[i]. Find the largest rectangle area.
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
//
// Idea:
//   For each bar, the widest rectangle using its full height extends until the
//   first smaller bar on each side. With an increasing stack, when we pop bar
//   j because h[i] < h[j], the right limit is i and the left limit is the new
//   stack top. A sentinel height 0 at the end flushes the stack.
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra largest_rectangle_histogram.cpp -o lrh && ./lrh

#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

long long largestRectangleArea(const std::vector<int>& h) {
    const int n = static_cast<int>(h.size());
    std::stack<int> st;                              // indices with increasing heights
    long long best = 0;
    for (int i = 0; i <= n; ++i) {
        const int cur = (i == n) ? 0 : h[i];         // sentinel 0 at the end
        while (!st.empty() && h[st.top()] > cur) {
            const int height = h[st.top()]; st.pop();
            const int left = st.empty() ? -1 : st.top();   // first smaller on the left
            best = std::max(best, 1LL * height * (i - left - 1));  // width between limits
        }
        st.push(i);
    }
    return best;
}

int main() {
    assert(largestRectangleArea({2, 1, 5, 6, 2, 3}) == 10);
    assert(largestRectangleArea({2, 4}) == 4);
    assert(largestRectangleArea({6, 2, 5, 4, 5, 1, 6}) == 12);
    std::cout << "largest_rectangle_histogram: all tests passed\n";
    return 0;
}
