#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSwapped = true;
            }
        }

        if (!isSwapped)
        {
            break;
        }
    }
}


void checkTimeComplexity(){
    int n = 100000;
    int arr[n];
    clock_t start,end;
    FILE *file;
    file = fopen("./output/worst_case.txt","r");

    for (int i = 0; i < n; i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    
    fclose(file);

    printf("worst case scenerio\n");

    start = clock();
    bubbleSort(arr, n);
    end = clock();
    
    printf("Time taken to sort the array : %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);


    file = fopen("./output/best_case.txt","r");

    for (int i = 0; i < n; i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    
    fclose(file);

    printf("best case scenerio\n");

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    
    printf("Time taken to sort the array : %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(file);

    file = fopen("./output/average_case.txt","r");

    for (int i = 0; i < n; i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    
    fclose(file);

    printf("average case scenerio\n");

    start = clock();
    bubbleSort(arr, n);
    end = clock();
    
    printf("Time taken to sort the array : %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void main()
{
    // createFiles();
    int arr[] = {52, 32, 43, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    checkTimeComplexity();
}