#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};


bool findNode(ListNode* head, int value) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == value) {
            return true; 
        }
        current = current->next;
    }
    return false; 
}


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(23);
    head->next->next->next = new ListNode(252);
    head->next->next->next->next = new ListNode(545);
    
    std::cout << std::boolalpha << findNode(head , 545);

    return 0;
}
