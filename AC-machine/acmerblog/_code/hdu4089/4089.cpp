#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
#define eps 1e-9
#define zero(x) ((fabs(x)<eps?0:x))
#define maxn 2200
double dp[maxn][maxn];
double c[maxn];
double p[maxn];
int main()
{
    int n,m,k;
    double p1,p2,p3,p4;
    while(~scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4))
    {
        if(p4<eps)
        {
            puts("0.00000");
            continue;
        }
        double p21=p2/(1-p1);
        double p41=p4/(1-p1);
        double p31=p3/(1-p1);
        p[0]=1.0;
        for(int i=1;i<=n;i++)p[i]=p[i-1]*p21;
        dp[1][1]=p41/(1-p21);
        for(int i=2;i<=n;i++)
        {
            double tmp=p[i-1]*p41;
            for(int j=2;j<=k&&j<=i;j++)c[j]=p31*dp[i-1][j-1]+p41;
            for(int j=k+1;j<=i;j++)c[j]=p31*dp[i-1][j-1];
            for(int j=2;j<=i;j++)tmp+=p[i-j]*c[j];
            dp[i][i]=tmp/(1-p[i]);
            dp[i][1]=p21*dp[i][i]+p41;
            for(int j=2;j<i;j++)dp[i][j]=p21*dp[i][j-1]+c[j];
        }
        printf("%.5f\n",dp[n][m]);
    }
    return 0;
}











