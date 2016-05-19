#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node
{
    int h,m;
    double r;
}clock[10000];

int cmp(Node x,Node y)
{
    if(x.r!=y.r)
    return x.r<y.r;
    return x.h<y.h;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        for(i = 0;i<5;i++)
        {
            scanf("%d:%d",&clock[i].h,&clock[i].m);
            if(clock[i].h>12)
            clock[i].r = fabs(30.0*(clock[i].h-12)+clock[i].m/2.0-6.0*clock[i].m);
            else
            clock[i].r = fabs(30.0*clock[i].h+clock[i].m/2.0-6.0*clock[i].m);
            if(clock[i].r>180)
            clock[i].r = 360-clock[i].r;
        }
        sort(clock,clock+5,cmp);
        printf("%02d:%02d\n",clock[2].h,clock[2].m);
    }

    return 0;
}
