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

int n;
int c1[MAXN<<1],c2[MAXN<<1];
struct Node
{
    int op;
    int l,r; 
}a[MAXN];

void update(int i,int v,int *c)
{
    for(;i<MAXN*2;i+=lowbit(i))
        c[i]+=v;
}

int getsum(int i,int *c)
{
    int sum=0;
    for(;i;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

int b[MAXN<<1],cnt,num;
int pos[MAXN],pos2[MAXN];

int main()
{
    //freopen("data.txt","r",stdin);
    int cas=1;
    while(read(n))
    {
        CLR(c1,0);CLR(c2,0);
        int op,l,r;
        cnt=0,num=0;
        for(int i=0;i<n;i++)
        {
            read(op),read(l);
            if(op==0)
            {
                num++;
                b[cnt++]=l;
                b[cnt++]=l+num;
            }
            a[i].op=op;a[i].l=l;a[i].r=l+num;
        }
        sort(b,b+cnt);
        cnt=unique(b,b+cnt)-b;
        num=1;
        printf("Case #%d:\n",cas++);
        for(int i=0;i<n;i++)
        {
            if(a[i].op==0)
            {
                l=lower_bound(b,b+cnt,a[i].l)-b+1;
                r=lower_bound(b,b+cnt,a[i].r)-b+1;
                pos[num]=l;pos2[num]=r;num++;
                //cout<<" "<<l<<" "<<r<<endl;
                int num1=getsum(l-1,c1);
                int num2=getsum(r,c2);
                write(num2-num1),putchar('\n');
                update(l,1,c1);
                update(r,1,c2);
            }
            else
            {
                l=a[i].l;
                //cout<<pos[l]<<" "<<pos2[l]<<endl;
                update(pos[l],-1,c1);
                update(pos2[l],-1,c2);
            }
        }
    }
    return 0;
} 