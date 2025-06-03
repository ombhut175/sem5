#include<stdio.h>

void main()
{
    int n = 5; //15
    // scanf("%d",&n);

    int sum = 0;

    for(int i = 1 ; i<=n ;i++){
        sum = sum + i;
    }

    printf("sum = %d",sum);
}