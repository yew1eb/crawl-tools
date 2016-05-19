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

const int MAXN=100010;

int t,n;
ll a[MAXN],b[MAXN],sum;
pair<int,int> ans[MAXN];
pair<int,int> temp[MAXN];
int cnt,tot;

int run(int be,int dir,ll* a)
{
    for(int i=0;i<n;i++)
        b[i]=a[i];  
    cnt=0;
    temp[cnt++]=mp(be,(be+dir+n)%n);
    b[be]--;b[(be+dir+n)%n]++;
    for(int i=(be+dir+n)%n;i!=be;i=(i+dir+n)%n)
    {
        if(b[i]>0)
        {
            temp[cnt++]=mp(i,(i+dir+n)%n);
            b[i]--;b[(i+dir+n)%n]++;
        }
        else if(b[i]<0)
        {
            temp[cnt++]=mp((i+dir+n)%n,i);
            b[i]++;b[(i+dir+n)%n]--;
        }
    }
    for(int i=0;i<n;i++)
        if(b[i]!=0)
            return false;
    for(int i=0;i<cnt;i++)
        ans[i]=temp[i];
    return true;
}


int main()
{
    int T;
    read(T);
    while(T--)
    {
        read(n);sum=cnt=0;
        for(int i=0;i<n;i++)
            read(a[i]),sum+=a[i];

        if(sum%n!=0)
        {
            printf("NO\n");
            continue;
        }

        sum/=n;

        for(int i=0;i<n;i++)
            a[i]-=sum;

        if(n==2)
        {
            if(a[0]>=2 || a[0]<=-2)
            {
                printf("NO\n");
                continue;
            }
        }

        for(int i=0;i<n;i++)
            if(a[i]>0)
            {
                if(!run(i,1,a))
                    if(!run(i,-1,a))
                    {
                        printf("NO\n");
                        goto here;
                    }
                break;
            }

        puts("YES");
        write(cnt),putchar('\n');
        for(int i=0;i<cnt;i++)
            write(ans[i].first+1),putchar(' '),write(ans[i].second+1),putchar('\n');
        here:;
    }
    return 0;
}