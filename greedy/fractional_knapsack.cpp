// Fractional Knapsack (greedy by value/weight ratio).
//
// Problem:
//   Items with value and weight; you may take fractions. Maximize value with
//   capacity W.
// Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
//
// Idea:
//   Take items in decreasing value/weight order; take whole items while they
//   fit and a fraction of the first one that does not.
//   (For 0/1 knapsack greedy FAILS - use DP instead.)
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra fractional_knapsack.cpp -o fk && ./fk

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

struct Item { int value, weight; };

double fractionalKnapsack(std::vector<Item> items, int W) {
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return 1LL * a.value * b.weight > 1LL * b.value * a.weight;  // compare ratios without division
    });
    double total = 0;
    int left = W;                                    // remaining capacity
    for (const Item& it : items) {
        if (left == 0) break;
        if (it.weight <= left) { total += it.value; left -= it.weight; }  // whole item
        else { total += 1.0 * it.value * left / it.weight; left = 0; }    // fraction
    }
    return total;
}

int main() {
    assert(std::fabs(fractionalKnapsack({{60, 10}, {100, 20}, {120, 30}}, 50) - 240.0) < 1e-9);
    std::cout << "fractional_knapsack: all tests passed\n";
    return 0;
}
