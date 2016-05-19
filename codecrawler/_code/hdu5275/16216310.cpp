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

const int MOD=1000000007;
const int MAXN=3010;

int p[MAXN][2],mul[MAXN][MAXN];
int inv[250010];
int n,m;

ll power(int a,int n)
{
    ll ans=1,tmp=a;
    while(n)
    {
        if(n&1)
            ans=ans*tmp%MOD;
        tmp=tmp*tmp%MOD;
        n>>=1;
    }
    return ans;
}

void preprocess()
{
    for(int i=1;i<=n;i++)
    {
        mul[i][i]=1;
        for(int j=i+1;j<=n;j++)
        {
            mul[i][j]=1LL*mul[i][j-1]*inv[abs(p[i][0]-p[j][0])]%MOD*(p[i][0]<p[j][0]?-1:1);
            if(mul[i][j]<0) mul[i][j]+=MOD;
        }
        for(int j=i-1;j>=1;j--)
        {
            mul[i][j]=1LL*mul[i][j+1]*inv[abs(p[i][0]-p[j][0])]%MOD*(p[i][0]<p[j][0]?-1:1);
            if(mul[i][j]<0) mul[i][j]+=MOD;
        }
    }
}

int main()
{
    int l,r,x;
    inv[0]=1;
    for(int i=1;i<250005;i++)
        inv[i]=power(i,MOD-2);
    while(read(n))
    {
        for(int i=1;i<=n;i++)
            read(p[i][0]),read(p[i][1]);
        preprocess();
        read(m);
        while(m--)
        {
            read(l),read(r),read(x);
            int res=0,tot=1;
            for(int i=l;i<=r;i++)
                tot=1LL*tot*(x-p[i][0])%MOD;
            for(int i=l;i<=r;i++)
            {
                int tmp=1LL*p[i][1]*mul[i][l]%MOD*mul[i][r]%MOD;
                if(x!=p[i][0])
                    tmp=1LL*tmp*tot%MOD*inv[abs(x-p[i][0])]%MOD*(x<p[i][0]?-1:1);
                else
                {
                    int t=1;
                    for(int j=l;j<=r;j++)
                        if(i!=j)
                            t=1LL*t*(x-p[j][0])%MOD;
                    tmp=1LL*tmp*t%MOD;
                }
                if(tmp<0)   tmp+=MOD;
                //cout<<tmp<<endl;
                res=(res+tmp)%MOD;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
