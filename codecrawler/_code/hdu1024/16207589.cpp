#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 999999999
using namespace std;
int a[1000005];
int now[1000005];
int pre[1000005];
int max1(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i;

        memset(a,0,sizeof(a));
        memset(now,0,sizeof(now));
        memset(pre,0,sizeof(pre));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int j;
        long long maxx;
        for(i=1;i<=m;i++)
        {
            maxx=-inf;
            for(j=i;j<=n;j++)
            {
                now[j]=max1(now[j-1],pre[j-1])+a[j];   //pre[j-1]è¡¨ç¤ºmaxï¼dp[i-1][k]ï¼ i-1<=k<=j-1
                pre[j-1]=maxx;
                if(now[j]>maxx)
                    maxx=now[j];
            }
        }
        printf("%I64d\n",maxx);
        
    }
}