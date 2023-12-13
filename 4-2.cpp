#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    ListNode *head = new ListNode{1, nullptr};
    ListNode *node2 = new ListNode{2, nullptr};
    ListNode *node3 = new ListNode{3, nullptr};
    ListNode *node4 = new ListNode{4, nullptr};
    ListNode *node5 = new ListNode{5, nullptr};
    ListNode *node6 = new ListNode{6, nullptr};

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node3;

    ListNode *cycleStart = detectCycle(head);

    if (cycleStart != nullptr) {
        cout << "链表存在环，入口点的值为: " << cycleStart->val << endl;
    } else {
        cout << "链表不存在环" << endl;
    }

    delete head;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}