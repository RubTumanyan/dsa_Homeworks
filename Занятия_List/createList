#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

template <typename... Args>
ListNode* createList(Args... args) {

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    
    (..., (tail = (tail ? (tail->next = new ListNode(args)) : (head = new ListNode(args)), tail ? tail->next : head)));

    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createList(1, 2, 3, 4, 5);
    
    printList(head);

    return 0;
}
