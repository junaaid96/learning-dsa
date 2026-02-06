// Demonstration of different time complexities in simple loops.
// This file is for intuition only, not for benchmarking.
//
// We show:
// - O(n):   single loop
// - O(n log n): nested loop with logarithmic inner work
// - O(n^2): nested loop with linear inner work
//
// Compile: g++ -std=c++17 -O2 time_space_complexity_demo.cpp -o time_demo
// Run:     ./time_demo

#include <iostream>

void linearTime(int n) {
    long long counter = 0;
    for (int i = 0; i < n; ++i) {
        ++counter;
    }
    std::cout << "Linear O(n) loop performed " << counter << " operations.\n";
}

void nLogNTime(int n) {
    long long counter = 0;
    for (int i = 0; i < n; ++i) {
        int step = 1;
        while (step <= n) {
            ++counter;
            step *= 2; // log n iterations
        }
    }
    std::cout << "O(n log n) loop performed " << counter << " operations.\n";
}

void quadraticTime(int n) {
    long long counter = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ++counter;
        }
    }
    std::cout << "Quadratic O(n^2) loop performed " << counter << " operations.\n";
}

int main() {
    int n = 1000;
    std::cout << "Demonstrating time complexity with n = " << n << "\n\n";

    linearTime(n);
    nLogNTime(n);
    quadraticTime(n);

    std::cout << "\nAs n grows, O(n^2) grows much faster than O(n log n), "
                 "which grows faster than O(n).\n";
    return 0;
}

