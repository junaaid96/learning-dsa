// Iterative reversal of a singly linked list.
//
// Idea:
//   Maintain three pointers: prev, curr, next.
//   Rewire curr->next to point to prev while walking through the list.
//
// Compile: g++ -std=c++17 -O2 linked_list_reverse.cpp -o ll_reverse
// Run:     ./ll_reverse

#include <iostream>
#include <memory>

struct ListNode {
    int value{};
    ListNode* next{nullptr};

    explicit ListNode(int v) : value(v), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(const ListNode* head) {
    const ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << "\n";
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4
    auto n1 = std::make_unique<ListNode>(1);
    auto n2 = std::make_unique<ListNode>(2);
    auto n3 = std::make_unique<ListNode>(3);
    auto n4 = std::make_unique<ListNode>(4);

    n1->next = n2.get();
    n2->next = n3.get();
    n3->next = n4.get();

    ListNode* head = n1.get();

    std::cout << "Original list: ";
    printList(head);

    ListNode* reversedHead = reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Nodes are owned by unique_ptrs (n1..n4), so memory is safely released.
    // The reversed pointers do not affect ownership.
    return 0;
}

