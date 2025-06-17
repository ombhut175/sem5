#include <stdio.h>
#include <stdbool.h>

void insertionSort(int arr[], int n)
{
     for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;   
    }
    
}

void main()
{

    int arr[] = {52, 32, 43, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
}