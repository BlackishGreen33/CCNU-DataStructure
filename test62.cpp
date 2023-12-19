#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createBinaryTree(string preorder, int &index) {
    if (index >= preorder.length() || preorder[index] == '#') {
        index++;
        return nullptr;
    }

    TreeNode *node = new TreeNode;
    node->data = preorder[index] - '0';
    index++;

    node->left = createBinaryTree(preorder, index);
    node->right = createBinaryTree(preorder, index);

    return node;
}

void freeBinaryTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    delete root;
}

int calculateWPL(TreeNode *root, int depth) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->data * depth;
    }

    int leftWPL = calculateWPL(root->left, depth + 1);
    int rightWPL = calculateWPL(root->right, depth + 1);

    return leftWPL + rightWPL;
}

int main() {
    string preorder = "124###35###";
    int index = 0;

    TreeNode *root = createBinaryTree(preorder, index);

    int wpl = calculateWPL(root, 0);
    cout << "带权路径长度: " << wpl << endl;

    freeBinaryTree(root);

    return 0;
}