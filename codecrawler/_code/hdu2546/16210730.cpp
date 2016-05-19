#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int cost[1011];
int c1[2000],c2[2000];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n,m,limit;
    int i,l;
    int ans;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)    scanf("%d",&cost[i]);
        qsort(cost,n,sizeof(cost[0]),cmp);
        scanf("%d",&m);

        if(m<5)    {printf("%d\n",m);continue;}

        limit=m-5;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0;i<n;i++)
        {
            for(l=0;l<=limit;l++)    if(c1[l])    c2[l+cost[i]]=1;
            c2[cost[i]]=1;
            for(l=0;l<=1100;l++)    c1[l]=c2[l];
        }

        ans=0;
        for(i=0;i<=1100;i++)    if(c2[i])    ans=i;
        printf("%d\n",m-ans);
    }
    return 0;
}