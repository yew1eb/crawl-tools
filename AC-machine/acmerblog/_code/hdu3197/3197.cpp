#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define M 100500
vector<int > vec[M];
int vis[M],dp[M],pri[M];
int dfs(int x){
    if(dp[x]!=-1)return dp[x];
    vis[x]=1;
    dp[x]=0;
    for(int i=0;i<vec[x].size();i++){
        if(!vis[vec[x][i]])
        dp[x]^=dfs(vec[x][i])+1;
    }
    return dp[x];
}
int main()
{
    int tcase,n,i,s,e;
    int cnt=0,ans=0,k;
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(i=0;i<=n;i++)vec[i].clear();
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
       for(i=0;i<n;i++){
            scanf("%d",&pri[i]);
            if(pri[i]!=-1){
                vec[pri[i]].push_back(i);
                vec[i].push_back(pri[i]);
            }
        }
        for(i=0;i<n;i++)
        if(pri[i]==-1){
            k=dfs(i);
            ans^=k;
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}