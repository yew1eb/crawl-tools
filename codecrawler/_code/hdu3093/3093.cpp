#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define Maxn 4000
using namespace std;
int v[Maxn],dp[10100],ans,Min,Sum;
int main()
{
    int t,n,m,i,j,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        Sum=0;
        Min=0x7fffffff;
        for(i=1;i<=n;i++)
        {
            scanf("%d",v+i);
            Min=min(Min,v[i]);
            Sum+=v[i];
        }
        ans=0;
        int sum=0,f=0,k;
        sort(v+1,v+1+n);
        for(i=1;i<=n;i++)
        {
            memset(dp,0,sizeof(dp));
            dp[sum]=1;
            for(j=i+1;j<=n;j++)
            for(k=m;k>=sum+v[j];k--)
                dp[k]=dp[k]+dp[k-v[j]];
            for(j=m;j>=m-v[i]+1;j--)
            if(j>=sum) ans+=dp[j];
            sum+=v[i];
        }
        if(Sum<=m)
            printf("%d 1\n",++Case);
        else
            if(Min>m)
            printf("%d 0\n",++Case);
        else
        printf("%d %d\n",++Case,ans);
    }
    return 0;
}