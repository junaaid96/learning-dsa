// Find Median from Data Stream (two heaps).
//
// Problem:
//   Support addNum(x) and findMedian() over all numbers added so far.
// Link: https://leetcode.com/problems/find-median-from-data-stream/
//
// Idea:
//   lo = max-heap holding the smaller half, hi = min-heap holding the larger
//   half. Keep size(lo) == size(hi) or size(lo) == size(hi) + 1. The median is
//   lo.top() (odd count) or the average of both tops (even count).
//
// Time: O(log n) add, O(1) median    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra median_from_data_stream.cpp -o mfds && ./mfds

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
    std::priority_queue<int> lo;                                       // max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi;  // min-heap
public:
    void addNum(int x) {
        lo.push(x);                                // put into lower half first
        hi.push(lo.top()); lo.pop();               // move the largest of lower half up
        if (hi.size() > lo.size()) { lo.push(hi.top()); hi.pop(); }  // rebalance sizes
    }
    double findMedian() const {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + 0.0 + hi.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2);
    assert(std::fabs(mf.findMedian() - 1.5) < 1e-9);
    mf.addNum(3);
    assert(std::fabs(mf.findMedian() - 2.0) < 1e-9);
    std::cout << "median_from_data_stream: all tests passed\n";
    return 0;
}
