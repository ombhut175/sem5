#include<stdio.h>
#include <time.h>


void binarySearch(int arr[],int target ,int n){
    int start = 0;
    int end = n;

    while (start <= end)
    {
        int mid = (start + end)/2;
        if (arr[mid] == target)
        {
            printf("Founded at index %d\n",mid);
            return; 
        }
        
        if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;  
    }
    
    printf("Element not found\n");
}

void checkTimeComplexity(){
    int n = 100000;
    int arr[n];
    clock_t start,end;
    FILE *file;

    file = fopen("./output/best_case.txt","r");

    for (int i = 0; i < n; i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    
    fclose(file);

    printf("best case scenerio\n");

    start = clock();
    binarySearch(arr,50,n);
    end = clock();

    
    printf("Time taken to search in the array : %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(file);

}

int binarySearchRecursionHelper(int arr[],int target,int start,int end){
    
        int mid = (start + end)/2;
        if (arr[mid] == target)
        {
            return mid; 
        }
        
        if (arr[mid] < target) binarySearchRecursionHelper(arr,target,mid+1,end);
        else binarySearchRecursionHelper(arr,target,start,mid - 1);
}

int binarySearchRecursion(int arr[],int target,int n){
    binarySearchRecursionHelper(arr,target,0,n);
}

void main(){
    int arr[] = {1,2,4,5,45,67,73};
    int n = sizeof(arr) / sizeof(arr[0]);
    // checkTimeComplexity();
    printf("element founded at index %d",binarySearchRecursion(arr,1,n));
}