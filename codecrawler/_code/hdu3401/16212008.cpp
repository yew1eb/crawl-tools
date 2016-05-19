#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 2005
#define inf 0xfffff
#define max(a,b) ((a)>(b)?(a):(b))
int T,MaxP,W;
int APi[MAX],BPi[MAX],ASi[MAX],BSi[MAX];
int dp[MAX][MAX];//dp[i][j]ç¬¬iå¤©ææjè¡çæå¤§å¼
//dp[i][j]=max{dp[i-1][j],max{dp[r][k]-APi[i]*(j-k)}(0<r<i-w,k<j),max{dp[r][k]+BPi[i]*(k-j)}(0<r<i-w,k>j)}
struct node
{
    int x;//å­dp[i-w-1][k]+APi[i]*kædp[i-w-1][k]+BPi[i]*k
    int p;//å½åæè¡æ°
} q[2005],temp;
int front,back;
int main()
{
    int cas;
    scanf("%d",&cas);
    for(; cas--;)
    {
        scanf("%d%d%d",&T,&MaxP,&W);
        for(int i=1; i<=T; ++i)
            scanf("%d%d%d%d",APi+i,BPi+i,ASi+i,BSi+i);
        for(int i=0; i<=T; ++i)
            for(int j=0; j<=MaxP; ++j)
                dp[i][j]=-inf;
        for(int i=1; i<=W+1; ++i)
            for(int j=0; j<=ASi[i]; ++j)
                dp[i][j]=(-APi[i]*j);
        for(int i=2; i<=T; ++i)
        {
            for(int j=0; j<=MaxP; ++j)
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(i<=W+1) continue;
            //ä¹°å¥
            front=back=1;
            for(int j=0; j<=MaxP; ++j)
            {
                temp.p=j;
                temp.x=dp[i-W-1][j]+APi[i]*j;
                for(;front<back&&q[back-1].x<temp.x;--back);
                q[back++]=temp;
                for(;front<back&&q[front].p+ASi[i]<j;++front);
                dp[i][j]=max(dp[i][j],q[front].x-APi[i]*j);
            }
            //ååº
            front=back=1;
            for(int j=MaxP; j>=0; --j)
            {
                temp.p=j;
                temp.x=dp[i-W-1][j]+BPi[i]*j;
                for(;front<back&&q[back-1].x<temp.x;--back);
                q[back++]=temp;
                for(;front<back&&q[front].p-BSi[i]>j;++front);
                dp[i][j]=max(dp[i][j],q[front].x-BPi[i]*j);
            }
        }
        int ans=0;
        for(int i=0;i<=MaxP;++i)
            ans=max(ans,dp[T][i]);
        printf("%d\n",ans);
    }
    return 0;
}
