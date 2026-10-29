// XPSC Week 16 Day 03 - CSES 1071 Number Spiral
// Link: https://cses.fi/problemset/task/1071
//
// Problem: value at row y, column x of the infinite number spiral.
// Idea:    layer z = max(y, x) ends at z^2. Even layers run one way, odd the other,
//          so the value is z^2 - offset or (z-1)^2 + offset depending on parity.
// Time: O(1)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1071_number_spiral.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>

long long spiral(long long y, long long x) {
    long long z = std::max(y, x);
    if (z % 2 == 0) {                                     // even layer: z^2 at (z, 1)
        return y == z ? z * z - (x - 1) : (z - 1) * (z - 1) + y;
    }
    return x == z ? z * z - (y - 1) : (z - 1) * (z - 1) + x;   // odd layer: z^2 at (1, z)
}

int main() {
    assert(spiral(2, 3) == 8);
    assert(spiral(1, 1) == 1);
    assert(spiral(4, 2) == 15);
    assert(spiral(1, 2) == 2 && spiral(2, 1) == 4 && spiral(3, 1) == 5 && spiral(1, 3) == 9);
    std::cout << "cses_1071_number_spiral: all tests passed\n";
    return 0;
}
