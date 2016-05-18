#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define SZ(v) ((int)(v).size())
const int MAXN = 65, MAXS = 520;

int t, n, l, s, a, b;
vector<int> maps[MAXN];
double dp[MAXN][MAXS], son[MAXS], tmp[MAXS], ans, e;

void dfs(int x, int p)
{
        for (int i = 0; i <= s; ++ i)
                dp[x][i] = 0.0;
        dp[x][0] = 1.0;
        for (int i = 0; i < SZ(maps[x]); ++ i)
        {
                int c = maps[x][i];
                if (c != p)
                {
                        dfs(c, x);
                        for (int j = 0; j <= s; ++ j)
                                son[j] = tmp[j] = 0.0;

                        for (int j = 0; j <= l; ++ j)
                                for (int k = 0; k <= s; ++ k)
                                        if (j + k <= s)
                                                son[j + k] += dp[c][k] * e;

                    /*  for(int i=0;i<=s;i++)
                          cout<< son[i] <<" ";
                        cout<<endl;
                        for(int i=0;i<=s;i++)
                          cout<< dp[x][i] <<" ";
                        cout<<endl;
                        cout<<endl;*/
                        for (int j = 0; j <= s; ++ j)
                        {
                                //cout<<s-j<<" :: ";
                                for (int k = 0; k <= s - j; ++ k)
                                {
                                        //cout<<max(i,j)<<endl;
                                        tmp[max(j, k)] += son[j] * dp[x][k];
                                       // cout<< max(j,k)<<" "<<tmp[max(j,k)]<<endl;
                                }
                        }
                        for (int j = 0; j <= s; ++ j)
                                dp[x][j] = tmp[j];
                       // cout<<endl;
                }
        }
}

int main()
{
        scanf("%d", &t);
        for (int m = 1; m <= t; ++ m)
        {
                scanf("%d%d%d", &n, &l, &s);
                e = 1 / (l + 1.0);
                for (int i = 1; i <= n; ++ i)
                        maps[i].clear();
                for (int i = 1; i < n; ++ i)
                {
                        scanf("%d%d", &a, &b);
                        maps[a].push_back(b);
                        maps[b].push_back(a);
                }
                dfs(1, -1);
                ans = 0.0;
                /*for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<=s;j++)
                      printf("%.3lf ",dp[i][j]);
                    cout<<endl;
                }*/
                for (int i = 0; i <= s; ++ i)
                        ans += dp[1][i];
                printf("Case %d: %.6lf\n", m, ans);
        }
        return 0;
}
