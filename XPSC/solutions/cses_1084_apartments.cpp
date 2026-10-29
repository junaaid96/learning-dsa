// XPSC Week 15 Day 04 - CSES 1084 Apartments
// Link: https://cses.fi/problemset/task/1084
//
// Problem: applicant wants size within [a - k, a + k]; maximise matched applicants.
// Idea:    sort both lists and walk two pointers: skip apartments that are too
//          small, skip applicants whose range is already passed, match otherwise.
// Time: O(n log n + m log m)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1084_apartments.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int apartments(std::vector<long long> want, std::vector<long long> apt, long long k) {
    std::sort(want.begin(), want.end());
    std::sort(apt.begin(), apt.end());
    size_t i = 0, j = 0;
    int matched = 0;
    while (i < want.size() && j < apt.size()) {
        if (apt[j] < want[i] - k) ++j;                    // apartment too small for anyone left
        else if (apt[j] > want[i] + k) ++i;               // applicant can't be served
        else { ++matched; ++i; ++j; }                     // fits -> match
    }
    return matched;
}

int main() {
    assert(apartments({60, 45, 80, 60}, {30, 60, 75}, 5) == 2);
    std::cout << "cses_1084_apartments: all tests passed\n";
    return 0;
}
