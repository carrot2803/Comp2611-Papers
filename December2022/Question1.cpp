#include <iostream>

#include "carrot.h"
using namespace std;

bool isSortedRec(LLNode* top) {
    if (top == NULL || top->next == NULL)
        return true;
    else if (top->data > top->next->data)
        return false;
    return isSortedRec(top->next);
}

LLNode* reverseList(LLNode* top) {
    Stack* s = initStack();
    LLNode* curr = top;
    while (curr != NULL) {
        push(s, curr->data);
        curr = curr->next;
    }
    curr = top;
    while (curr != NULL) {
        curr->data = pop(s);
        curr = curr->next;
    }
    return top;
}

int main() {
    LLNode* sorted = new LLNode{1, new LLNode{2, new LLNode{3, new LLNode{4, new LLNode{5, NULL}}}}};
    LLNode* unsorted = new LLNode{9, new LLNode{2, new LLNode{7, new LLNode{4, new LLNode{5, NULL}}}}};
    cout << "Is sorted: " << boolalpha << isSortedRec(sorted) << endl;
    cout << "Is sorted: " << boolalpha << isSortedRec(unsorted) << endl;
    cout << "Original List: ";
    printList(sorted);
    LLNode* reversed = reverseList(sorted);
    cout << "\nReversed List: ";
    printList(reversed);
    return 0;
}