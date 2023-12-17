#include <iostream>

#include "carrot.h"
using namespace std;

bool isDegenerate(BTNode* root) {
    if (root == NULL) return true;
    if (root->left && root->right) return false;
    return isDegenerate(root->left) && isDegenerate(root->right);
}

int main() {
    BTNode* root = new BTNode{1, new BTNode{2, new BTNode{3, new BTNode{4, new BTNode{5, nullptr}}}}};

    // Test isDegenerate function
    if (isDegenerate(root)) {
        cout << "The tree is degenerate." << endl;
    } else {
        cout << "The tree is not degenerate." << endl;
    }

    return 0;
}
