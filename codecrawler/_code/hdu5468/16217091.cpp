#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const MAX = 1e5 + 5;
int const MAXM = 8e5;
int mob[MAX], p[MAX], head[MAXM], HEAD[MAX], val[MAX];
int seq[MAX << 1], ans[MAX], num[MAX];
bool noprime[MAX];
int n, cnt, dfn, CNT;

struct EDGE
{
    int to, next; 
}e[MAXM], E[MAX << 1];

void ADD(int u, int v)
{
    E[CNT].to = v;
    E[CNT].next = HEAD[u];
    HEAD[u] = CNT++;
}

void Add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void Mobius()
{
    int pnum = 0;
    mob[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        if(!noprime[i])
        {
            p[pnum ++] = i;
            mob[i] = -1;
        }
        for(int j = 0; j < pnum && i * p[j] < MAX; j++)
        {
            noprime[i * p[j]] = true;
            if(i % p[j] == 0)
            {
                mob[i * p[j]] = 0;
                break;
            }
            mob[i * p[j]] = -mob[i];
        }
    }
}

void DFS(int u, int fa)
{
    dfn ++;
    seq[dfn] = u;
    for(int i = HEAD[u]; i != -1; i = E[i].next)
    {
        int v = E[i].to;
        if(v != fa)
            DFS(v, u);
    }
    dfn ++;
    seq[dfn] = -u;
}

int main()
{
    Mobius();
    int nnn = 0;
    memset(head, -1, sizeof(head));
    cnt = 0;
    for(int i = 1; i <= 100000; i++)
        if(mob[i])
            for(int j = i; j <= 100000; j += i)
                Add(j, i);
    int ca = 1;
    while(scanf("%d", &n) != EOF)
    {
        memset(HEAD, -1, sizeof(HEAD));
        memset(num, 0, sizeof(num));
        memset(ans, 0, sizeof(ans));
        CNT = 0;
        dfn = 0;
        int u, v;
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            ADD(u, v);
            ADD(v, u);
        }
        for(int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        DFS(1, 0);
        for(int i = 1; i <= n; i++)
            ans[i] = (val[i] == 1);
        for(int i = 1; i <= dfn; i++)
        {
            if(seq[i] > 0)
            {
                for(int j = head[val[seq[i]]]; j != -1; j = e[j].next)
                {
                    int v = e[j].to;
                    num[v] ++;
                    ans[seq[i]] -= mob[v] * num[v];
                }
            }
            else
            {
                for(int j = head[val[-seq[i]]]; j != -1; j = e[j].next)
                {
                    int v = e[j].to;
                    ans[-seq[i]] += mob[v] * num[v];
                }
            }
        }
        printf("Case #%d:", ca ++);
        for(int i = 1; i <= n; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
}