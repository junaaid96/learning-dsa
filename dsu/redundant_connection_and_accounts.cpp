// DSU applications: Redundant Connection and Accounts Merge.
//
// Problems:
//   (1) A tree plus one extra edge: return the edge that creates the cycle
//       (the last such edge in input order).
//       Link: https://leetcode.com/problems/redundant-connection/
//   (2) Merge accounts that share any email.
//       Link: https://leetcode.com/problems/accounts-merge/
//
// Idea:
//   (1) Process edges; the first edge whose ends are already connected closes
//       a cycle.
//   (2) Union account i with the first account that owned each of its emails,
//       then group emails by root.
//
// Time: ~O(E alpha) / O(total emails * log)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra redundant_connection_and_accounts.cpp -o rc && ./rc

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

struct DSU {
    std::vector<int> p;
    explicit DSU(int n) : p(n) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }   // recursive compression
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; p[b] = a; return true; }
};

std::vector<int> findRedundantConnection(const std::vector<std::vector<int>>& edges) {
    DSU d(static_cast<int>(edges.size()) + 1);        // nodes are 1..n
    for (const auto& e : edges)
        if (!d.unite(e[0], e[1])) return e;           // already connected -> cycle edge
    return {};
}

using Accounts = std::vector<std::vector<std::string>>;

Accounts accountsMerge(const Accounts& acc) {
    DSU d(static_cast<int>(acc.size()));
    std::unordered_map<std::string, int> owner;       // email -> first account index
    for (int i = 0; i < static_cast<int>(acc.size()); ++i)
        for (std::size_t j = 1; j < acc[i].size(); ++j) {
            auto it = owner.find(acc[i][j]);
            if (it == owner.end()) owner[acc[i][j]] = i;
            else d.unite(it->second, i);              // shared email -> same person
        }
    std::map<int, std::vector<std::string>> groups;   // root -> emails
    for (auto& [email, i] : owner) groups[d.find(i)].push_back(email);
    Accounts out;
    for (auto& [root, emails] : groups) {
        std::sort(emails.begin(), emails.end());
        std::vector<std::string> row{acc[root][0]};  // name first
        row.insert(row.end(), emails.begin(), emails.end());
        out.push_back(row);
    }
    std::sort(out.begin(), out.end());
    return out;
}

int main() {
    assert((findRedundantConnection({{1, 2}, {1, 3}, {2, 3}}) == std::vector<int>{2, 3}));
    assert((findRedundantConnection({{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}) == std::vector<int>{1, 4}));
    Accounts a{{"John", "j1@m", "j2@m"}, {"John", "j1@m", "j3@m"}, {"Mary", "m@m"}, {"John", "jx@m"}};
    Accounts r = accountsMerge(a);
    assert(r.size() == 3);
    assert((r[0] == std::vector<std::string>{"John", "j1@m", "j2@m", "j3@m"}));
    std::cout << "redundant_connection_and_accounts: all tests passed\n";
    return 0;
}
