#include<cstdio>
#include<cstring>
using namespace std;
int dp[15][15][3];
/*
dp[i][j][k] jè¡¨ç¤ºä½æ°
k==0 ä¸åå«13ä¸ä¸ä»¥1ç»å°¾
k==1 ä¸åå«13ä¸ä»¥1ç»å°¾
k==2 åå«13
*/
int num[15];
int next(int a,int b)
{
    if(a==0)
    {
        if(b==1) return 1;
        else     return 0;
    }
    if(a==1)
    {
        if(b==3) return 2;
        if(b==1) return 1;
        else     return 0;
    }
    return 2;
}
int dfs(int idx,int pre,int value,bool bound)//ä½æ°ï¼ä½æ°ï¼ç¶ææ å·ï¼æ¯å¦ä¸ºä¸ç
{
    if(idx==-1) return value==2&&pre==0;//æ°å­ä¸­åºç°13ä¸è¢«13æ´é¤
    if(!bound&&dp[idx][pre][value]!=-1) return dp[idx][pre][value];//è®°å¿å
    int ans=0,end=bound?num[idx]:9;
    for(int i=0;i<=end;++i)
        ans+=dfs(idx-1,(pre*10+i)%13,next(value,i),bound&&i==end);
    if(!bound) dp[idx][pre][value]=ans;
    return ans;
}
void DP(int n)
{
    int idx=0;
    for(;n;n/=10) num[idx++]=(n%10);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(idx-1,0,0,true));
}
int main()
{
    int n;
    for(;~scanf("%d",&n);)
       DP(n);
    return 0;
}
