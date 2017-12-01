#include"binaryheap.h"

int leftChild(int i){
    return 2*i;
}

int rightChild(int i){
    return 2*i + 1;
}

int parent(int i){
    return i/2;
}


void insert(BinaryHeap* heap, int n){
    int pos = ++heap->n;

    for(; pos > 1 && n < heap->que[parent(pos)]; pos = parent(pos)){
        heap->que[pos] = heap->que[parent(pos)];
    }

    heap->que[pos] = n;
}

void siftDown(BinaryHeap* heap, int i){
    int left;
    int right;
    int smallest = i;
    int sz = heap->n;

    while((left = leftChild(i)) <= sz){
        smallest = heap->que[left] < heap->que[i] ? left : i;
        right = rightChild(i);
        if(right <= sz){
            smallest = heap->que[right] < heap->que[smallest] ? right : smallest;
        }

        if(smallest != i){
            int tmp = heap->que[i];
            heap->que[i] = heap->que[smallest];
            heap->que[smallest] = tmp;
            i = smallest;
        }else{
            break;
        }
    }
}

int extractMin(BinaryHeap* heap){
    int ret = heap->que[1];
    // swap the last one to the root
    heap->que[1] = heap->que[heap->n];
    --heap->n;
    // keep the heap property
    siftDown(heap, 1);

    return ret;
}

void buildHeap(BinaryHeap* heap, int* a, int len){

    heap->n = len;
    for(int i = 0; i < len; ++i) heap->que[i+1] = a[i];

    for(int i = parent(len); i >= 1; --i){
        siftDown(heap, i);
    }
}

void heapSort(BinaryHeap* heap, int a[], int len){
    // build heap
    buildHeap(heap, a, len);

    //printArray(heap, len);

    for(int i = 0; i < len; ++i){
        a[i] = extractMin(heap);
    }
}
