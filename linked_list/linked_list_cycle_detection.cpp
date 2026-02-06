// Linked list cycle detection using fast & slow pointers (Floyd's algorithm).
//
// Idea:
//   Use two pointers:
//     slow moves 1 step at a time
//     fast moves 2 steps at a time
//   If there is a cycle, they will eventually meet inside the cycle.
//
// Compile: g++ -std=c++17 -O2 linked_list_cycle_detection.cpp -o ll_cycle
// Run:     ./ll_cycle

#include <iostream>
#include <memory>

struct ListNode {
    int value{};
    ListNode* next{nullptr};

    explicit ListNode(int v) : value(v), next(nullptr) {}
};

ListNode* detectCycleMeetingPoint(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow; // meeting point
        }
    }
    return nullptr;
}

bool hasCycle(ListNode* head) {
    return detectCycleMeetingPoint(head) != nullptr;
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    auto n1 = std::make_unique<ListNode>(1);
    auto n2 = std::make_unique<ListNode>(2);
    auto n3 = std::make_unique<ListNode>(3);
    auto n4 = std::make_unique<ListNode>(4);
    auto n5 = std::make_unique<ListNode>(5);

    n1->next = n2.get();
    n2->next = n3.get();
    n3->next = n4.get();
    n4->next = n5.get();

    // Create a cycle: 5 -> 3
    n5->next = n3.get();

    ListNode* head = n1.get();

    std::cout << "Linked list with a cycle created (5 -> 3).\n";
    std::cout << "Detecting cycle...\n";

    if (hasCycle(head)) {
        std::cout << "Cycle detected.\n";
    } else {
        std::cout << "No cycle detected.\n";
    }

    // WARNING: Because of the cycle, we must not traverse to delete nodes manually.
    // In this demo, nodes are owned by unique_ptrs and we do not follow next pointers
    // on destruction, so memory is still freed safely when unique_ptrs go out of scope.

    return 0;
}

