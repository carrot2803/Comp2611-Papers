#include <iostream>

#include "carrot.h"

BTNode *deleteNodeBST(BTNode *root, int data);

BTNode *minimumBST(BTNode *root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    return minimumBST(root->left);
}

BTNode *findInOrderSuccessorWithParent(BTNode *root) {
    if (root == NULL)
        return NULL;
    else if (root == root->parent->left)
        return root->parent;
    return findInOrderSuccessorWithParent(root->parent);
}

BTNode *inOrderSuccessor(BTNode *root) {
    if (root == NULL)
        return NULL;
    else if (root->right != NULL)
        return minimumBST(root->right);
    return findInOrderSuccessorWithParent(root);
}

BTNode *deleteLeafNode(BTNode *root) {
    delete root;
    return NULL;
}

BTNode *deleteNonTerminalNode(BTNode *root) {
    BTNode *temp = root->left ? root->left : root->right;
    delete root;
    return temp;
}

BTNode *deleteNodeWithTwoChildren(BTNode *root) {
    BTNode *successor = inOrderSuccessor(root);
    root->data = successor->data;
    root->right = deleteNodeBST(root->right, successor->data);
    return root;
}

BTNode *deleteNodeBST(BTNode *root, int data) {
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        root->left = deleteNodeBST(root->left, data);
    else if (data > root->data)
        root->right = deleteNodeBST(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL)
            root = deleteLeafNode(root);
        else if (!root->left ^ !root->right)
            root = deleteNonTerminalNode(root);
        else
            root = deleteNodeWithTwoChildren(root);
    }
    return root;
}

// you could just find minBst use the parent and move around for two cases
BTNode *deleteMinBST(BTNode *root) {
    if (root == NULL) return NULL;
    BTNode *minBST = minimumBST(root);
    root = deleteNodeBST(root, minBST->data);
    return root;
}

int main() {
    BTNode *root = new BTNode{5, nullptr, nullptr};
    root->left = new BTNode{3, nullptr, nullptr};
    root->right = new BTNode{8, nullptr, nullptr};
    root->left->left = new BTNode{2, nullptr, nullptr};
    root->left->right = new BTNode{4, nullptr, nullptr};
    root->right->left = new BTNode{7, nullptr, nullptr};
    root->right->right = new BTNode{9, nullptr, nullptr};

    cout << "Original BST:" << endl;
    inOrder(root);

    root = deleteMinBST(root);

    cout << "\nBST after deleting the minimum value node:" << endl;
    inOrder(root);

    return 0;
}