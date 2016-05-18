#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXD 1010
#define MAXM 2004010
#include<iostream>
#define INF 0x7fffffff
using namespace std;

int head[MAXD], e;
int v[MAXM], next[MAXM], flow[MAXM];
int lev[MAXD], q[MAXD], out[MAXD];

void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void add(int x, int y, int z)
{
    v[e]=y;
    flow[e]=z;
    next[e]=head[x];
    head[x]=e++;
    v[e]=x;
    flow[e]=0;
    next[e]=head[y];
    head[y]=e++;
}

int bfs(int S,int T)
{
    int  rear = 0;
    memset(lev, -1, sizeof(lev));
    lev[S] = 0, q[rear ++] = S;
    for(int i = 0; i < rear; i ++)
        for(int j = head[q[i]]; j != -1; j = next[j])
            if(flow[j] && lev[v[j]] == -1)
            {
                lev[v[j]] = lev[q[i]] + 1, q[rear ++] = v[j];
                if(v[j] == T) return 1;
            }
    return 0;
}

int dfs(int cur, int a,  int T)
{
    if(cur == T)
        return a;
    for(int &i = out[cur]; i != -1; i = next[i])
        if(flow[i] && lev[v[i]] == lev[cur] + 1)
        {
            int t = dfs(v[i], min(a, flow[i]),T);
            if(t)
            {
                flow[i] -= t, flow[i ^ 1] += t;
                return t;
            }
        }
    return 0;
}

long long dinic(int S,int T)
{
    long long ans = 0;
    while(bfs(S,T))
    {
        memcpy(out, head, sizeof(head));
        while(int t = dfs(S, INF,T))
            ans += t;
    }
    return ans;
}
int x, a;
int N;
int S = 0, T = N + 1;
long long SUM;
void input()
{
    scanf("%d", &N);
    init();
    S=0;
    T=N+1;
    SUM = 0;
    for(int i = 1; i <= N; i ++)
    {
        a = 0;
        for(int j = 1; j <= N; j ++)
        {
            scanf("%d", &x), a += x;
            add(i, j, x);
        }
        SUM += a;
        add(S, i, a);
    }
    for(int i = 1; i <= N; i ++)
    {
        scanf("%d", &x);
        add(i, T, x);
    }
    cout<<SUM-dinic(S,T)<<endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        input();
    }
    return 0;
}
