#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define FIN             freopen("input.txt","r",stdin)
#define FOUT            freopen("output.txt","w",stdout)
#define CASE(T)         for(scanf("%d",&T);T--;)

typedef __int64  LL;
const int maxn = 20000 + 5;
const int maxm = 100000 + 5;
const int maxq = 5000 + 5;
int T, N, M, Q;
struct Edge
{
    int from, to, cost;
    bool operator < (const Edge& e) const
    {
        return cost < e.cost;
    }
} edges[maxm];
int pa[maxn], num[maxn], Query[maxq], qq[maxq];
map<int, LL> Ans;

int Find(int x)
{
    return x == pa[x] ? x : (pa[x] = Find(pa[x]));
}
int main()
{
//    FIN;
    CASE(T)
    {
        scanf("%d %d %d", &N, &M, &Q);
        int u, v, c;
        for(int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            edges[i].from = u, edges[i].to = v, edges[i].cost = c;
        }
        sort(edges, edges + M);

        Ans.clear();
        for(int i = 0; i < Q; i++)
        {
            scanf("%d", &Query[i]);
            qq[i] = Query[i];
        }
        sort(qq, qq + Q);
        LL s = 0;
        for(int i = 1; i <= N; i++) pa[i] = i, num[i] = 1;
        int j = 0;
        for(int i = 0; i < M; i++)
        {
            int fa = Find(edges[i].from), fb = Find(edges[i].to);
            while(j < Q && edges[i].cost > qq[j])
            {
                Ans[qq[j]] = s;
                j++;
            }
            if(fa != fb)
            {
                s = (LL)s - num[fa] * (num[fa] - 1) - num[fb] * (num[fb] - 1) + (num[fa] + num[fb]) * (num[fa] + num[fb] - 1);
                pa[fb] = fa;
                num[fa] += num[fb];
            }
        }
        while(j < Q) Ans[qq[j++]] = s;
        for(int i = 0; i < Q; i++)
            printf("%I64d\n", Ans[Query[i]]);
    }
    return 0;
}