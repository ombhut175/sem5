#include<stdio.h>

void main()
{
    int n = 512;
    // scanf("%d",&n);

    int count = 0;

    while (n > 0)
    {
        count++;
        n/=10;
        // printf("n = %d",n);
    }

    printf("count = %d",count);
    
}