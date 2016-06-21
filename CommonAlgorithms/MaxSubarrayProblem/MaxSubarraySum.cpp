#include "msp.h"

int MaxSubarrayProblem_1D(int *arr, int len){
    int currentSum,maxSum,i;
    // record the starting/ending point
    int start,end;

    currentSum = maxSum = 0;
    start = end = 0;

    i = 0;
    for(int j = 0; j < len; ++j){
        currentSum += arr[j];

        if(currentSum > maxSum){
            start = i,end = j;
            maxSum = currentSum;
        }else if(currentSum < 0){
            currentSum = 0;
            i = j + 1;
        }
    }

    return maxSum;
}


