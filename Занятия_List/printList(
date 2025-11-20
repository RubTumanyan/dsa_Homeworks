#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x): val(x) , next(nullptr) {}
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current ->next;
    }
    std::cout << "\n";
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(10);
    
    printList(head);
    return 0;
}
