#include <iostream>
using namespace std;

struct MinHeap {
    int A[1000];
    int size;
};

void miniHeapify(MinHeap* heap, int i) {
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
        miniHeapify(heap, smallest);
    }
}

int main() {
    MinHeap* heap = new MinHeap();
    heap->size = 7;
    heap->A[1] = 4;
    heap->A[2] = 10;
    heap->A[3] = 3;
    heap->A[4] = 5;
    heap->A[5] = 1;
    heap->A[6] = 7;
    heap->A[7] = 8;

    cout << "Original Min Heap:" << endl;
    for (int i = 1; i <= heap->size; ++i) {
        cout << heap->A[i] << " ";
    }
    cout << endl;

    miniHeapify(heap, 1);

    cout << "Min Heap after heapify:" << endl;
    for (int i = 1; i <= heap->size; ++i) {
        cout << heap->A[i] << " ";
    }
    cout << endl;

    return 0;
}
