/*
状态转移方程为：
买入：
  dp[i][j]=max(dp[r][k]-(j-k)*ap[i]);(0<j-k<=bnum[i])
卖出：
  dp[i][j]=max(dp[r][k]+(k-j)*bp[i]);（0<k-j<=snum[i])
不买不卖：
  dp[i][j]=max(dp[i][j],dp[i-1][j]);
很明显时间复杂度为o(maxp^2*t^2) 超时！！
考虑怎么优化：
  dp[i][j]+j*ap[i]=max(dp[r][k]+k*bp[i]);
同理：
  dp[i][j]+j*bp[i]=max(dp[r][k]+k*ap[i]);
买
 令f(k)=dp[i][k]+k*AP[i]
 f(j)=max(f(k)) (j-AS[i]<=k<=j)//经典单调队列
 所以dp[i][j]=f(j)-j*AP[i]
 卖
 令ff(k)=dp[i][k]+k*AP[i]
 ff(j)=max(ff(k)) (j<=k<=j+BS[i])
 所以dp[i][j]=ff(j)-j*BP[i]
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<memory.h>
#include<cmath>
using namespace std;
const int maxn=2002;
const int maxm=2002;
const int inf=1<<29;
int q[maxn];
int t,cas,maxp,w,ap[maxn],bp[maxn],as[maxn],bs[maxn];
int dp[maxn][maxm];
int main()
{
    scanf("%d",&cas);
    while(cas--)
    {
        int i,j;
        scanf("%d%d%d",&t,&maxp,&w);
        for(i=1; i<=t; i++)
        {
            scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
        }
        for(i=0; i<=t; i++)
        {
            for(j=0; j<=maxp; j++)
            {
                dp[i][j]=-inf;
            }
        }
        dp[0][0]=0;
        for (i=1; i<=w+1; i++)//前w天买第一批货物
        {
            for (j=0; j<=min(as[i],maxp); j++) dp[i][j]=-ap[i]*j;
        }
        for(i=1; i<=t; i++)
        {
            for(j=0; j<=maxp; j++) //不买不卖
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
            if(i<=w+1) continue;//第1天有交易也要第w+2后才能再次交易
            int pre=i-w-1;
            //买
            int front = 1;
            int tail = 0;
            for (j = 0; j <= maxp; ++j)
            {
                while (tail >= front && q[front] + as[i] < j) front++;//单调队列维护长度不能超过as
                int tmp = dp[i - w - 1][j];
                while (tail >= front && dp[pre][q[tail]] - ap[i]*(j - q[tail]) < tmp) tail--;
                q[++tail] = j;
                if (tail >= front) dp[i][j] = max(dp[i][j],dp[pre][q[front]] - ap[i]*(j - q[front]));
            }
            //卖
            front = 1;
            tail = 0;
            for (j = maxp; j >= 0; --j)
            {
                while (tail >= front && q[front] - bs[i] > j) front++;
                int tmp = dp[i - w - 1][j];
                while (tail >= front && dp[pre][q[tail]] + bp[i]*(q[tail] - j) < tmp) tail--;
                q[++tail] = j;
                if (tail >= front) dp[i][j] = max(dp[i][j],dp[pre][q[front]] + bp[i]*(q[front] - j));
            }
        }
        int ans=0;
        for(i=0; i<=maxp; i++)
        {
            ans=max(ans,dp[t][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}