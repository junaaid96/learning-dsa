// Valid parentheses using a stack.
//
// Problem:
//   Given a string containing '(', ')', '{', '}', '[' and ']', determine
//   if the input string is valid.
//
// Rules:
//   - Open brackets must be closed by the same type of brackets.
//   - Open brackets must be closed in the correct order.
//
// Compile: g++ -std=c++17 -O2 stack_valid_parentheses.cpp -o valid_paren
// Run:     ./valid_paren

#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();

            bool ok = (ch == ')' && top == '(') ||
                      (ch == '}' && top == '{') ||
                      (ch == ']' && top == '[');
            if (!ok) {
                return false;
            }
        } else {
            // Ignore any non-bracket character in this demo.
        }
    }

    return st.empty();
}

int main() {
    const std::string s1 = "()[{}]";
    const std::string s2 = "([)]";
    const std::string s3 = "(((";

    std::cout << s1 << " -> " << (isValidParentheses(s1) ? "valid" : "invalid") << "\n";
    std::cout << s2 << " -> " << (isValidParentheses(s2) ? "valid" : "invalid") << "\n";
    std::cout << s3 << " -> " << (isValidParentheses(s3) ? "valid" : "invalid") << "\n";

    return 0;
}

