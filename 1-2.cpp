#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createList(int n) {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *tail = head;
    int i;
    for (i = 0; i < n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        cout << "请输入第 " << i + 1 << " 个元素的值：";
        cin >> newNode->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void adjustList(Node *head) {
    Node *p = head->next;
    Node *evenHead = (Node *)malloc(sizeof(Node));
    evenHead->next = NULL;
    Node *evenTail = evenHead;
    Node *oddHead = (Node *)malloc(sizeof(Node));
    oddHead->next = NULL;
    Node *oddTail = oddHead;
    int count = 1;
    while (p != NULL) {
        Node *next = p->next;
        if (count % 2 == 0) {
            evenTail->next = p;
            evenTail = p;
            evenTail->next = NULL;
        } else {
            oddTail->next = p;
            oddTail = p;
            oddTail->next = NULL;
        }
        p = next;
        count++;
    }
    evenTail->next = oddHead->next;
    head->next = evenHead->next;
    free(evenHead);
    free(oddHead);
}

void printList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void freeList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        Node *next = p->next;
        free(p);
        p = next;
    }
}

int main() {
    int n;
    cout << "请输入线性表的长度：";
    cin >> n;
    Node *head = createList(n);
    cout << "调整前：";
    printList(head);
    adjustList(head);
    cout << "调整后：";
    printList(head);
    freeList(head);
    return 0;
}