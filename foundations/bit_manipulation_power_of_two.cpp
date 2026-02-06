// Bit manipulation: check if an integer is a power of two.
//
// Key identity for positive integers:
//   n is a power of two  <=>  (n & (n - 1)) == 0
//
// Example:
//   8  -> 1000 (binary)
//   7  -> 0111 (binary)
//   8 & 7 = 0000
//
//   10 -> 1010
//   9  -> 1001
//   10 & 9 = 1000 != 0  (not a power of two)
//
// Compile: g++ -std=c++17 -O2 bit_manipulation_power_of_two.cpp -o bit_demo
// Run:     ./bit_demo

#include <iostream>
#include <vector>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}

int main() {
    const std::vector<int> testValues{0, 1, 2, 3, 4, 5, 8, 10, 16, 18, 32, -2};

    std::cout << "Checking power-of-two status:\n\n";
    for (int value : testValues) {
        std::cout << value << " -> " << (isPowerOfTwo(value) ? "YES" : "NO") << "\n";
    }

    std::cout << "\nOnly positive powers of two should return YES.\n";
    return 0;
}

