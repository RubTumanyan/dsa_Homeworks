#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteValue(ListNode* head, int value) {
    while (head && head->val == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* current = head;
    while (current && current->next) {
        if (current->next->val == value) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

ListNode* createNode(int value) {
    return new ListNode(value);
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(3);

    printList(head);

    head = deleteValue(head, 3);

   
    printList(head);

    return 0;
}
