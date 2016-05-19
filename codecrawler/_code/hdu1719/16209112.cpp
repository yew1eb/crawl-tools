#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        if(n==0)        {printf("NO!\n");continue;}
        if(n==1 || n==2){printf("YES!\n");continue;}

        n++;
        while(!(n%2))    n/=2;
        while(!(n%3))    n/=3;
        if(n==1)    printf("YES!\n");
        else        printf("NO!\n");
    }
    return 0;
}