#include <iostream>
using namespace std;

const int n = 100;

struct LLNode {
    int key;
    int count;
    LLNode* next;
};

struct HashTable {
    LLNode* elements[n + 1];
};

HashTable* initHashTable() {
    HashTable* ht = new HashTable;
    for (int i = 1; i <= n; i++)  // Start from 0 instead of 1
        ht->elements[i] = NULL;
    return ht;
}

bool containsLL(LLNode* top, int k) {
    if (top == NULL)
        return false;
    else if (top->key == k)
        return true;
    return containsLL(top->next, k);
}

LLNode* deleteNode(LLNode* top, int n) {
    if (top == NULL) {
        return NULL;
    } else if (top->key == n) {
        LLNode* temp = top->next;
        delete top;
        return temp;
    }
    top->next = deleteNode(top->next, n);
    return top;
}

LLNode* insertAtHead(LLNode* top, int k) {
    LLNode* newNode = new LLNode;
    newNode->count = 0;
    newNode->key = k;
    newNode->next = top;
    return newNode;
}

LLNode* searchHashTable(HashTable* ht, int k) {
    int index = (k % n) + 1;
    LLNode* top = ht->elements[index];
    if (containsLL(top, k)) {
        top->count++;
    } else if (top == NULL || top->count >= 10) {
        top = deleteNode(top, k);
        top = insertAtHead(top, k);
    } else {
        top = insertAtHead(top, k);
    }
    ht->elements[index] = top;
    return top;
}

int main() {
    HashTable* ht = initHashTable();
    int keys[] = {5, 5, 5, 35, 45, 55, 65, 75, 85, 95};

    for (int i = 0; i < 10; i++) {
        searchHashTable(ht, keys[i]);
    }

    for (int i = 1; i <= n; i++) {
        LLNode* current = ht->elements[i];
        while (current != NULL) {
            cout << "Key: " << current->key << ", Count: " << current->count << endl;
            current = current->next;
        }
    }

    return 0;
}
