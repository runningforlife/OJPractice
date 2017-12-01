#include<stdio.h>
/**
* Binary heap
* operation
*    - insert
     - extractMin
     - buildHeap
     - siftDown

* NOTE: this heap index is started from 1
* so given parent i, its child is 2*i, 2*i+1
* given it child i, it parent is i/2
*/

const int MAX_HEAP_SIZE = 1000;

struct BinaryHeap{
    int n;
    int que[MAX_HEAP_SIZE];

    BinaryHeap(){
        n = 0;
    }
};


// usage function
/**
* insert a item to the heap
* @BinaryHeap heap the heap to insert
* @int n the item to be inserted
*/
void insert(BinaryHeap* heap, int n);

/**
* sift down  from the starting index i to end index end to keep heap property
* 1) find the minimum between children & parent
* 2) if the minimum is not the parent, swap them and
* 3) continue the process till the heap property is kept
*/
void siftDown(BinaryHeap* heap, int start);

/**
* extract a minimum from the heap based on starting index i
* 1) take 1st item as the return value
* 2) swap the last one to the 1st
* 3) sift down to keep heap property
*/
int extractMin(BinaryHeap* heap);

/**
* build a binary heap given a int array
* 1) assign the array item to heap
* 2) sift down for all the parent nodes
*/
void buildHeap(BinaryHeap* heap, int a[], int len);

/**
* sorting an array based on binary heap
* 1) build a heap
* 2) keep extract minimum from the heap
*/
void heapSort(BinaryHeap* heap, int a[], int len);
