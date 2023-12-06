#include <iostream>

using namespace std;

struct BiNode {
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

BiNode* createBinaryTree(char* seq, int& index) {
    if (seq[index] == '\0' || seq[index] == '#') {
        return nullptr;
    }

    BiNode* newNode = new BiNode;
    newNode->data = seq[index] - '0';
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;

    index++;
    newNode->lchild = createBinaryTree(seq, index);

    index++;
    newNode->rchild = createBinaryTree(seq, index);

    return newNode;
}

int countNodes(BiNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = countNodes(root->lchild);
    int rightCount = countNodes(root->rchild);

    return leftCount + rightCount + 1;
}

int main() {
    char seq[] = "124###35###";

    int index = 0;
    BiNode* root = createBinaryTree(seq, index);

    int nodeCount = countNodes(root);
    cout << "The total number of nodes in the binary tree is: " << nodeCount << endl;

    return 0;
}