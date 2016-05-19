#include <stdio.h>
#include <string.h>
int w[105];
int num[105];
int m;
int dp[100005];
int max(int a,int b)
{
    return a>b?a:b;
}
void ZeroOnePack(int v,int c)
{
    int i;
    for(i=m;i>=c;i--)
        dp[i]=max(dp[i],dp[i-c]+v);
}
void CompletePack(int v,int c)
{
    int i;
    for(i=c;i<=m;i++)
        dp[i]=max(dp[i],dp[i-c]+v);
}
int main()
{
    int n;
    while(scanf("%d%d",&n,&m),n+m)
    {
        int i;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        for(i=1;i<=n;i++)
        {
            if(num[i]*w[i]>m)
                CompletePack(w[i],w[i]);
            else
            {
                int k=1;
                while(k<=num[i])
                {
                    ZeroOnePack(k*w[i],k*w[i]);
                    num[i]=num[i]-k;
                    k=k<<1;
                }
                ZeroOnePack(num[i]*w[i],num[i]*w[i]);
            }
        }
        int s=0;
        for(i=1;i<=m;i++)
        {
            if(dp[i]==i)
                s++;
        }
        printf("%d\n",s);
    }
    return 0;
}