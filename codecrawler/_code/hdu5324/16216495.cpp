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

const int MAXN=50010;

struct Node
{
    int l,r,idx;
    Node(const int l=0,const int r=0,const int idx=0):l(l),r(r),idx(idx){}
    bool operator < (const Node& b) const
    {

        if(r!=b.r)  return r<b.r;
        if(l!=b.l)  return l>b.l;
        return idx<b.idx;
    }
}a[MAXN];

struct P
{
    int l,r,pos;
    P(const int l=0,const int r=0,const int pos=0):l(l),r(r),pos(pos){}
    bool operator < (const P& b) const
    {
        if(r!=b.r)  return r<b.r;
        if(l!=b.l)  return l>b.l;
        return pos<b.pos;
    }
}p1[MAXN],p2[MAXN];

int dp[MAXN],c[MAXN*2],bit[MAXN*2];
int n,tot;

void update(int i,int v)
{
    for(;i<tot+10;i+=lowbit(i))
        bit[i]=max(bit[i],v);
}

int getsum(int i)
{
    int ans=0;
    for(;i;i-=lowbit(i))
        ans=max(ans,bit[i]);
    return ans;
}

void clear(int i)
{
    for(;i<tot+10;i+=lowbit(i))
        bit[i]=0;
}

void cdq(int l,int r)
{
    if(l==r)
    {
        dp[a[l].idx]=max(dp[a[l].idx],1);
        return;
    }
    int mid=MID(l,r);
    cdq(mid+1,r);
    for(int i=l;i<=mid;i++)
        p1[i]=P(a[i].l,a[i].r,i);
    for(int i=mid+1;i<=r;i++)
        p2[i]=P(a[i].l,a[i].r,i);
    sort(p1+l,p1+mid+1);
    sort(p2+mid+1,p2+r+1);
    for(int i=mid,j=r;i>=l;i--)
    {
        while(j>mid && p2[j].r>=p1[i].r)
        {
            update(p2[j].l,dp[p2[j].pos]);j--;
        }
        dp[p1[i].pos]=max(dp[p1[i].pos],getsum(p1[i].l)+1);
    }
    for(int i=mid+1;i<=r;i++)
        clear(p2[i].l);
    cdq(l,mid);
}

int main()
{
    while(read(n))
    {
        tot=0;
        for(int i=1;i<=n;i++)
            read(a[i].l),c[tot++]=a[i].l;
        for(int i=1;i<=n;i++)
            read(a[i].r),c[tot++]=a[i].r;
        for(int i=1;i<=n;i++)
            a[i].idx=i;
        sort(c,c+tot);
        tot=unique(c,c+tot)-c;
        for(int i=1;i<=n;i++)
        {
            a[i].l=lower_bound(c,c+tot,a[i].l)-c+1;
            a[i].r=lower_bound(c,c+tot,a[i].r)-c+1;
        }
        for(int i=0;i<n+10;i++) dp[i]=1;
        cdq(1,n);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dp[i]);
        write(ans),putchar('\n');
        int pre=0;
        for(int i=1;i<=n;i++)
            if(dp[i]==ans && (pre==0 || (a[pre].l>=a[i].l && a[pre].r<=a[i].r)))
            {
                ans--;pre=i;
                write(i);putchar(ans?' ':'\n');
            }
    }
    return 0;
}
