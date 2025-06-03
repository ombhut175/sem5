#include<stdio.h>

int factorial (int n)
{
    if(n==1) return n;

    return n * factorial(n-1);
}

void main()
{
    int ans = factorial(5);

    printf("ans = %d",ans);
}


