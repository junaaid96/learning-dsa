// Task Scheduler (greedy counting; max-heap intuition).
//
// Problem:
//   Tasks A..Z, each takes one unit; identical tasks need n idle units
//   between them. Minimum total time to run all tasks.
// Link: https://leetcode.com/problems/task-scheduler/
//
// Idea:
//   The most frequent task (count maxF) forces (maxF - 1) full frames of size
//   (n + 1), plus one slot for each task tying for maxF at the end. If there
//   are more tasks than this, no idling is needed: answer = number of tasks.
//
// Time: O(T)    Space: O(26)
//
// Compile: g++ -std=c++17 -Wall -Wextra task_scheduler.cpp -o ts && ./ts

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

int leastInterval(const std::vector<char>& tasks, int n) {
    std::array<int, 26> f{};
    for (char c : tasks) f[c - 'A']++;                    // frequency of each task
    int maxF = *std::max_element(f.begin(), f.end());
    int tie = static_cast<int>(std::count(f.begin(), f.end(), maxF));  // tasks with maxF
    int frames = (maxF - 1) * (n + 1) + tie;              // schedule forced by top task
    return std::max(frames, static_cast<int>(tasks.size()));
}

int main() {
    assert(leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) == 8);
    assert(leastInterval({'A', 'C', 'A', 'B', 'D', 'B'}, 1) == 6);
    assert(leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 3) == 10);
    std::cout << "task_scheduler: all tests passed\n";
    return 0;
}
