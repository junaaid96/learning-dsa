// Static Range Sum Queries (1D prefix sums).
//
// Problem:
//   Given an array and q queries (a, b), print sum of x[a..b] (1-indexed).
// Link: https://cses.fi/problemset/task/1646
//
// Idea:
//   P[i] = x[1] + ... + x[i]. Then sum(a..b) = P[b] - P[a-1].
//
// Time: O(n + q)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra static_range_sum_cses.cpp -o srs && ./srs

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

std::vector<long long> answer(const std::vector<int>& x, const std::vector<std::pair<int, int>>& qs) {
    const int n = static_cast<int>(x.size());
    std::vector<long long> P(n + 1, 0);                    // P[0] = 0 (empty prefix)
    for (int i = 1; i <= n; ++i) P[i] = P[i - 1] + x[i - 1];
    std::vector<long long> out;
    for (auto [a, b] : qs) out.push_back(P[b] - P[a - 1]); // O(1) per query
    return out;
}

int main() {
    auto r = answer({3, 2, 4, 5, 1, 1, 5, 3}, {{2, 4}, {5, 6}, {1, 8}, {3, 3}});
    assert((r == std::vector<long long>{11, 2, 24, 4}));
    std::cout << "static_range_sum_cses: all tests passed\n";
    return 0;
}
