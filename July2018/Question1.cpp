#include <iostream>
using namespace std;

struct MinHeap {
    int A[1000];
    int size;
};

MinHeap *initMinHeap() {
    MinHeap *heap = new MinHeap;
    heap->size = 0;
    return heap;
}

void minHeapify(MinHeap *heap, int i) {
    int smallest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= heap->size && heap->A[left] < heap->A[smallest])
        smallest = left;
    if (right <= heap->size && heap->A[right] < heap->A[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap->A[i];
        heap->A[i] = heap->A[smallest];
        heap->A[smallest] = temp;
        minHeapify(heap, smallest);
    }
}

int deleteMinHeap(MinHeap *heap, int i) {
    int toDelete = heap->A[i];
    heap->A[i] = heap->A[heap->size];
    heap->size = heap->size - 1;
    minHeapify(heap, i);
    return toDelete;
}

void buildMinHeap(MinHeap *heap) {
    for (int i = heap->size / 2; i >= 1; i--)
        minHeapify(heap, i);
}

MinHeap *makeHeap(int arr[], int n) {
    MinHeap *heap = initMinHeap();
    for (int i = 0; i < n; i++)
        heap->A[i + 1] = arr[i];
    heap->size = n;
    buildMinHeap(heap);
    return heap;
}

void deleteAllMinHeap(MinHeap *heap) {
    for (int i = heap->size; i >= 1; i--)
        heap->A[i] = deleteMinHeap(heap, 1);
}

void *heapSort(int arr[], int n) {
    MinHeap *heap = makeHeap(arr, n);
    deleteAllMinHeap(heap);
    for (int i = 0; i < n; i++)
        arr[i] = heap->A[i + 1];
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}