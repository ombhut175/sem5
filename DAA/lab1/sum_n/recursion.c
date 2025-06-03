#include<stdio.h>

int sum(int n)
{
    if(n<=0) return 0;

    return n + sum(n-1);
}

void main()
{
    int n = 6; //15
    // scanf("%d",&n);

    int ans = sum(n);
    printf("ans = %d",ans);
}