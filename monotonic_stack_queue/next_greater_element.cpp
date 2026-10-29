// Next Greater Element (monotonic decreasing stack).
//
// Problem:
//   For each element, find the first element to its right that is greater,
//   or -1. (Daily Temperatures is the same pattern returning distances.)
// Links: https://leetcode.com/problems/next-greater-element-ii/  (circular variant)
//        https://leetcode.com/problems/daily-temperatures/
//
// Idea:
//   Keep a stack of indices whose answer is still unknown; their values are
//   decreasing from bottom to top. When a bigger value arrives, it is the
//   answer for every smaller value on top of the stack: pop them.
//
// Time: O(n) (each index is pushed and popped once)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra next_greater_element.cpp -o nge && ./nge

#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreater(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    std::vector<int> ans(n, -1);                    // default: no greater element
    std::stack<int> st;                             // indices waiting for an answer
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] < a[i]) { // a[i] beats the waiting values
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);                                 // i now waits for its answer
    }
    return ans;
}

std::vector<int> dailyTemperatures(const std::vector<int>& t) {
    const int n = static_cast<int>(t.size());
    std::vector<int> ans(n, 0);
    std::stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && t[st.top()] < t[i]) {
            ans[st.top()] = i - st.top();           // days to wait = index distance
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    assert((nextGreater({4, 5, 2, 25}) == std::vector<int>{5, 25, 25, -1}));
    assert((nextGreater({13, 7, 6, 12}) == std::vector<int>{-1, 12, 12, -1}));
    assert((dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}) == std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
    std::cout << "next_greater_element: all tests passed\n";
    return 0;
}
