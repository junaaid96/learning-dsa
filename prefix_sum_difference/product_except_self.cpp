// Product of Array Except Self (prefix and suffix products, no division).
//
// Problem:
//   ans[i] = product of all nums[j] with j != i.
// Link: https://leetcode.com/problems/product-of-array-except-self/
//
// Idea:
//   ans[i] = (product of everything left of i) * (product of everything right
//   of i). Fill left products in one pass and multiply right products in a
//   second pass with a running variable.
//
// Time: O(n)    Space: O(1) extra besides output
//
// Compile: g++ -std=c++17 -Wall -Wextra product_except_self.cpp -o pes && ./pes

#include <cassert>
#include <iostream>
#include <vector>

std::vector<long long> productExceptSelf(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    std::vector<long long> ans(n, 1);
    for (int i = 1; i < n; ++i) ans[i] = ans[i - 1] * a[i - 1];   // prefix products
    long long right = 1;                                          // product of a[i+1..]
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= right;
        right *= a[i];
    }
    return ans;
}

int main() {
    assert((productExceptSelf({1, 2, 3, 4}) == std::vector<long long>{24, 12, 8, 6}));
    assert((productExceptSelf({-1, 1, 0, -3, 3}) == std::vector<long long>{0, 0, 9, 0, 0}));
    std::cout << "product_except_self: all tests passed\n";
    return 0;
}
