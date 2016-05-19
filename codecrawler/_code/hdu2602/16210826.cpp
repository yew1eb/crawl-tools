#include"stdio.h"
#include"string.h"

struct A
{
    int val;
    int v;
}E[1011];

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int T;
    int dp[1011];
    int i,l;
    int N,V;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&V);
        for(i=1;i<=N;i++)    scanf("%d",&E[i].val);
        for(i=1;i<=N;i++)    scanf("%d",&E[i].v);

        memset(dp,0,sizeof(dp));
        for(i=1;i<=N;i++)
        for(l=V;l>=E[i].v;l--)
            dp[l]=max(dp[l],dp[l-E[i].v]+E[i].val);

        printf("%d\n",dp[V]);
    }
    return 0;
}