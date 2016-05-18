#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=303;
int sum[maxn][maxn],e[maxn][maxn];
int find(int n,int m)
{
    int i,j,k,ans=0,t=0,p,q;
    if(e[n][m]==0)return 0;
    for(i=n-1,j=m-1;i>=1&&j>=1;i--,j--,t++)
    {
        //判断边上是否有0
        if(!e[i][m]||!e[n][j])return ans;
        for(p=i,q=j;p<n;p++,q++)
            if(!e[i][q]||!e[p][j])break;
        if(p<n)continue;
        //判断边上无0后，计算中间部分0和1个数差
        p=sum[n-1][m-1]-sum[i][m-1]-sum[n-1][j]+sum[i][j];//正方形中部分的和
        if(abs(t*t-2*p)<=1)ans++;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,m,ans=0;
        scanf("%d%d",&n,&m);
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&e[i][j]);
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+e[i][j];//计算以(0,0)和(i,j)为端点的矩阵和
            }
        }
        for(i=2;i<=n;i++)
            for(j=2;j<=m;j++)
                ans+=find(i,j);
        printf("%d\n",ans);
    }
    return 0;
}