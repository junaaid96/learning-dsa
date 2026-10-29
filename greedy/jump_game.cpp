// Jump Game I and II (greedy reach).
//
// Problem:
//   nums[i] = max jump length from i. (I) Can you reach the last index?
//   (II) Minimum number of jumps to reach it.
// Links: https://leetcode.com/problems/jump-game/
//        https://leetcode.com/problems/jump-game-ii/
//
// Idea:
//   (I) Track the furthest reachable index; fail if i ever exceeds it.
//   (II) BFS by levels: [curStart, curEnd] is reachable with `jumps` jumps;
//   the furthest index reachable from this level becomes the next level end.
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra jump_game.cpp -o jump && ./jump

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

bool canJump(const std::vector<int>& a) {
    int reach = 0;                                       // furthest index we can stand on
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (i > reach) return false;                     // i is unreachable
        reach = std::max(reach, i + a[i]);
    }
    return true;
}

int minJumps(const std::vector<int>& a) {
    int jumps = 0, curEnd = 0, furthest = 0;
    for (int i = 0; i + 1 < static_cast<int>(a.size()); ++i) {
        furthest = std::max(furthest, i + a[i]);         // best reach from this level
        if (i == curEnd) {                               // level finished -> must jump
            ++jumps;
            curEnd = furthest;
        }
    }
    return jumps;
}

int main() {
    assert(canJump({2, 3, 1, 1, 4}));
    assert(!canJump({3, 2, 1, 0, 4}));
    assert(minJumps({2, 3, 1, 1, 4}) == 2);
    assert(minJumps({2, 3, 0, 1, 4}) == 2);
    assert(minJumps({0}) == 0);
    std::cout << "jump_game: all tests passed\n";
    return 0;
}
