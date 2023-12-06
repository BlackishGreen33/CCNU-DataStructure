#include <iostream>
#include <cmath>

using namespace std;

struct BiNode {
    int data;
    BiNode *lchild;
    BiNode *rchild;
};

BiNode *createBinaryTree(char *seq, int &index) {
    if (seq[index] == '\0' || seq[index] == '#') {
        return nullptr;
    }

    BiNode *newNode = new BiNode;
    newNode->data = seq[index] - '0';
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;

    index++;
    newNode->lchild = createBinaryTree(seq, index);

    index++;
    newNode->rchild = createBinaryTree(seq, index);

    return newNode;
}

int getHeight(BiNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(root->lchild);
    int rightHeight = getHeight(root->rchild);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(BiNode *root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = getHeight(root->lchild);
    int rightHeight = getHeight(root->rchild);

    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    return isBalanced(root->lchild) && isBalanced(root->rchild);
}

int main() {
    char seq[] = "124###35###";

    int index = 0;
    BiNode *root = createBinaryTree(seq, index);

    if (isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}