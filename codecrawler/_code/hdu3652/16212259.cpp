#include <stdio.h>
#include <string.h>

int digit[15];
int dp[15][15][15][2];

int DFS(int pos,int pre,int mod,bool have,bool inf)
{
    int i,j;
    if (pos==-1) return (have && !mod);
    if (!inf && dp[pos][pre][mod][have]!=-1) return dp[pos][pre][mod][have];
    int ans=0;
    int end=inf?digit[pos]:9;
    for (i=0;i<=end;i++)
    {
        if (pre==1 && i==3) ans+=DFS(pos-1,3,(mod*10+i)%13,1,inf && (i==digit[pos]));
        else ans+=DFS(pos-1,i,(mod*10+i)%13,have,inf && (i==digit[pos]));
    }
    if (!inf)
    {
        dp[pos][pre][mod][have]=ans;
    }
    return ans;

}

int Calc(int t)
{
    int pos=0;
    while(t)
    {
        digit[pos++]=t%10;
        t/=10;
    }
    return DFS(pos-1,0,0,0,1);

}

int main()
{
    int i,j,n;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",Calc(n));
    }
    return 0;
}
