#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createBinaryTree(string preorder, int& index) {
    if (index >= preorder.length() || preorder[index] == '#') {
        index++;
        return nullptr;
    }

    TreeNode* node = new TreeNode;
    node->data = preorder[index] - '0';
    index++;

    node->left = createBinaryTree(preorder, index);
    node->right = createBinaryTree(preorder, index);

    return node;
}

void swapChildren(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;

    swapChildren(node->left);
    swapChildren(node->right);
}

void preorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        cout << "#";
        return;
    }

    cout << node->data;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

int main() {
    string preorder = "124###35###";
    int index = 0;

    TreeNode* root = createBinaryTree(preorder, index);

    cout << "原始二叉树先序遍历结果: ";
    preorderTraversal(root);
    cout << endl;

    swapChildren(root);

    cout << "交换后的二叉树先序遍历结果: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}