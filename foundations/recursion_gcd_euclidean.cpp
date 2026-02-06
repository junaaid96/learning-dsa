// GCD using Euclidean algorithm: recursive and iterative versions.
//
// Key idea:
//   gcd(a, b) = gcd(b, a % b), with gcd(a, 0) = a (a > 0).
//
// Shows recursion, base case, and call stack behavior in a simple setting.
//
// Compile: g++ -std=c++17 -O2 recursion_gcd_euclidean.cpp -o gcd_demo
// Run:     ./gcd_demo

#include <iostream>
#include <utility>

int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

int gcdIterative(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int a = 48;
    int b = 18;

    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    std::cout << "Computing GCD of " << a << " and " << b << "\n";

    int g1 = gcdRecursive(a, b);
    int g2 = gcdIterative(a, b);

    std::cout << "Recursive GCD: " << g1 << "\n";
    std::cout << "Iterative GCD: " << g2 << "\n";

    std::cout << "Both methods should produce the same result.\n";
    return 0;
}

