#include <iostream>
using namespace std;

struct MaxHeap {
    int A[1000];
    int size;
};

MaxHeap *initMaxHeap() {
    MaxHeap *heap = new MaxHeap;
    heap->size = 0;
    return heap;
}

void maxHeapify(MaxHeap *heap, int i) {
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= heap->size && heap->A[left] > heap->A[largest])
        largest = left;
    if (right <= heap->size && heap->A[right] > heap->A[largest])
        largest = right;

    if (largest != i) {
        int temp = heap->A[i];
        heap->A[i] = heap->A[largest];
        heap->A[largest] = temp;
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(MaxHeap *heap) {
    for (int i = heap->size / 2; i >= 1; i--)
        maxHeapify(heap, i);
}

MaxHeap *makeHeap(int arr[], int n) {
    MaxHeap *heap = initMaxHeap();
    for (int i = 0; i < n; i++)
        heap->A[i + 1] = arr[i];
    heap->size = n;
    buildMaxHeap(heap);
    return heap;
}

int main() {
    int arr[] = {53, 36, 25, 47, 61, 32, 75, 59};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    MaxHeap *heap = makeHeap(arr, n);

    cout << "Heap: ";
    for (int i = 1; i <= heap->size; i++) {
        cout << heap->A[i] << " ";
    }

    return 0;
}
