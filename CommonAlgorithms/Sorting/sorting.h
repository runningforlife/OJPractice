/**
* merge sorting
* NOTE: high is inclusive
*/
void mergeSort(int a[], int low,int high);

/**
* merge two sorted array
* NOTE: high is inclusive
*/
void merge(int a[], int low, int mid, int high);


/**
* quick sorting
* NOTE: high is inclusive
*/
void quickSort(int a[], int low, int high);

/**
* partition the array such that all the items at the left of pivot is less than pivot
* and all the items at the right is larger than pivot
* NOTE: high is inclusive
*/
int partition(int a[], int low, int high);
