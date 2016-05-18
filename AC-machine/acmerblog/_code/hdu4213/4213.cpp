#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 51000;
const int M = 17;
const int eps = 1e-9;
int d[N][2], Fm[N][2], head[N];
int mi[M][N], mx[M][N];
int Log[N];
int ans[N];
struct EDG{
    int u, v, c, next;
}g[N * 2];
int cnt, n;
void add(int u, int v, int c)
{
    g[cnt].u = u; g[cnt].v = v; g[cnt].c = c; g[cnt].next = head[u]; head[u] = cnt++;
    g[cnt].u = v; g[cnt].v = u; g[cnt].c = c; g[cnt].next = head[v]; head[v] = cnt++;
}
int dfs(int cur, int p)
{
    for(int e = head[cur]; e != -1; e = g[e].next){
        int v = g[e].v;
        if(v != p){
            int t = dfs(v, cur) + g[e].c;
            if(d[cur][1] < t){
                d[cur][0] = d[cur][1]; Fm[cur][0] = Fm[cur][1];
                d[cur][1] = t; Fm[cur][1] = v;
            }else if(d[cur][0] < t){
                d[cur][0] = t; Fm[cur][0] = v;
            }
        }
    }
    return d[cur][1];
}
void Dp(int cur, int p, int c)
{
    if(cur != Fm[p][1]){
        if(d[cur][1] < d[p][1] + c){
            d[cur][0] = d[cur][1]; Fm[cur][0] = Fm[cur][1];
            d[cur][1] = d[p][1] + c; Fm[cur][1] = p;
        }else if(d[cur][0] < d[p][1] + c){
            d[cur][0] = d[p][1] + c; Fm[cur][0] = p;
        }
    }else {
        if(d[cur][1] < d[p][0] + c){
            d[cur][0] = d[cur][1]; Fm[cur][0] = Fm[cur][1];
            d[cur][1] = d[p][0] + c; Fm[cur][1] = p;
        }else if(d[cur][0] < d[p][0] + c){
            d[cur][0] = d[p][0] + c; Fm[cur][0] = p;
        }
    }
    for(int e = head[cur]; e != -1; e = g[e].next){
        int v = g[e].v;
        if(v != p){
            Dp(v, cur, g[e].c);
        }
    }
}
void ST()
{
    for(int i = 1; i <= n; i++)
        mi[0][i] = mx[0][i] = d[i][1];
    for(int i = 1; (1 << i) < n; i++){
        for(int j = n; j >= 1; j--){
            mx[i][j] = mx[i - 1][j];
            if(j + (1 << (i - 1)) <= n)
                mx[i][j] = max(mx[i][j], mx[i - 1][j + (1 << (i - 1))]);
            mi[i][j] = mi[i - 1][j];
            if(j + (1 << (i - 1)) <= n)
                mi[i][j] = min(mi[i][j], mi[i - 1][j + (1 << (i - 1))]);
        }
    }
}
inline int rmq(int l, int r)
{
    int m = Log[r - l + 1];
    int a = max(mx[m][l], mx[m][r - (1 << m) + 1]);
    int b = min(mi[m][l], mi[m][r - (1 << m) + 1]);
    return a - b;
}
inline int check(int m)
{
    int &res = ans[m];
    if(res != -1) return res;
    for(int i = 1; i + m - 1 <= n; i++){
        if(res == -1) res = rmq(i, i + m - 1);
        else res = min(res, rmq(i, i + m - 1));
    }
    return res;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int m;
    int u, v, c;
    for(int i = 0, j = 0; i <= 50000; i++){
        if((1 << j) >= ((i + 1) >> 1)){
            Log[i] = j;
        }else{
            Log[i] = ++j;
        }
    }
    while(scanf("%d %d", &n, &m) == 2 && m + n){
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(d, 0, sizeof(d));
        memset(Fm, 0, sizeof(Fm));
        for(int i = 1; i < n; i++){
            scanf("%d %d %d", &u, &v, &c);
            add(u, v, c);
        }
        dfs(1, 0);
        Dp(1, 0, 0);
        ST();
        memset(ans, -1, sizeof(ans));
        ans[1] = 0;
        for(int i = 0; i < m; i++){
            scanf("%d", &u);
            int l = 1, r = n + 1;
            while(l < r){
                int mid = (l + r) >> 1;
                if(check(mid) <= u){
                    l = mid + 1;
                }else r = mid;
            }
            printf("%d\n", l - 1);
        }
    }
    return 0;
}
