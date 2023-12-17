#include <iostream>
using namespace std;

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isFullBT(BTNode* bt) {
    if (bt == NULL)
        return true;
    else if ((bt->left == NULL) ^ (bt->right == NULL))
        return false;
    return isFullBT(bt->left) && isFullBT(bt->right);
}

int main() {
    BTNode* root = new BTNode(1);
    root->left = new BTNode(2);
    root->right = new BTNode(3);
    root->left->left = new BTNode(4);
    root->left->right = new BTNode(5);
    root->right->left = new BTNode(6);
    root->right->right = new BTNode(7);

    if (isFullBT(root))
        cout << "The binary tree is a full binary tree." << endl;
    else
        cout << "The binary tree is not a full binary tree." << endl;

    return 0;
}
