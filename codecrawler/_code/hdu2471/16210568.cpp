#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll __int64
#define ull unsigned long long
#define eps 1e-8
#define NMAX 1000000000
#define MOD 51123987
//#define lson l,mid,rt<<1
//#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.end())
#define mp make_pair
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
template<class T> inline T Max(T a, T b){ return a > b ? a : b; }
template<class T> inline T Min(T a, T b){ return a < b ? a : b; }
const int maxn = 2000+10;
struct Edge
{
    int v,next;
}e[maxn*30];
int t,nct,head[maxn*30];

bool vis[maxn],gg[maxn][maxn];
queue<int>q;
queue<pair<int,int> >qu;
struct node
{
    int p[30];
}a[maxn],b[maxn];

void add_edge(int u, int v)
{
    e[nct].v = v; e[nct].next = head[u];
    head[u] = nct++;
}

void del(node *k, int n)
{
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    while(!q.empty()) q.pop();
    for(int i = 0; i < n; i++)
    {
        if(k[i].p[0] == 1)
        {
            vis[i] = 1;
            q.push(i);
        }
    }
    nct = 0;
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= t; j++) if(k[i].p[j] != -1)
            add_edge(k[i].p[j],i);
    while(!q.empty())
    {
        int tmp = q.front(); q.pop();
        for(int i = head[tmp]; i != -1; i = e[i].next)
        {
            if(vis[e[i].v]) continue;
            vis[e[i].v] = 1;
            q.push(e[i].v);
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= t; j++)
        {
            if(k[i].p[j] != -1 && vis[k[i].p[j]] == 0)
                k[i].p[j] = -1;
        }
}

bool solve()
{
    memset(gg,0,sizeof(gg));
    while(!qu.empty()) qu.pop();
    qu.push(mp(0,0));
    gg[0][0] = 1;
    while(!qu.empty())
    {
        pair<int,int>tmp = qu.front(); qu.pop();
        if(a[tmp.first].p[0] != b[tmp.second].p[0]) return false;
        for(int i = 1; i <= t; i++)
        {
            if(a[tmp.first].p[i] == -1 && b[tmp.second].p[i] != -1) return false;
            if(a[tmp.first].p[i] != -1 && b[tmp.second].p[i] == -1) return false;
            if(a[tmp.first].p[i] == -1) continue;
            if(gg[a[tmp.first].p[i]][b[tmp.second].p[i]] == 0)
            {
                gg[a[tmp.first].p[i]][b[tmp.second].p[i]] = 1;
                qu.push(mp(a[tmp.first].p[i],b[tmp.second].p[i]));
            }
        }
    }
    return true;
}
int main()
{
#ifdef GLQ
    freopen("input.txt","r",stdin);
//    freopen("o.txt","w",stdout);
#endif
    int n,cas = 1;
    while(~scanf("%d",&t) && t)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= t; j++)
                scanf("%d",&a[i].p[j]);
        del(a,n);
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= t; j++)
                scanf("%d",&b[i].p[j]);
        del(b,n);
        printf("Case #%d: ",cas++);
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}