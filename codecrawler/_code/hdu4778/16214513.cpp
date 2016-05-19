#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf -2100000000
using namespace std;
int dp[1<<21];
int g,b,s;
int box[21][8],c[8];
int dfs(int flag,int left,int cc[])
{
    if(left==0||flag==0)
    return 0;
    if(dp[flag]!=inf)
    return dp[flag];
    int i,tmp,ans=0,ben;
    int tt[8];
    memset(tt,0,sizeof(tt));
    for(i=b-1;i>=0;i--)
    {
        ben=0;
        if((flag>>i)&1)
        {
            tmp=flag^(1<<i);
            int sum=0;
            for(int j=0;j<g;j++)
            {
                tt[j]=(cc[j]+box[i][j]);
                sum+=tt[j]/s;
                tt[j]%=s;
            }
            if(sum)
            {
                ben=sum+dfs(tmp,left-sum,tt);
            }
            else
            {
                ben=left-dfs(tmp,left,tt);
            }
            ans=max(ans,ben);
        }
    }
    return dp[flag]=ans;
}
int main()
{
   // freopen("dd.txt","r",stdin);
    while(scanf("%d%d%d",&g,&b,&s))
    {
        if(!g)
        break;
        memset(box,0,sizeof(box));
        memset(c,0,sizeof(c));
        for(int i=0;i<b;i++)
        {
            int n,x;
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&x);
                box[i][x-1]++;
                c[x-1]++;
            }
        }
        int sum=0;
        for(int i=0;i<g;i++)
        {
            sum+=c[i]/s;
        }
        int cc[8];
        int limit=(1<<b);
        for(int i=0;i<limit;i++)
        {
            dp[i]=dp[i]=inf;
        }
        memset(cc,0,sizeof(cc));
        int ans=dfs((1<<b)-1,sum,cc);
        printf("%d\n",2*ans-sum);
    }
    return 0;
}





   
