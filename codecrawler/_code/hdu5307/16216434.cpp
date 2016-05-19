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
const ld pi=acosl(-1.0);

struct Complex
{
    ld r,i;
    Complex(){}
    Complex(ld r ,ld i):r(r),i(i) {}
    Complex operator + (const Complex& t) const
    {
        return Complex(r+t.r,i+t.i) ;
    }
    Complex operator - (const Complex& t) const
    {
        return Complex(r-t.r,i-t.i);
    }
    Complex operator * (const Complex& t) const
    {
        return Complex(r*t.r-i*t.i,r*t.i+i*t.r);
    }
}las[MAXN*5],pre[MAXN*5],c[MAXN*5];

void FFT(Complex y[],int n,int rev)//rev=-1è¡¨ç¤ºéåæ¢
{
    for(int i=1,j,k,t; i<n; i++)  //è¿è¡è¶ååæ¢
    {
        for(j=0,k=n>>1,t=i; k; k>>=1,t>>=1) j=j<<1|t&1;
        if(i<j ) swap(y[i],y[j]);
    }
    for ( int s = 2 , ds = 1 ; s <= n ; ds = s , s <<= 1 )
    {
        Complex wn=Complex(cosl(rev*2*pi/s),sinl(rev*2*pi/s)),w=Complex(1,0),t;
        for(int k=0; k<ds; k++,w=w*wn)
        {
            for(int i=k; i<n; i+=s)
            {
                y[i+ds]=y[i]-(t=w*y[i+ds]);
                y[i]=y[i]+t;
            }
        }
    }
    if(rev==-1) for(int i=0; i<n; i++) y[i].r/=n;
}

int n;
ll val[MAXN*5],ans[MAXN*5];
ll pu[MAXN*5];

int main()
{
//    freopen("data.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    for(int i=1;i<=MAXN*3;i++)
        pu[i]=pu[i-1]+1LL*i*(i+1)/2;
    int T,temp;
    read(T);
    while(T--)
    {
        read(n);temp=0;
        int L=1;CLR(ans,0);
        for(int i=1;i<=n;i++)
        {
            read(val[i]);
            val[i]+=val[i-1];
        }

        for (int q=1,h=0;q<=n;q=h+1)
            if(val[q]!=val[q-1])    h=q;
            else
            {
                for(h=q;h<n && val[h+1]==val[q];h++);
                    ans[0]+=pu[h-q+1];
            }
        while(L<=val[n]) L<<=1;
        L<<=1;
        CLR(las,0);CLR(pre,0);CLR(c,0);
        for(int i=1;i<=n;i++)   las[val[i]].r+=i;
        for(int i=1;i<=n;i++)   pre[-val[i-1]+val[n]].r+=1.0;
        FFT(las,L,1);FFT(pre,L,1);
        for(int i=0;i<L;i++)
            c[i]=las[i]*pre[i];
        FFT(c,L,-1);
        for(int i=1;i<L;i++)
            ans[i]+=ll(c[i].r+0.1);
        CLR(las,0);CLR(pre,0);CLR(c,0);
        for(int i=1;i<=n;i++)   las[val[i]].r+=1.0;
        for(int i=1;i<=n;i++)   pre[-val[i-1]+val[n]].r+=i-1;
        FFT(las,L,1);FFT(pre,L,1);
        for(int i=0;i<L;i++)
            c[i]=las[i]*pre[i];
        FFT(c,L,-1);
        for(int i=1;i<L;i++)
            ans[i]-=ll(c[i].r+0.1);
        printf("%lld\n",ans[0]);
        for(int i=1;i<val[n]+1;i++)
            printf("%lld\n",ans[i+val[n]]);
    }
    return 0;
}
