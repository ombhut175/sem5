#include<stdio.h>

int fibonacci (int n)
{

    if(n<=1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

void main()
{
    int ans = fibonacci(7); // 7

    printf("ans = %d",ans);
}