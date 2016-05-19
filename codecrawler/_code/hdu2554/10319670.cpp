#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        if(n%4==0||(3*n-1)%4==0)
        printf("Y\n");
        else printf("N\n");
    }
    return 0;
}