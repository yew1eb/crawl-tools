#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 1e8
const int maxn=100+5;

int n;//n种货币
int T;//商品金额
int val[maxn];//每种货币面值
int num[maxn];//每种货币数目
int dp1[20000+5];
int dp2[20000+5];

//1次01背包过程
void ZERO_ONE_PACK(int *dp,int cost,int sum)
{
    for(int i=20000;i>=cost;i--)
        dp[i] = min(dp[i],dp[i-cost]+sum);//注意这里是+sum,而不是+1
}

//1次完全背包过程
void COMPLETE_PACK(int *dp,int cost)
{
    for(int i=cost;i<=20000;i++)
        dp[i] = min(dp[i],dp[i-cost]+1);
}

//1次多重背包过程
void MULTIPLY_PACK(int *dp,int cost,int sum)
{
    if(cost*sum>=20000)
    {
        COMPLETE_PACK(dp,cost);
        return ;
    }

    int k=1;
    while(k<sum)
    {
        ZERO_ONE_PACK(dp,cost*k,k);
        sum-=k;
        k*=2;
    }
    ZERO_ONE_PACK(dp,cost*sum,sum);
}

int main()
{
    int kase=0;
    while(scanf("%d%d",&n,&T)==2)
    {
        //注意退出,否则WA
        if(n==0 && T==0) break;

        //读取输入
        for(int i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);

        //初始化
        for(int i=0;i<=20000;i++)
            dp1[i]=dp2[i]=INF;
        dp1[0]=dp2[0]=0;

        //递推
        for(int i=1;i<=n;i++)
            MULTIPLY_PACK(dp1,val[i],num[i]);
        for(int i=1;i<=n;i++)
            COMPLETE_PACK(dp2,val[i]);

        //输出结果
        int ans=dp1[T];
        for(int i=T+1;i<=20000;i++)
            ans=min(ans, dp1[i]+dp2[i-T]);

        printf("Case %d: %d\n",++kase,ans==INF?-1:ans);
    }
    return 0;
}
