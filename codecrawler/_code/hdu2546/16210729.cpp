#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
int c[2005];
int dp[2500];
int cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        memset(c,0,sizeof(c));
        int i;
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);
        int m;
        sort(c+1,c+n+1,cmp);
        scanf("%d",&m);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        int max1=c[n];
        m=m-5;
        int j;
        for(i=1;i<n;i++)
        {
            for(j=m;j>=c[i];j--)
            {
                dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
            }
        }
        printf("%d\n",m+5-dp[m]-max1);
    }
    return 0;
}
