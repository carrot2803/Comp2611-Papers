#ifndef CARROT_H
#define CARROT_H

#include <stdlib.h>

#include <algorithm>
#include <iostream>

using namespace std;

/*
Linked List, Stacks, Queues 20-140
BSTs 150-280
MaxHeaps 292-420
Priority Queues 424-465
*/

struct LLNode {
    int data;
    LLNode *next;
};

struct Stack {
    LLNode *top;
};

struct Queue {
    LLNode *front;
    LLNode *rear;
};

LLNode *createLLNode(int n);
LLNode *insertAtHead(LLNode *top, int n);
LLNode *insertAtTail(LLNode *top, int n);
LLNode *deleteAtHead(LLNode *top);
Stack *initStack();
void printList(LLNode *top);
bool isEmptyStack(Stack *s);
int peek(Stack *s);
int pop(Stack *s);
void push(Stack *s, int n);
Queue *initQueue();
bool isEmptyQueue(Queue *q);
int peek(Queue *q);
int dequeue(Queue *q);
void enqueue(Queue *q, int n);

LLNode *createLLNode(int n) {
    LLNode *newNode = (LLNode *)malloc(sizeof(LLNode));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

LLNode *insertAtHead(LLNode *top, int n) {
    LLNode *newNode = createLLNode(n);
    return (top == NULL) ? newNode : (newNode->next = top, top = newNode);
}

LLNode *deleteAtHead(LLNode *top) {
    if (top == NULL) return NULL;
    LLNode *temp = top->next;
    free(top);
    return temp;
}

LLNode *getLast(LLNode *top) {
    if (top == NULL) return NULL;
    LLNode *current = top;
    while (current->next != NULL) current = current->next;
    return current;
}

LLNode *insertAtTail(LLNode *top, int n) {
    return (getLast(top) == NULL) ? createLLNode(n) : getLast(top)->next = createLLNode(n);
}

void printList(LLNode *top) {
    if (top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmptyStack(Stack *s) {
    return s->top == NULL;
}

int peek(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "The stack is empty\n";
        return -999;
    }
    return s->top->data;
}

int pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "The stack is empty\n";
        return -999;
    }
    int n = s->top->data;
    s->top = deleteAtHead(s->top);
    return n;
}

void push(Stack *s, int n) {
    s->top = insertAtHead(s->top, n);
}

Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

int peek(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Queue is empty\n";
        return -999;
    }
    return q->front->data;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Queue is empty\n";
        return -999;
    }
    int n = q->front->data;
    q->front = deleteAtHead(q->front);
    return n;
}

void enqueue(Queue *q, int n) {
    LLNode *newNode = createLLNode(n);
    isEmptyQueue(q) ? q->front = newNode : q->rear->next = newNode;
    q->rear = newNode;
}

// Binary Trees
struct BTNode {
    int data;
    BTNode *left;
    BTNode *right;
    BTNode *parent;
};

BTNode *createBTNode(int data);
void preOrder(BTNode *root);
void inOrder(BTNode *root);
void postOrder(BTNode *root);

int moment(BTNode *root);
int numOneChild(BTNode *root);
int numNonTerminal(BTNode *root);
int maximumBT(BTNode *root);
int nodeDepth(BTNode *node);

BTNode *insertBSTRec(BTNode *root, int data);

