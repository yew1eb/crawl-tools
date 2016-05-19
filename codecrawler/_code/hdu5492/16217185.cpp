#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define inf 0x3f3f3f3f
int V[30][30],dp[30][30][1800];
int main()
{
    int ca=1,T,i,j,k,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;++i)
            for(j=0;j<m;++j) scanf("%d",&V[i][j]);
        printf("Case #%d: ",ca++);
        memset(dp,inf,sizeof(dp));
        dp[0][0][V[0][0]]=V[0][0]*V[0][0];
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            {
                if(i+1<n){
                    for(k=0;k<=59*30;++k)
                        if(dp[i][j][k]!=inf)
                            dp[i+1][j][k+V[i+1][j]]=min(dp[i+1][j][k+V[i+1][j]],dp[i][j][k]+V[i+1][j]*V[i+1][j]);
                }
                if(j+1<m){
                    for(k=0;k<=59*30;++k)
                        if(dp[i][j][k]!=inf)
                            dp[i][j+1][k+V[i][j+1]]=min(dp[i][j+1][k+V[i][j+1]],dp[i][j][k]+V[i][j+1]*V[i][j+1]);
                }
            }
        int ans=inf;
        for(i=0;i<=59*30;++i)
            if(dp[n-1][m-1][i]!=inf)
                ans=min(ans,(n+m-1)*dp[n-1][m-1][i]-i*i);
        printf("%d\n",ans);
    }
    return 0;
}