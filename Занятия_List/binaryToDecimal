#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

int binaryToDecimal(ListNode* head) {
    int result = 0;
    
    while (head != nullptr) {
        result = result * 2 + head->val;
        head = head->next;
    }

    return result;
}

ListNode* createList(const std::initializer_list<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createList({1, 0, 1, 1});
    printList(head);
    int decimal = binaryToDecimal(head);
    std::cout << decimal << std::endl;

    return 0;
}
