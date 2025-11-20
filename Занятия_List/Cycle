#include <iostream>
#include <initializer_list>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
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

void makeCycle(ListNode* head, int pos) {
    if (!head || pos < 0) return;

    ListNode* cycleNode = nullptr;
    ListNode* tail = head;
    int index = 0;

    while (tail->next) {
        if (index == pos) cycleNode = tail;
        tail = tail->next;
        index++;
    }
    if (cycleNode) {
        tail->next = cycleNode;
    }
}

void printList(ListNode* head) {
    ListNode* current = head;
    int count = 0;
    while (current && count < 20) {
        std::cout << current->val << " ";
        current = current->next;
        count++;
    }
    if (current) std::cout << "...";
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    printList(head1);
    std::cout << "Has cycle? " << (hasCycle(head1) ? "Yes" : "No") << std::endl;

    return 0;
}
