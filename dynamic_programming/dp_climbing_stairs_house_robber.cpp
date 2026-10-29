// 1D DP: Climbing Stairs and House Robber.
//
// Problems:
//   (1) Ways to climb n steps taking 1 or 2 at a time.
//       Link: https://leetcode.com/problems/climbing-stairs/
//   (2) Max money robbing houses in a line, never two adjacent.
//       Link: https://leetcode.com/problems/house-robber/
//
// Idea:
//   (1) ways(i) = ways(i-1) + ways(i-2)  (last move was 1 or 2 steps).
//   (2) best(i) = max(best(i-1) skip house i, best(i-2) + a[i] rob house i).
//   Both only need the previous two states -> O(1) memory.
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_climbing_stairs_house_robber.cpp -o dp1 && ./dp1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long climbStairs(int n) {
    long long prev2 = 1, prev1 = 1;          // ways(0) = 1, ways(1) = 1
    for (int i = 2; i <= n; ++i) {
        long long cur = prev1 + prev2;       // transition
        prev2 = prev1; prev1 = cur;          // shift the window of states
    }
    return prev1;
}

long long rob(const std::vector<int>& a) {
    long long take = 0, skip = 0;            // best up to previous house: robbed / not robbed
    for (int x : a) {
        long long newTake = skip + x;        // rob this -> previous must be skipped
        skip = std::max(skip, take);         // skip this -> best of both
        take = newTake;
    }
    return std::max(take, skip);
}

int main() {
    assert(climbStairs(2) == 2);
    assert(climbStairs(3) == 3);
    assert(climbStairs(10) == 89);
    assert(rob({1, 2, 3, 1}) == 4);
    assert(rob({2, 7, 9, 3, 1}) == 12);
    std::cout << "dp_climbing_stairs_house_robber: all tests passed\n";
    return 0;
}
