#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if(min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main() {
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = 6;
    int i;
    
    selectionSort(a, n);
    
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
