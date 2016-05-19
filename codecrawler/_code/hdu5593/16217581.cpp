#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LL long long
const int MAXN = 500000 + 5;
int fa[MAXN], f[MAXN][11];
vector<int>lin[MAXN];
int ans[MAXN];
int n, k;
void dfs1(int u)
{
    for(int i = 0 ; i < (int)lin[u].size() ; i++){
        int v = lin[u][i];
        dfs1(v);
        for(int j = 1 ; j <= k ; j++)   f[u][j] += f[v][j - 1];
    }
    f[u][0] = 1;
//    for(int i = 1 ; i <= k ; i++)   f[u][i] += f[u][i - 1];
}
void dfs2(int u)
{
//    ans[u] = 0;
    for(int i = 0 ; i < (int)lin[u].size() ; i++){
        int v = lin[u][i];
        dfs2(v);
    }
    ans[u] = f[u][k];
//    for(int i = 0 ; i <= k ; i++)   ans[u] += f[u][i];
    int now = u;
    int cnt = 1;
    while(fa[now] != 0 && cnt <= k){
        ans[u] += f[fa[now]][k - cnt];
        if(k - cnt - 1 >= 0)    ans[u] -= f[now][k - cnt - 1];
        cnt++;
        now = fa[now];
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        LL a, b;
        scanf("%d%d%I64d%I64d", &n, &k, &a, &b);
        for(int i = 1 ; i <= n ; i++)   lin[i].clear();
        fa[0] = 0;
        fa[1] = 0;
        for(int i = 2 ; i <= n ; i++){
            fa[i] = (a * i + b) % (i - 1) + 1;
            lin[fa[i]].push_back(i);
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= k ; j++){
                f[i][j] = 0;
            }
        }
        dfs1(1);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= k ; j++){
                f[i][j] += f[i][j - 1];
            }
        }
        dfs2(1);
        int res = 0;
        for(int i = 1 ; i <= n ; i++)   res = res ^ ans[i];
//        for(int i = 1 ; i <= n ; i++)   printf("ans[%d] = %d\n", i, ans[i]);
        printf("%d\n", res);
    }
    return 0;
}