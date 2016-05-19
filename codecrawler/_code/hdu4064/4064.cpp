#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
#define MOD  1000000007
#define MAX 531443
int dp[13][MAX];
char st[13][13][6];
bool same[13][13];
int n,m,Max,cur,row;

int change(char x)
{
    if (x=='R') return 1;
    if (x=='F') return 2;
    return 0;
}

void dfs(int col,ll sum,char prechar,int pre,int now)
{
    if(col==m)
    {
        if(row==0) dp[row][now]=(dp[row][now]+sum)%MOD;
        else dp[row][now]=(dp[row][now]+sum*dp[row-1][pre])%MOD;
        return;
    }
    if(same[row][col]) // 判断该处是四个边否相同，如果相同直接dfs 一次即可 
    {
        if(prechar=='#'||prechar==st[row][col][0])
           dfs(col+1,sum*4%MOD,st[row][col][0],pre*3+change(st[row][col][0]),now*3+change(st[row][col][0]));
        return;
    }
    for(int i=0; i<4; i++)
        if(prechar=='#'||prechar==st[row][col][i])
            dfs(col+1,sum,st[row][col][(i+2)%4],pre*3+change(st[row][col][(i+1)%4]),now*3+change(st[row][col][(i+3)%4]));
}

int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(int ca=1; ca<=T; ca++)
    {
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%s",st[i][j]);
        memset(same,0,sizeof(same));
        Max=1;
        for (i=0; i<m; i++) Max*=3;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            bool ok=1;
            for(int r=1;r<4;r++)
              if(st[i][j][r]!=st[i][j][r-1]) ok=0;
            same[i][j]=ok;
        }
        memset(dp,0,sizeof(dp));
        for(row=0;row<n;row++) dfs(0,1,'#',0,0);

        int ans=0;
        for(i=0;i<Max;i++) ans=(ans+dp[n-1][i])%MOD;
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
