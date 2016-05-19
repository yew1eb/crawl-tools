#include<stdio.h>
int main ()
{
    int n,i;
    while(scanf("%d",&n),n)
    {
        if(n>4)
            printf("%d\n",(2*(n-4)+4)*5);
        else if(n==4||n==3)
            printf("%d\n",n*5);
        else
            printf("%d\n",n*5-5);
    }
    return 0;
}
