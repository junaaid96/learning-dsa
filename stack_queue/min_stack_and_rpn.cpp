// Stack design + expression problems: Min Stack, Evaluate RPN, Daily Temperatures,
// Queue using two stacks.
//
// Links: https://leetcode.com/problems/min-stack/
//        https://leetcode.com/problems/evaluate-reverse-polish-notation/
//        https://leetcode.com/problems/daily-temperatures/
//        https://leetcode.com/problems/implement-queue-using-stacks/
//
// Idea:
//   Min stack: store (value, min so far) pairs.
//   RPN: push numbers; an operator pops two (right operand first!).
//   Daily temperatures: monotonic decreasing stack of indices.
//   Queue: push to "in", pop from "out", refill out only when empty (amortised O(1)).
//
// Time: O(1) amortised per op / O(n) total    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra min_stack_and_rpn.cpp -o stk && ./stk

#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

class MinStack {
    std::stack<std::pair<int, int>> s;                         // (value, min up to here)
public:
    void push(int v) { s.push({v, s.empty() ? v : std::min(v, s.top().second)}); }
    void pop() { s.pop(); }
    int top() const { return s.top().first; }
    int getMin() const { return s.top().second; }
};

int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<long long> st;
    for (const std::string& t : tokens) {
        if (t.size() == 1 && std::string("+-*/").find(t[0]) != std::string::npos) {
            long long b = st.top(); st.pop();                  // right operand
            long long a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);                               // C++ truncates toward zero
        } else st.push(std::stoll(t));
    }
    return static_cast<int>(st.top());
}

std::vector<int> dailyTemperatures(const std::vector<int>& t) {
    std::vector<int> ans(t.size(), 0);
    std::stack<int> st;                                        // indices, temps decreasing
    for (int i = 0; i < static_cast<int>(t.size()); ++i) {
        while (!st.empty() && t[st.top()] < t[i]) { ans[st.top()] = i - st.top(); st.pop(); }
        st.push(i);
    }
    return ans;
}

class MyQueue {
    std::stack<int> in, out;
    void shift() { if (out.empty()) while (!in.empty()) { out.push(in.top()); in.pop(); } }
public:
    void push(int x) { in.push(x); }
    int pop() { shift(); int v = out.top(); out.pop(); return v; }
    int peek() { shift(); return out.top(); }
    bool empty() const { return in.empty() && out.empty(); }
};

int main() {
    MinStack ms;
    ms.push(-2); ms.push(0); ms.push(-3);
    assert(ms.getMin() == -3);
    ms.pop();
    assert(ms.top() == 0 && ms.getMin() == -2);
    assert(evalRPN({"2", "1", "+", "3", "*"}) == 9);
    assert(evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}) == 22);
    assert((dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}) == std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
    MyQueue q; q.push(1); q.push(2);
    assert(q.peek() == 1 && q.pop() == 1 && !q.empty() && q.pop() == 2 && q.empty());
    std::cout << "min_stack_and_rpn: all tests passed\n";
    return 0;
}
