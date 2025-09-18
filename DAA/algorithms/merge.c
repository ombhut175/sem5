#include <stdio.h>

void merge(int arr[], int leftIndex, int middleIndex, int rightIndex) {
    int sizeLeft = middleIndex - leftIndex + 1;
    int sizeRight = rightIndex - middleIndex;
    
    int leftArr[50];
    int rightArr[50];
    
    int i, j, k;
    
    for(i = 0; i < sizeLeft; i++) {
        leftArr[i] = arr[leftIndex + i];
    }
    
    for(j = 0; j < sizeRight; j++) {
        rightArr[j] = arr[middleIndex + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = leftIndex;
    
    while(i < sizeLeft && j < sizeRight) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i = i + 1;
        }
        else {
            arr[k] = rightArr[j];
            j = j + 1;
        }
        k = k + 1;
    }
    
    while(i < sizeLeft) {
        arr[k] = leftArr[i];
        i = i + 1;
        k = k + 1;
    }
    
    while(j < sizeRight) {
        arr[k] = rightArr[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(int arr[], int leftIndex, int rightIndex) {
    if(leftIndex < rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        
        mergeSort(arr, leftIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, rightIndex);
        
        merge(arr, leftIndex, middleIndex, rightIndex);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = 6;
    int index;
    
    mergeSort(arr, 0, size - 1);
    
    for(index = 0; index < size; index++) {
        printf("%d ", arr[index]);
    }
    printf("\n");
    
    return 0;
}
