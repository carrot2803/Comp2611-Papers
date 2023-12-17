#include <iostream>
using namespace std;

const int n = 10;

struct LLNode {
    int data;
    LLNode* next;
};

struct HashTable {
    int top;
    LLNode* elements[n + 1];
};

LLNode* createNode(int n) {
    LLNode* newNode = new LLNode;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

LLNode* insertInOrder(LLNode* top, int n) {
    if (top == NULL || top->data >= n) {
        LLNode* newNode = createNode(n);
        newNode->next = top;
        return newNode;
    }
    top->next = insertInOrder(top->next, n);
    return top;
}

int h1(int key) {
    return (key % n) + 1;
}

int h2(int key) {
    return (key % (n - 2)) + 1;
}

bool searchAndInsert(HashTable* ht, int key) {
    int hash = h1(key);
    int offset = h2(key);

    int i = hash;
    while (ht->elements[i] != NULL && ht->elements[i]->data != key)
        i = (i + offset) % n;

    if (ht->elements[i] != NULL && ht->elements[i]->data == key)
        return true;

    ht->elements[i] = insertInOrder(ht->elements[i], key);

    if (ht->top == -1 || key < ht->elements[ht->top]->data)
        ht->top = i;
    return false;
}

void printHashTable(const HashTable* ht) {
    for (int i = 0; i < n; ++i) {
        cout << "Bucket " << i << ": ";
        LLNode* current = ht->elements[i];
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    HashTable* ht = new HashTable{};
    ht->top = -1;

    int keys[] = {12, 22, 42, 7, 19, 32, 87, 54};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; ++i) {
        searchAndInsert(ht, keys[i]);
    }

    printHashTable(ht);

    int searchKey = 19;
    if (searchAndInsert(ht, searchKey))
        cout << "Key " << searchKey << " found in the hash table." << endl;
    else
        cout << "Key " << searchKey << " not found in the hash table." << endl;

    printHashTable(ht);

    return 0;
}
