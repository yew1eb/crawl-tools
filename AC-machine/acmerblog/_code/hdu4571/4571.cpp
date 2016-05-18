#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 110;
const int M = N * N;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int u, v, c;
}E[M];

struct Node
{
    int u, tim;
};

int fir[N], next[M], tot;
int G[N][N], n, m, t, s, e, cas = 1;
int C[N], S[N], dp[N][N * 3];

void Add_Edge(int u, int v, int c)
{
    E[tot].u = u, E[tot].v = v, E[tot].c = c;
    next[tot] = fir[u], fir[u] = tot ++;
}

void input()
{
    int u, v, c, i, j;
    scanf("%d%d%d%d%d", &n, &m, &t, &s, &e);
    CLR(G, INF);
    for(i = 0; i < n; i ++)
        scanf("%d", &C[i]);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &S[i]);
        G[i][i] = 0;
    }
    for(i = 0; i < m; i ++)
    {
        scanf("%d%d%d", &u, &v, &c);
        G[u][v] = G[v][u] = min(c, G[u][v]);
    }
}

void floyd()
{
    int i, j, k;
    for(k = 0; k < n; k ++)
        for(i = 0; i < n; i ++)
            for(j = 0 ; j < n; j ++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

void init()
{
    int i, j;tot = 0;CLR(fir, -1);
    S[n] = C[n] = 0;
    S[n + 1] = N;C[n + 1] = 0;
    for(i = 0; i < n; i ++)
    {
        if(i != s) Add_Edge(n, i, G[s][i]);
        else Add_Edge(n, s, 0);
        if(i != e) Add_Edge(i, n + 1, G[e][i]);
        else Add_Edge(e, n + 1, 0);
    }
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            if(S[j] > S[i])
                Add_Edge(i, j, G[i][j]);
    s = n; e = n + 1;n += 2;
}

void Spfa()
{
    int v, i, j, c, ans;
    queue<Node> Q;CLR(dp, 0);
    dp[s][0] = 0;Node A, B;
    A.u = s;A.tim = 0;Q.push(A);
    while(!Q.empty())
    {
        A = Q.front();Q.pop();
        for(i = fir[A.u]; ~i; i = next[i])
        {
            v = E[i].v;c = E[i].c;
            int tmp = A.tim + c + C[v];
            if(tmp <= t && dp[v][tmp] < dp[A.u][A.tim] + S[v])
            {
                dp[v][tmp] = dp[A.u][A.tim] + S[v];
                B.u = v;
                B.tim = tmp;
                Q.push(B);
            }
        }
    }
    ans = 0;
    for(i = 0; i <= t; i ++)
    {
        ans = max(ans, dp[e][i]);
    }
    printf("Case #%d:\n%d\n", cas ++, max(ans - N, 0));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int w;
    scanf("%d", &w);
    while(w --)
    {
        input();
        floyd();
        init();
        Spfa();
    }
}
