#include<stdio.h>

void main()
{
    int x = 2;
    int y = 3;

    int ans = 1;

    for (int i = 1 ; i<=y ;i++)
    {
        ans = ans*x;
    }

    printf("%d",ans);
}