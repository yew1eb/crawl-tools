#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n,m;
int i,l;
struct A
{
    int val,len,limit;
}E[33];
int dp[2011];
int MAX(int a,int b){
    return a>b?a:b;
}
int cmp(const void *a,const void *b)
{
    A *c,*d;
    c=(A *)a;
    d=(A *)b;
    return c->limit-d->limit;
}
int main()
{
    int i,l;
    int ans;
    while(scanf("%d",&n),n>=0)
    {
        m=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&E[i].val,&E[i].len,&E[i].limit);
            if(E[i].limit>m)    m=E[i].limit;
        }
        qsort(E,n,sizeof(E[0]),cmp);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        for(l=E[i].limit;l>=E[i].len;l--)
            dp[l]=MAX(dp[l],dp[l-E[i].len]+E[i].val);
        ans=0;
        for(l=0;l<=m;l++)    if(dp[l]>ans)    ans=dp[l];
        printf("%d\n",ans);
    }
    return 0;
}