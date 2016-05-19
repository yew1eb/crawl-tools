#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1010;
const int M = 35;
typedef long long LL;
int dp[N][N][M], mp[N][N];
char da[N][N];
int n, m, q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        int d = sqrt(double(n));
        for (int i = 1; i<= n; ++i)
            scanf("%s", da[i]+1);
        for (int i = 1; i<= n; ++i)
        {
            for (int j = 1; j<= m; ++j)
            {
                mp[i][j] = mp[i][j-1] + (da[i][j]=='X');
            }
        }
        for (int i = 1, *p, kk; i<= n; ++i)
        {
            for (int j = 1; j<= m; ++j)
            {
                for (int k = 1; k<= d; ++k)
                {
                    kk = k<<1;
                    p = &dp[i][j][k];
                    *p = (da[i][j]=='X');
                    if (i > k)
                    {
                        if (j>k)
                        {
                            *p += dp[i-k][j-k][k] + mp[i-k][j] - mp[i-k][j-k];
                        }
                        else
                        {
                            *p += mp[i-k][j];
                            if (i > kk) *p += dp[i-kk][j][k] + mp[i-kk][j-1];
                        }
                        if (j+k <= m)
                        {
                            *p += dp[i-k][j+k][k] + mp[i-k][j+k-1] - mp[i-k][j];
                        }
                        else
                        {
                            *p += mp[i-k][m] - mp[i-k][j];
                            if (i > kk) *p += dp[i-kk][j][k] + mp[i-kk][m] - mp[i-kk][j];
                        }
                        if (i > kk) *p -= dp[i-kk][j][k];
                    }
                }
            }
        }
        for (int i = 0; i< q; ++i)
        {
            int r, c, w, res;
            scanf("%d%d%d", &r, &c, &w);
            if (w > d)
            {
                res = 0;
                for (int j = r, lf=c, rt=c; j >0; j-=w, lf=max(lf-w,1), rt=min(m,rt+w))
                    res +=  mp[j][rt]-mp[j][lf-1];
                printf("%d\n", res);
            }
            else
                printf("%d\n", dp[r][c][w]);
        }
    }
    return 0;
}
