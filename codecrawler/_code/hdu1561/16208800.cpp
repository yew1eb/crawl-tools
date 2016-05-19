#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int N,M,v[223];
vector<int>son[223];

int dp[223][223];

void dfs(int n,int left){
    int i,j,k,len=son[n].size();
    dp[n][1]=v[n];
    for(i=0;i<len;i++){
        if(left>1)    dfs(son[n][i],left-1);
        for(j=left;j>=1;j--)
            for(k=1;k<=j;k++)
                if(dp[n][j+1]<    dp[n][j+1-k]    +dp[son[n][i]][k])    dp[n][j+1]=dp[n][j+1-k]+dp[son[n][i]][k];
    //                            å¶ä»å¿å­çæ»å¼     ç¬¬iä¸ªå¿å­åkä¸ª
    }
}

int main()
{
    int i,j,k;
    
    while(scanf("%d%d",&N,&M),N||M)
    {
        //
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        for(i=0;i<=N;i++)    son[i].clear();
        //
        for(i=1;i<=N;i++){
            scanf("%d%d",&j,&v[i]);
            son[j].push_back(i);
        }
        
        dfs(0,M+1);
        
        printf("%d\n",dp[0][M+1]);
    }
    return 0;
}
