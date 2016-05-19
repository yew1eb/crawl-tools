#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
const int maxn = 2000005;
int fa[maxn/2];
int Find(int x)
{
    if(fa[x]==-1) return x;
    else return fa[x] = Find(fa[x]);
}


struct Edge
{
    int s, t;
    short w;
    Edge(int _s=0, int _t=0, short _w=0)
    {
        s = _s;
        t = _t;
        w = _w;
    }
    bool operator < (const Edge &t) const {
        return w < t.w;
    }
}edges[maxn];
int cnt;

int n, m;

int main()
{
    int T;
    int ans, fx, fy;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) scanf("%d", &fa[i*m+j]);
        cnt = 0;
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
            {
                if(j>0)
                {
                    edges[cnt++] = Edge(i*m+j-1, i*m+j, abs(fa[i*m+j] - fa[i*m+j-1]));
                }
                if(i>0)
                {
                    edges[cnt++] = Edge((i-1)*m+j,i*m+j, abs(fa[i*m+j] - fa[(i-1)*m+j]));
                }
            }

        sort(edges,edges+cnt);
        memset(fa, -1, sizeof fa );
        ans = 0;
        for(int i=0; i<cnt; ++i)
        {
            fx = Find(edges[i].s);
            fy = Find(edges[i].t);
            if( fx != fy)
            {
                fa[fx] = fy;
                ans += edges[i].w;
            }
        }
        printf("Case #%d:\n", cas);
        printf("%d\n", ans);
    }
    return 0;
}
