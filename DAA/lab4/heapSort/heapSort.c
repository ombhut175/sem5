#include<stdio.h>


void heapify(int arr[],int n,int i){
    int largest = i;

    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left<n && arr[left] > arr[largest]) largest = left;

    if(right<n && arr[right] > arr[largest]) largest = right;

    if (i == largest) return;
    
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr,n,largest);
    
}

void heapSort(int arr[], int n){
    
    for (int i = (n/2)-1; i >= 0; i--) heapify(arr,n,i);
    
    for (int i = n-1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
    
}

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void main(){
    int arr[] = {45,23,75,12,3,67};
    int n = 6;

    heapSort(arr,n);
    display(arr,n);
}