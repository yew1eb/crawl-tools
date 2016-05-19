//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXN=20010;

int deg[MAXN],stamp[MAXN],seq[MAXN];
bitset<MAXN> reach[MAXN];
vector<int> revEdges[MAXN],edges[MAXN];

bool cmp(int u,int v)
{
    return stamp[u]>stamp[v];
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        edges[i].clear();
        revEdges[i].clear();
        deg[i]=0;
        reach[i].reset();
        reach[i][i]=true;
    }
}


int main()
{
    int T,n,m;
    read(T);
    while(T--)
    {
        read(n),read(m);
        init(n);
        for(int i=1,u,v;i<=m;i++)
        {
            read(u),read(v);
            edges[u].push_back(v);
            revEdges[v].push_back(u);
            deg[v]++;
        }
        queue<int> q;
        int timestamp=0;
        while(!q.empty())   q.pop();
        for(int i=1;i<=n;i++)
            if(deg[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            stamp[u]=++timestamp;
            seq[timestamp]=u;
            for(auto v: edges[u])
                if(--deg[v] == 0)
                    q.push(v);
        }
        int ans=0;
        for(int i=1;i<=timestamp;i++)
        {
            int u=seq[i];
            sort(revEdges[u].begin(),revEdges[u].end(),cmp);
            for(int v: revEdges[u])
            {
                if(reach[u][v])
                    ans++;
                reach[u]|=reach[v];
            }
        }
        write(ans),putchar('\n');
    }
    return 0;
}
