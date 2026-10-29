// Disjoint Set Union (Union-Find) with path compression + union by size.
//
// Problem (Number of Provinces / connected components):
//   Count connected components of a graph given as edges; also answer
//   "are u and v connected?" queries.
// Links: https://leetcode.com/problems/number-of-provinces/
//        https://cses.fi/problemset/task/1676  (Road Construction)
//
// Idea:
//   Each set has a representative (root). find() walks to the root and
//   flattens the path. unite() attaches the smaller tree under the larger.
//   Both together give almost O(1) (inverse Ackermann) per operation.
//
// Time: O(alpha(n)) per op    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra dsu_template_and_components.cpp -o dsu && ./dsu

#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct DSU {
    std::vector<int> parent, sz;
    int components;
    explicit DSU(int n) : parent(n), sz(n, 1), components(n) {
        std::iota(parent.begin(), parent.end(), 0);          // everyone is their own root
    }
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];                   // path halving (compression)
            x = parent[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;                            // already same set (edge makes a cycle)
        if (sz[a] < sz[b]) std::swap(a, b);                  // a = bigger set
        parent[b] = a;                                       // hang smaller under bigger
        sz[a] += sz[b];
        --components;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};

int main() {
    DSU d(6);
    std::vector<std::pair<int, int>> edges{{0, 1}, {1, 2}, {3, 4}};
    for (auto [u, v] : edges) d.unite(u, v);
    assert(d.components == 3);                               // {0,1,2} {3,4} {5}
    assert(d.find(0) == d.find(2));
    assert(d.find(0) != d.find(3));
    assert(d.size(1) == 3);
    assert(!d.unite(0, 2));                                  // would create a cycle
    std::cout << "dsu_template_and_components: all tests passed\n";
    return 0;
}
