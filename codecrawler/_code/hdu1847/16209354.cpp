#include"stdio.h"
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        if(n%3==0)    printf("Cici\n");
        else        printf("Kiki\n");
    }
    return 0;
}