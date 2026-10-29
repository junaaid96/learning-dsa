// Gas Station (greedy restart).
//
// Problem:
//   Circular route; gas[i] gained at station i, cost[i] to go to i+1. Return
//   the start index that completes the circuit, or -1.
// Link: https://leetcode.com/problems/gas-station/
//
// Idea:
//   If total gas < total cost: impossible. Otherwise, whenever the tank goes
//   negative at i, no station between start and i can be a valid start, so
//   restart at i + 1.
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra gas_station.cpp -o gas && ./gas

#include <cassert>
#include <iostream>
#include <vector>

int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
    long long total = 0, tank = 0;
    int start = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
        const int diff = gas[i] - cost[i];       // net gain at station i
        total += diff;
        tank += diff;
        if (tank < 0) { start = i + 1; tank = 0; }  // cannot pass i -> restart after it
    }
    return total < 0 ? -1 : start;
}

int main() {
    assert(canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) == 3);
    assert(canCompleteCircuit({2, 3, 4}, {3, 4, 3}) == -1);
    std::cout << "gas_station: all tests passed\n";
    return 0;
}
