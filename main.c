#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int splitList(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    do {
        do {
            i++;
        } while (A[i] <= pivot && i < h);

        do {
            j--;
        } while (A[j] > pivot && i >= l);

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = splitList(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}


int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int *A, n = 30, i;
    A = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        A[i] = generateRandomNumber(0,100);
    
    printArray(A, n);
    
    quickSort(A, 0, n);
    
    printArray(A, n);
    return 0;
}