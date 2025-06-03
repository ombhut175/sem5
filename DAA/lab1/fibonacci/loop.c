#include<stdio.h>


void main()
{
    int n = 7; //7

    int first = 0;
    int second = 1;
    
    // int sum = 0;

    for(int i=0 ;i<n;i++){

        printf("first = %d\n",first);
        int temp = first + second;
        // sum = sum +temp;

        first = second;
        second = temp;
    }

    printf("fibonacci = %d",second);
}