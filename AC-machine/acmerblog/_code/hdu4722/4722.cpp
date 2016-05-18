#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define LL  __int64
const int MAXN = 111;


LL dp[MAXN][11]={0};///注意这里的范围,注意这里的dp[i][j]，i表示位，表示最低位是第i位，
///然后该位上可以放0-9这十种情况下的数目
int dig[MAXN]={0};
LL dfs(int p,int m,bool flag)
{
    if(p==0)return (m==0);
    if(flag&&dp[p][m]!=-1)return dp[p][m];
    int len=flag?9:dig[p];

    LL res=0;
    for(int i=0;i<=len;++i)
    {
        res+=dfs(p-1,(m+i)%10,flag||i!=len);
    }
    if(flag) dp[p][m]=res;
    return res;
}


LL get(LL x)
{
    if(x<0)return 0;
    //memset(dig,0,sizeof(dig));

    int tot=0;
    while(x!=0)
    {
        dig[++tot]=x%10;
        x/=10;
    }
    return dfs(tot,0,0);
}

int main()
{
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    int cas=1;
    while(t--)
    {
        LL x,y;
        cin>>x>>y;
         printf("Case #%d: %I64d\n",cas++,get(y)-get(x-1));
       // cout<<"Case #"<<cas++<<": "<<get(y)-get(x-1)<<endl;
        // printf("Case #%d: %I64d\n",cas++,get(y)-get(x-1));
    }
    return 0;
}
