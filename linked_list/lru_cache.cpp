// LRU Cache with std::list + std::unordered_map (O(1) get/put).
//
// Link: https://leetcode.com/problems/lru-cache/
//
// Idea:
//   A doubly linked list keeps keys from most to least recently used; the hash
//   map stores key -> list iterator so we can move/erase in O(1).
//   splice() moves a node to the front without reallocating.
//
// Time: O(1) average per op    Space: O(capacity)
//
// Compile: g++ -std=c++17 -Wall -Wextra lru_cache.cpp -o lru && ./lru

#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
    int cap;
    std::list<std::pair<int, int>> order;                       // front = most recent
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> pos;
public:
    explicit LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        order.splice(order.begin(), order, it->second);         // mark as used
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {                                  // update + refresh
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if (static_cast<int>(order.size()) == cap) {            // evict least recent
            pos.erase(order.back().first);
            order.pop_back();
        }
        order.emplace_front(key, value);
        pos[key] = order.begin();
    }
};

int main() {
    LRUCache c(2);                                              // LeetCode example
    c.put(1, 1); c.put(2, 2);
    assert(c.get(1) == 1);
    c.put(3, 3);                                                // evicts 2
    assert(c.get(2) == -1);
    c.put(4, 4);                                                // evicts 1
    assert(c.get(1) == -1 && c.get(3) == 3 && c.get(4) == 4);
    std::cout << "lru_cache: all tests passed\n";
    return 0;
}
