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

const int MAXN=505*205+205;

int n,m,k;
vi g[MAXN];
int from[MAXN],tot;
int used[MAXN];
int ans[505];
int op[505];
int qq[505],cntt;
int tmstamp;

bool match(int x)
{
    int sz=g[x].size();
    for(int i=0;i<sz;i++)
        if(used[g[x][i]]!=tmstamp)
        {
            used[g[x][i]]=tmstamp;
            if(from[g[x][i]]==-1 || match(from[g[x][i]]))
            {
                from[g[x][i]]=x;
                return true;
            }            
        }
    return false;
}

int hungry()
{
    tot=0;
    CLR(from,-1);
    for(int i=cntt-1;i>=0;i--)
        for(int j=qq[i]*k;j<(qq[i]+1)*k;j++)
        {
            tmstamp++;
            if(match(j))
            {
                ans[qq[i]]++;tot++;    
            }
        }
    return tot;
}

int ma[222][222];
int vis[222],q[222],cnt;
void dfs(int u,int op)
{
    vis[u]=1;q[cnt++]=u;
    for(int i=1;i<=n;i++)
        if(ma[u][i] && !vis[i])
                dfs(i,op);
}

void init()
{
    CLR(ma,0);CLR(ans,0);cntt=0;
    for(int i=0;i<MAXN;i++)
        g[i].clear();
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    read(T);
    tmstamp=0;
    while(T--)
    {
        init();
        read(n),read(m),read(k);
        for(int i=1,x,y,tt;i<=m;i++)
        {
            read(op[i]);
            if(op[i]==1)
            {
                qq[cntt++]=i;
                read(x);
                CLR(vis,0);cnt=0;
                dfs(x,i);
                for(int t=0;t<cnt;t++)
                    for(int j=i*k;j<(i+1)*k;j++)
                    {
                        //cout<<i<<":("<<j<<") "<<x<<endl;
                        g[j].pb(q[t]);    
                    }
            }
            else if(op[i]==2)
            {
                read(x),read(y);
                ma[x][y]=ma[y][x]=1;
            }
            else
            {
                read(tt);
                for(int i=1;i<=tt;i++)
                {
                    read(x),read(y);
                    ma[x][y]=ma[y][x]=0;
                }
            }
        }
        int sum=hungry();
        write(sum),putchar('\n');
        bool flag=false;
        for(int i=0;i<cntt;i++)
        {
            printf("%s%d",((flag)?" ":""),ans[qq[i]]);
            flag=true;
        }
        puts("");
    }
    return 0;
} 