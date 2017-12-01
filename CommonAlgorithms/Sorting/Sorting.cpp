#include"sorting.h"

void merge(int a[], int low, int mid, int high){
    int* buf1 = new int[mid - low + 1];
    int* buf2 = new int[high - mid + 1];

    int sz1 = 0, sz2 = 0;

    while(sz1 < mid - low + 1) buf1[sz1] = a[low + sz1], ++sz1;
    while(sz2 < high - mid + 1) buf2[sz2] = a[mid + sz2 + 1], ++sz2;

    int idx1 = 0, idx2 = 0;
    int idx = low;

    while(idx1 < sz1 && idx2 < sz2){
        if(buf1[idx1] <= buf2[idx2]){
            a[idx++] = buf1[idx1];
            ++idx1;
        }else{
            a[idx++] = buf2[idx2];
            ++idx2;
        }
    }

    // still have remaining items?
    while(idx1 < sz1) a[idx++] = buf1[idx1++];
    while(idx2 < sz2) a[idx++] = buf2[idx2++];
}


void mergeSort(int a[], int low, int high){
    int mid;

    if(high > low){
        mid = (high + low)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}


int partition(int a[], int low, int high){
    int ret = low; /* return index of pivot */
    int p = high; /* choose the last one as pivot */

    for(int i = low; i < high; ++i){
        if(a[i] < a[p]){
            int tmp = a[i];
            a[i] = a[ret];
            a[ret] = tmp;
            ++ret;
        }
    }

    int tmp = a[ret];
    a[ret] = a[p];
    a[p] = tmp;

    return ret;
}

void quickSort(int a[], int low, int high){
    if(high > low){
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