BTNode *createBTNode(int data) {
    BTNode *newNode;
    newNode = new BTNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void preOrder(BTNode *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BTNode *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BTNode *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int moment(BTNode *root) {
    if (root == NULL) return 0;
    return (1 + moment(root->left) + moment(root->right));
}

int numOneChild(BTNode *root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 0;

    if (root->left == NULL)
        return 1 + numOneChild(root->right);
    else if (root->right == NULL)
        return 1 + numOneChild(root->left);
    else
        return (numOneChild(root->left) + numOneChild(root->right));
}

int numNonTerminal(BTNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    return (1 + numNonTerminal(root->left) + numNonTerminal(root->right));
}

int maximumBT(BTNode *root) {
    int max, maxLeft, maxRight;

    if (root == NULL) return INT8_MIN;

    maxLeft = maximumBT(root->left);
    maxRight = maximumBT(root->right);

    if (maxLeft > maxRight)
        max = maxLeft;
    else
        max = maxRight;

    if (max > root->data)
        return max;
    else
        return root->data;
}

int nodeDepth(BTNode *node) {
    if (node == NULL) return -1;
    int depth = 0;
    while (node->parent != NULL) {
        depth++;
        node = node->parent;
    }
    return depth;
}

BTNode *insertBSTRec(BTNode *root, int data) {
    if (root == NULL) return createBTNode(data);
    if (data < root->data) {
        root->left = insertBSTRec(root->left, data);
        root->left->parent = root;
    } else {
        root->right = insertBSTRec(root->right, data);
        root->right->parent = root;
    }
    return root;
}

// Max Heaps
struct MaxHeap {
    int A[10000];
    int size;
};

MaxHeap *initMaxHeap();
MaxHeap *initMaxHeapFromArray(int A[], int numElements);
void displayMaxHeap(MaxHeap *heap);
int sizeMaxHeap(MaxHeap *heap);
bool isEmptyMaxHeap(MaxHeap *heap);
bool maxHeapPropertyHolds(MaxHeap *heap, int i);
bool isMaxHeap(MaxHeap *heap);

void maxHeapify(MaxHeap *heap, int i);
int maximum(MaxHeap *heap);
int deleteMaxHeap(MaxHeap *heap, int i);
void insertMaxHeap(MaxHeap *heap, int data);
void buildMaxHeap(MaxHeap *heap);
void deleteAllMaxHeap(MaxHeap *heap);
void heapSort(int A[], int numElements);

MaxHeap *initMaxHeap() {
    MaxHeap *heap = new MaxHeap;
    heap->size = 0;
    return heap;
}

MaxHeap *initMaxHeapFromArray(int A[], int numElements) {
    MaxHeap *heap = new MaxHeap;
    for (int i = 0; i < numElements; i++)
        heap->A[i + 1] = A[i];
    heap->size = numElements;
    return heap;
}

void displayMaxHeap(MaxHeap *heap) {
    for (int i = 1; i <= heap->size; i = i + 1)
        cout << heap->A[i] << " ";
    cout << endl;
}

int sizeMaxHeap(MaxHeap *heap) {
    return heap->size;
}

bool isEmptyMaxHeap(MaxHeap *heap) {
    return (heap->size == 0);
}

bool maxHeapPropertyHolds(MaxHeap *heap, int i) {
    if (i < 1 || i > heap->size) return false;
    if (i == 1) return true;
    int parent = i / 2;
    return (heap->A[parent] >= heap->A[i]);
}

bool isMaxHeap(MaxHeap *heap) {
    int heapSize = heap->size;
    for (int i = 2; i <= heapSize; i++)
        if (!maxHeapPropertyHolds(heap, i))
            return false;
    return true;
}

void maxHeapify(MaxHeap *heap, int i) {
    int left, right, largest;

    left = i * 2;
    right = i * 2 + 1;

    if (left <= heap->size && heap->A[left] > heap->A[i])
        largest = left;
    else
        largest = i;

    if (right <= heap->size && heap->A[right] > heap->A[largest])
        largest = right;

    if (largest != i) {
        int temp = heap->A[i];
        heap->A[i] = heap->A[largest];
        heap->A[largest] = temp;
        maxHeapify(heap, largest);
    }
}

int maximum(MaxHeap *heap) {
    return heap->A[1];
}

int deleteMaxHeap(MaxHeap *heap, int i) {
    int toDelete = heap->A[i];
    heap->A[i] = heap->A[heap->size];
    heap->size = heap->size - 1;
    maxHeapify(heap, i);
    return toDelete;
}

void insertMaxHeap(MaxHeap *heap, int data) {
    heap->size = heap->size + 1;
    heap->A[heap->size] = data;

    int i = heap->size;

    while (i > 1 && heap->A[i / 2] < heap->A[i]) {
        int temp = heap->A[i / 2];
        heap->A[i / 2] = heap->A[i];
        heap->A[i] = temp;
        i = i / 2;
    }
}

void buildMaxHeap(MaxHeap *heap) {
    for (int i = (heap->size / 2); i >= 1; i--)
        maxHeapify(heap, i);
}

void deleteAllMaxHeap(MaxHeap *heap) {
    int size = heap->size;
    for (int i = size; i >= 1; i--)
        heap->A[i] = deleteMaxHeap(heap, 1);
}

void heapSort(int A[], int numElements) {
    MaxHeap *heap = initMaxHeapFromArray(A, numElements);
    buildMaxHeap(heap);
    deleteAllMaxHeap(heap);
    for (int i = 1; i <= numElements; i++)
        A[i - 1] = heap->A[i];
}

// Priority Queues
struct MaxPriorityQueue {
    MaxHeap *heap;
};

MaxPriorityQueue *initMaxPQ(int A[], int numElements);
int maximumPQ(MaxPriorityQueue *maxPQ);
int extractMaximumPQ(MaxPriorityQueue *maxPQ);
void insertMaxPQ(MaxPriorityQueue *maxPQ, int priority);
void increasePriority(MaxPriorityQueue *maxPQ, int i, int newPriority);
void displayMaxPQ(MaxPriorityQueue *maxPQ);

MaxPriorityQueue *initMaxPQ(int A[], int numElements) {
    MaxPriorityQueue *mpq = new MaxPriorityQueue;
    mpq->heap = initMaxHeapFromArray(A, numElements);
    return mpq;
}

int maximumPQ(MaxPriorityQueue *maxPQ) {
    if (isEmptyMaxHeap(maxPQ->heap)) return -1;
    return maxPQ->heap->A[1];
}

int extractMaximumPQ(MaxPriorityQueue *maxPQ) {
    if (isEmptyMaxHeap(maxPQ->heap)) return -1;
    int n = deleteMaxHeap(maxPQ->heap, 1);
    return n;
}

void insertMaxPQ(MaxPriorityQueue *maxPQ, int priority) {
    insertMaxHeap(maxPQ->heap, priority);
}

void increasePriority(MaxPriorityQueue *maxPQ, int i, int newPriority) {
    if (i > maxPQ->heap->size || maxPQ->heap->A[i] >= newPriority)
        return;
    maxPQ->heap->A[i] = newPriority;
    maxHeapify(maxPQ->heap, i);
}

void displayMaxPQ(MaxPriorityQueue *maxPQ) {
    displayMaxHeap(maxPQ->heap);
}

#endif