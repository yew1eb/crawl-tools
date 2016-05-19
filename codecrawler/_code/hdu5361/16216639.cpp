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

const int MAXN=200010;

ll L[MAXN],R[MAXN],cost[MAXN],dis[MAXN];
int n,fa[MAXN];

struct Node
{
    ll dis,cost;
    int u;
    bool operator < (const Node& b) const
    {
        return dis+cost>b.dis+b.cost;
    }
    Node(ll dis=0,ll cost=0,int u=0):dis(dis),cost(cost),u(u) {}
};

priority_queue<Node> Q;

void init()
{
    for(int i=0 ; i<n+10; i++)
    {
        dis[i]=LLINF;
        fa[i]=i;
    }
    while(!Q.empty())   Q.pop();
}

int find_fa(int x)
{
    if(fa[x]==x)    return x;
    return fa[x]=find_fa(fa[x]);
}

void merge(int x,int y)
{
    x=find_fa(x),y=find_fa(y);
    if(x==y)    return;
    fa[x]=y;
}

void dij(int st)
{
    dis[st]=0;
    Q.push(Node(0LL,cost[st],st));
    while(!Q.empty())
    {
        Node tmp=Q.top();
        Q.pop();
        int u=tmp.u;
        //cout<<u<<endl;
        for(int i=-1; i<=1; i += 2)
        {
            int le=L[u]*i+u;
            int ri=R[u]*i+u;
            if(le>ri)
                swap(le,ri);
            if(le>n || ri<=0)    continue;
            for(int v=max(le,1); ; v++)
            {
                v=find_fa(v);
                if(v>min(n,ri))
                    break;
                if(dis[v]>dis[u]+cost[u])
                {
                    dis[v]=dis[u]+cost[u];
                    Q.push(Node(dis[v],cost[v],v));
                }
                merge(v,v+1);
            }
        }
    }
}

int main()
{
    int T;
    read(T);
    while(T--)
    {
        read(n);
        init();
        for(int i=1; i<=n; i++)
            read(L[i]);
        for(int i=1; i<=n; i++)
            read(R[i]);
        for(int i=1; i<=n; i++)
            read(cost[i]);
        dij(1);
        printf("0");
        for (int i=2; i<=n; i++)
            printf(" %I64d",dis[i]!=LLINF?dis[i]:-1);
        printf("\n");
    }
    return 0;
}
