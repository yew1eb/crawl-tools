#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
long long n,m;
int k,s;
long long re;
int sum[1010][1010];//这写数组都可以开小点的
long long dp[1010][1010];

long long c[1010][1010];
//fun c a,b mod m
void initc()//求组合数
{
    int i,j;
    c[0][0] = 1;
    for(i = 1;i < 1010;i++)
    {
        for(j = 0;j <= i;j++)
        {
            c[i][j] = (j == 0) ? c[i-1][j] : ((c[i-1][j] + c[i-1][j-1]) % m);
        }
    }
}
int dfs1(int a,int b)//确定子树中的总点数
{
    sum[a][b] = 0;
    if(a > k) return 0;
    else if(a == k && b > s) return 0;

    dfs1(a+1,b<<1);
    dfs1(a+1,(b<<1)-1);
    sum[a][b] = sum[a+1][b<<1] + sum[a+1][(b<<1)-1] + 1;
    return sum[a][b];
}
long long dfs2(int a,int b)//递推 上面方法可以和这个合为一个，但是当时时间紧没这么做
{
    if(a > k || (a == k && b > s) )
    {
        dp[a][b] = 1;
        return dp[a][b];
    }
    dfs2(a+1,b<<1);
    dfs2(a+1,(b<<1)-1);
    dp[a][b] = (c[sum[a][b] - 1][sum[a+1][b<<1]] *
        ( (dp[a+1][b<<1] * dp[a+1][(b<<1)-1]) % m ))% m;
    return dp[a][b];
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        memset(c,0,sizeof(c));
        cin >> n >> m;
        initc();
        for(int i = 0;i < 1000;i++)
        {
            int tt = 1 << i;
            if(tt-1 > n)
            {
                k = i;
                s = n-((tt>>1) - 1);
                break;
            }
        }//包含k层，最后一层包含s个节点
        //cout << k << " " << s << "\n";
        dfs1(1,1);
        re = dfs2(1,1);
        cout << re << "\n";
    }
    return 0;
}
