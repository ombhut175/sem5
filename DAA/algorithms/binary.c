#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int low=0, high=n-1;
    while(low<=high) {
        int mid= (low+high)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 5, 5, 6, 9}; 
    int n = 6, key = 6;
    int idx = binarySearch(a, n, key);
    if(idx>=0) printf("Found at index %d\n", idx);
    else printf("Not found\n");
}
