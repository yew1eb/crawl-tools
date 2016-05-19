#include<cstdio>
#include<cstring>
/*******
概率与期望之间的关系
在概率论和统计学中，
一个离散性随机变量的期望值（或数学期望、或均值，亦简称期望）
是试验中每次可能结果的概率乘以其结果的总和。
********/
const int LMT=4002;
double dp[LMT][6],p[LMT][6];
int main(void)
{
    int n,a,b,i,j,T;
    double p1,p2,p3,ans;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
        scanf("%d%d%d",&n,&a,&b);
        for(i=1;i<=n;++i)
            scanf("%lf%lf%lf%lf",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
        ans=0;
        for(i=n+1;i<=n+a;++i)p[i][3]=1.0;
        dp[0][3]=1.0;
        for(i=0;i<=n;++i)
        {
            p1=p2=p3=1.0;
            for(j=i+a;j<=i+b;++j)
            {
                dp[j][2]+=dp[i][1]*p1*p[j][2];
                dp[j][3]+=dp[i][1]*p1*p[j][3];
                p1*=(p[j][0]+p[j][1]);
                dp[j][1]+=dp[i][2]*p2*p[j][1];
                dp[j][3]+=dp[i][2]*p2*p[j][3];
                p2*=(p[j][0]+p[j][2]);
                dp[j][1]+=dp[i][3]*p3*p[j][1];
                dp[j][2]+=dp[i][3]*p3*p[j][2];
                dp[j][3]+=dp[i][3]*p3*p[j][3];
                p3*=p[j][0];
            }
        }
        for(i=a;i<=n+a;++i)
            for(j=1;j<4;++j)
                ans+=dp[i][j];
            printf("%.8f\n",ans);
    }
    return 0;
}