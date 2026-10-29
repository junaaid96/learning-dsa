// Linked list classics: merge two sorted lists, middle node, remove N-th from end,
// palindrome list.
//
// Links: https://leetcode.com/problems/merge-two-sorted-lists/
//        https://leetcode.com/problems/middle-of-the-linked-list/
//        https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//        https://leetcode.com/problems/palindrome-linked-list/
//
// Idea:
//   A dummy head removes "is this the first node?" special cases.
//   Slow/fast pointers: fast moves 2, slow 1 -> slow ends in the middle.
//   Gap of n between two pointers finds the n-th node from the end.
//   Palindrome: reverse the second half and compare.
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra merge_sorted_and_middle.cpp -o ll && ./ll

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

struct ListNode { int val; ListNode* next; };

// helpers: nodes live in a pool so tests do not leak
struct Pool {
    std::vector<std::unique_ptr<ListNode>> nodes;
    ListNode* make(const std::vector<int>& v) {
        ListNode* head = nullptr;
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            nodes.push_back(std::make_unique<ListNode>(ListNode{*it, head}));
            head = nodes.back().get();
        }
        return head;
    }
};
std::vector<int> toVec(ListNode* h) { std::vector<int> v; for (; h; h = h->next) v.push_back(h->val); return v; }

ListNode* mergeTwo(ListNode* a, ListNode* b) {
    ListNode dummy{0, nullptr};
    ListNode* tail = &dummy;
    while (a && b) {
        ListNode*& smaller = (a->val <= b->val) ? a : b;   // reference to the pointer we advance
        tail->next = smaller; tail = smaller; smaller = smaller->next;
    }
    tail->next = a ? a : b;                                 // append the leftover
    return dummy.next;
}

ListNode* middle(ListNode* h) {
    ListNode *slow = h, *fast = h;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow;                                            // second middle for even length
}

ListNode* removeNthFromEnd(ListNode* h, int n) {
    ListNode dummy{0, h};
    ListNode *lead = &dummy, *lag = &dummy;
    for (int i = 0; i <= n; ++i) lead = lead->next;         // gap of n + 1
    while (lead) { lead = lead->next; lag = lag->next; }
    lag->next = lag->next->next;                            // unlink (pool owns memory)
    return dummy.next;
}

bool isPalindrome(ListNode* h) {
    ListNode* mid = middle(h);
    ListNode* prev = nullptr;
    while (mid) { ListNode* nx = mid->next; mid->next = prev; prev = mid; mid = nx; }  // reverse half
    for (ListNode *a = h, *b = prev; b; a = a->next, b = b->next)
        if (a->val != b->val) return false;
    return true;
}

int main() {
    Pool p;
    assert((toVec(mergeTwo(p.make({1, 2, 4}), p.make({1, 3, 4}))) == std::vector<int>{1, 1, 2, 3, 4, 4}));
    assert(middle(p.make({1, 2, 3, 4, 5}))->val == 3 && middle(p.make({1, 2, 3, 4, 5, 6}))->val == 4);
    assert((toVec(removeNthFromEnd(p.make({1, 2, 3, 4, 5}), 2)) == std::vector<int>{1, 2, 3, 5}));
    assert(removeNthFromEnd(p.make({1}), 1) == nullptr);
    assert(isPalindrome(p.make({1, 2, 2, 1})) && !isPalindrome(p.make({1, 2})));
    std::cout << "merge_sorted_and_middle: all tests passed\n";
    return 0;
}
