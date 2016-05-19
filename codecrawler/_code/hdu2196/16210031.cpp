#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 10005
#define max(a,b) ((a)>(b)?(a):(b))
int dp[MAX][3];
int edge[MAX<<1];//è¡¨ç¤ºç¬¬iæ¡è¾¹çç»ç¹
int next[MAX<<1];//ä¸ç¬¬iæ¡è¾¹åèµ·ç¹çä¸ä¸æ¡è¾¹çä½ç½®
int head[MAX<<1];//ä»¥iä¸ºèµ·ç¹çç¬¬ä¸æ¡è¾¹çå¨å­ä½ç½®
int cost[MAX<<1];
void insert(int i,int a,int b,int c)//aèµ·ç¹,bç»ç¹
{
    edge[i]=b;
    next[i]=head[a];
    head[a]=i;
    cost[i]=c;
}
void dp1(int x,int pre)
{
    for(int i=head[x]; i!=-1; i=next[i])
    {
        int k=edge[i];
        if(k!=pre)
        {
            dp1(k,x);
            if(dp[x][0]<cost[i]+dp[k][0])
            {
                dp[x][1]=dp[x][0];//æ´æ°æ¬¡é¿å­æ è·¯å¾
                dp[x][0]=cost[i]+dp[k][0];//æ´æ°æé¿å­æ è·¯å¾
            }
            else if(dp[x][1]<cost[i]+dp[k][0])
                dp[x][1]=cost[i]+dp[k][0];//æ´æ°æ¬¡é¿å­æ è·¯å¾
        }
    }
}
void dp2(int x,int pre)
{
    int len=0;
    for(int i=head[x]; i!=-1; i=next[i])
        if(edge[i]==pre)
        {
            len=cost[i];
            break;
        }
    if(pre!=-1)
    {
        dp[x][2]=dp[pre][2];
        if(dp[x][0]+len==dp[pre][0])
        {
            if(dp[pre][1]>dp[x][2]) dp[x][2]=dp[pre][1];
        }
        else if(dp[pre][0]>dp[x][2]) dp[x][2]=dp[pre][0];
        dp[x][2]+=len;
    }
    for(int i=head[x]; i!=-1; i=next[i])
        if(edge[i]!=pre)   dp2(edge[i],x);
}
int main()
{
    int n;
    int a,b;
    for(; ~scanf("%d",&n);)
    {
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
        for(int i=2,j=1; i<=n; ++i)
        {
            scanf("%d%d",&a,&b);
            insert(j++,i,a,b);
            insert(j++,a,i,b);
        }
        dp1(1,-1);//æ±å­æ æé¿è·¯
        dp2(1,-1);//æ±ç¶æ æé¿è·¯
        for(int i=1; i<=n; ++i)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
