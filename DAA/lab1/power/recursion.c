#include<stdio.h>

int power(int x, int y)
{
    if(y<=0) return 1;

    return x * power(x,y-1);
}

void main()
{
    int x = 2;
    int y = 3;

    int ans = power(x,y);

    printf("%d",ans);
}