#include <iostream>

#include "carrot.h"
using namespace std;

void bstToArr(BTNode* root, int arr[], int& i) {
    if (root == NULL) return;
    bstToArr(root, arr, i);
    arr[i++] = root->data;
    bstToArr(root, arr, i);
}

void sort(int arr[], int lengthA) {
    BTNode* root = NULL;
    for (int i = 0; i < lengthA; i++)
        root = insertBSTRec(root, arr[i]);
    bstToArr(root, arr, 0);
}