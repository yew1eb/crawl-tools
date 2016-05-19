#include<stdio.h>
int  work(int x, int size)
{
     int tot = 0;
     while(x>0)
     {
         tot+=x% size;
         x/=size;
     }
     return tot;
}

int main()
{
    int x;
    while(scanf("%d",&x), x)
    {
        if(work(x,10)==work(x,16)&& work(x,10)==work(x,12))
        printf("%d is a Sky Number.\n",x);
        else printf("%d is not a Sky Number.\n",x);
    }
    return 0;
}
