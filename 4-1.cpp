#include <iostream>
#include <cstring>
using namespace std;

struct BiNode {
    int data;
    BiNode *lchild;
    BiNode *rchild;
};

BiNode *buildTree(const char *preorder, const char *inorder, int length, int &preIndex, int inStart, int inEnd) {
    if (inStart > inEnd)
        return nullptr;

    BiNode *newNode = new BiNode;
    newNode->data = preorder[preIndex] - 'A';
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] - 'A' == preorder[preIndex] - 'A') {
            inIndex = i;
            break;
        }
    }

    preIndex++;
    newNode->lchild = buildTree(preorder, inorder, length, preIndex, inStart, inIndex - 1);
    newNode->rchild = buildTree(preorder, inorder, length, preIndex, inIndex + 1, inEnd);

    return newNode;
}

void postorderTraversal(BiNode *root) {
    if (root == nullptr)
        return;

    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    cout << (char)(root->data + 'A');
}

int main() {
    const char *preorder = "ABCDEFGH";
    const char *inorder = "CBEDFAGH";
    int length = strlen(preorder);
    int preIndex = 0;

    BiNode *root = buildTree(preorder, inorder, length, preIndex, 0, length - 1);

    cout << "后序遍历结果为：";
    postorderTraversal(root);
    cout << endl;

    return 0;
}