#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} *LinkList;

int getLength(LinkList head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

LinkList findFirstCommonNode(LinkList head1, LinkList head2) {
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    while (length1 > length2) {
        head1 = head1->next;
        length1--;
    }
    while (length2 > length1) {
        head2 = head2->next;
        length2--;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

LinkList createList(int arr[], int n) {
    LinkList head = NULL, tail = NULL;
    for (int i = 0; i < n; i++) {
        LinkList newNode = (LinkList)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(LinkList head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7};

    LinkList head1 = createList(arr1, 5);
    LinkList head2 = createList(arr2, 2);

    head2->next->next = head1->next->next->next;

    cout << "链表1：";
    printList(head1);

    cout << "链表2：";
    printList(head2);

    LinkList commonNode = findFirstCommonNode(head1, head2);
    if (commonNode != NULL) {
        cout << "第一个公共结点的值为：" << commonNode->data << endl;
    } else {
        cout << "两个链表没有公共结点" << endl;
    }

    return 0;
}