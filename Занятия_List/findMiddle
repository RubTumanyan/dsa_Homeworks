#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* findMiddle(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;  
        fast = fast->next->next; 
    }

    return slow;
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
    ListNode* head = createList({1, 2, 3, 4, 5, 6 });
    printList(head);

    ListNode* middle = findMiddle(head);
    if (middle){
        std::cout << middle->val;
    }else{
        std::cout << "it's empty";
    }
    return 0;
}
