#include <stdio.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    
    while(i <= j) {
        while(i <= high && a[i] <= pivot) {
            i = i + 1;
        }
        
        while(j >= low && a[j] > pivot) {
            j = j - 1;
        }
        
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    return j;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = 6;
    int i;
    
    quickSort(a, 0, n - 1);
    
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
