#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x): val(x) , next(nullptr) {}
};

size_t listLength(ListNode* head) {
    ListNode* current = head;
    size_t count = 0;
    while (current != nullptr) {
        count++;
        current = current ->next;
    }
    return count;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(10);
    
    std::cout << listLength(head);
    return 0;
}
