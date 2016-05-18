//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:16777216")

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<cassert>
#define maxim 100
#define LLD long long int
#define LLU long long unsigned
#define HD short int
#define HU short unsigned
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define eps 1e-9
#define rep(i,init,n) for(i=init;i<n;i++)
#define rem(i,init,n) for(i=init;i>n;i--)
#define foreach(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define _abs(a) ((a)<0?(-(a)):(a))
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)
#define STR string
#define LF double
#define IT iterator
#define VI vector<int>
#define VLLD vector<LLD>
#define VS vector<STR>
#define VLF vector<LF>
#define MII map<int,int>
#define MIB map<int,bool>
#define MSI map<STR,int>
#define MSB map<STR,bool>
#define MSS map<STR,STR>
#define M2dII map<int,map<int,int> >
#define QI queue<int>
#define SI stack<int>
#define PII pair< int, int >
#define PPI pair< PII, int >
#define ff first
#define ss second
#define VPII vector<PII>
#define MP make_pair

#define chk(a,k) ((bool)(a&(1<<(k))))
#define set0(a,k) (a&(~(1<<(k))))
#define set1(a,k) (a|(1<<(k)))

#define chkA(a,k) (bool)(a[(k)>>5] & (1<<((k)&31)))
#define setA0(a,k) (a[(k)>>5] &= ~(1<<((k)&31)))
#define setA1(a,k) (a[(k)>>5] |= (1<<((k)&31)))

#define SD(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

using namespace std;

#define DEB(args...) {dbg,args; cerr<<endl;}
struct debugger { template<typename T> debugger& operator,(const T& v) { cerr<<v<<" "; return *this; } } dbg ;

template< class T > T sq(T n) { return n*n; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T power(T N,T P){  return (P==0)?  1: N*power(N,P-1); }

char tmp[100] ;
int allow[100] ;
int in[200] ;
int n,len ;
LLD dp[200][2][2] ;
bool isV[200][2][2] ;

LLD cal(int i, int f, int non0)
{
    if(i==n)        return 1 ;

    if(isV[i][f][non0])       return dp[i][f][non0] ;

    LLD ret = 0 ;
    int j,k ;

    if(f==0)        // open
    {
        //ret += (LLD)len*cal(i+1,0) ;

        rep(j,0,len)
        {
            k = allow[j] ;
            ret += cal(i+1,0,non0||k) ;
        }

        if(allow[0] && non0==0)        ret += cal(i+1,0,non0) ;
    }
    else
    {
        rep(j,0,len)
        {
            k = allow[j] ;

            if(k>=in[i])        break ;

            ret += cal(i+1,0,non0||k) ;
        }

        if(j<len && allow[j]==in[i])
        {
            ret += cal(i+1,1,non0||allow[j]) ;
        }

        if(allow[0] && non0==0)
        {
            if(i!=0)        assert(0) ;
            ret += cal(i+1,0,non0) ;
        }
    }

    isV[i][f][non0] = 1 ;
    return dp[i][f][non0] = ret ;
}

LLD solve(LLD v, LLD b)
{
    n = 0 ;

    if(v==0)
    {
        return 1 ;
    }

    while(v)
    {
        in[n++] = v%b ;
        v /= b ;
    }

    reverse(in,in+n) ;

    int i ;
    //DEB(n) ;

    //rep(i,0,n)  printf("%d",in[i]) ;
    //puts("") ;

    //CLR(isV) ;

    rep(i,0,n)
        CLR(isV[i]) ;

    return cal(0,1,0) ;
}

int main()
{
     int T,t=1,i,j,k;
     LLD x,y ;
     int b ;
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
     //scanf("%d",&T);
     //for(t=1;t<=T;t++)
     while(scanf("%lld",&x)==1 && x!=-1)
     {
         scanf("%lld",&y) ;
         SD(b) ;
         SS(tmp) ;
         len = 0 ;

         for(i=0;tmp[i];i++)
         {
             if(tmp[i]=='S')    allow[len++] = i ;
         }

         LLD ans = solve(y,b) - solve(x-1,b) ;

         printf("%lld\n",ans) ;
         //printf("%lld\n",solve(y,b)) ;
     }

	return 0;
}