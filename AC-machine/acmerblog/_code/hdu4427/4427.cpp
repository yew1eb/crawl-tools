#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const int maxn=1010;
const int mod=1000000007;

int dp[2][maxn][maxn];
int lcm[maxn][maxn];//lcm[a][b]为a,b的最大公约数。
int fac[maxn];//存m的因子
int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int main()
{
    int n,m,k,cnt,i,j,p,q,e,f,t,v,mul,tt;

    for(i=1; i<maxn; i++)
        for(j=i; j<maxn; j++)//预处理出任意两数的最大公倍数
            lcm[i][j]=lcm[j][i]=i*j/gcd(i,j);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        cnt=0;
        for(i=1; i<=m; i++)
        {
            if(m%i==0)
                fac[cnt++]=i;
        }
        v=0;
        memset(dp,0,sizeof dp);//记得要初始化。wa了千百回。里面的初始化只初始化了部分
        for(i=0; i<cnt; i++)
            dp[v][fac[i]][fac[i]]=1;
        for(i=1; i<k; i++) //len
        {
            for(e=i; e<=n; e++)//必须手动初始化。不然超时
                for(f=0; f<cnt; f++)
                    dp[v^1][e][fac[f]]=0;
            for(j=i; j<n; j++) //sum
            {
                for(p=0; p<cnt; p++) //mul
                {
                    mul=fac[p];
                    if(!dp[v][j][mul])
                        continue;
                    for(q=0; q<cnt; q++) //a[i]
                    {
                        tt=j+fac[q];
                        if(tt>n)
                            break;
                        t=lcm[mul][fac[q]];
                        dp[v^1][tt][t]+=dp[v][j][mul];
                        dp[v^1][tt][t]%=mod;
                    }
                }
            }
            v^=1;
        }
        printf("%d\n",dp[v][n][m]);
    }
    return 0;
}
