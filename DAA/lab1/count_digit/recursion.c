#include<stdio.h>

int count (int n)
{
    if(n<=0) return n;

    return 1 + count(n/10);
}

void main()
{
    // int n = 512;
    // scanf("%d",&n);

    int ans = count(123);

    printf("count = %d",ans);
    
}
