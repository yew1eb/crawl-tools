#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
bool cmp(int x,int y)
{
    return x>   y;
}

int dp[1010][5050];
int a[5050];
int main()
{
    int t,k,n,i,j;
    scanf("%d",&t);
    while (t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&k,&n);
        for (i=n;i>=1;i--)
        scanf("%d",&a[i]);
        a[0]=0;
        sort(a+1,a+n+1,cmp);
        for (i=1;i<=k+8;i++)
        {
            dp[i][i*3]=dp[i-1][i*3-2]+(a[i*3-1]-a[i*3])*(a[i*3-1]-a[i*3]);
            for (j=3*i+1;j<=n;j++)
            dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+(a[j-1]-a[j])*(a[j-1]-a[j]));
        }
        printf("%d\n",dp[k+8][n]);
    }
}
