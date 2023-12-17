#include <iostream>

#include "carrot.h"
using namespace std;

BTNode* containsBST(BTNode* root, int n) {
    if (root == NULL)
        return NULL;
    else if (root->data == n)
        return root;
    else if (n < root->data)
        return containsBST(root->left, n);
    return containsBST(root->right, n);
}

void setParent(BTNode* child, BTNode* parent) {
    if (child != NULL) child->parent = parent;
}

BTNode* insertBST(BTNode* root, int n) {
    if (root == NULL) {
        return createBTNode(n);
    } else if (root->data >= n) {
        root->left = insertBST(root->left, n);
        setParent(root->left, root);
    } else if (root->data < n) {
        root->right = insertBST(root->right, n);
        setParent(root->right, root);
    }
    return root;
}

BTNode* searchKey(BTNode* root, int key) {
    BTNode* node = containsBST(root, key);
    if (node != NULL) return node;
    root = insertBST(root, key);
    return root;
}

int main() {
    // Creating a BST
    BTNode* root = nullptr;
    root = insertBST(root, 10);
    insertBST(root, 5);
    insertBST(root, 15);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 12);
    insertBST(root, 18);

    // Testing containsBST function
    int searchValue = 1;
    BTNode* searchResult = searchKey(root, searchValue);

    if (searchResult->data == searchValue) {
        cout << "BST contains " << searchValue << endl;
    } else {
        cout << "BST did not contain " << searchValue << " so it was added" << endl;
    }

    return 0;
}
