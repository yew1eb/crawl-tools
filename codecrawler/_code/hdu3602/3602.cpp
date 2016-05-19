#include  <stdio.h>
#include <string.h>
#include   <math.h>

#include    <queue>
#include <iostream>
#include   <vector>
#include<algorithm>
#include      <map>
#include  <sstream>

using namespace std;

typedef pair<int , int> pii;


template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

#define     MP(a,b)             make_pair(a,b)
#define     mem(a,b)            memset(a , b , sizeof (a))
#define     lol                 long long
#define     sz(a)               (int)a.size()
#define     llsz(a)             (long long)a.size()
#define     pb(a,b)             a.push_back(b)
#define     c_sq(a)             (int)sqrt(a)
#define     llsq(a)             (long long)sqrt(a)
#define     cl(a)               a.clear()
#define     I_SZ                1000000000000ll
#define     MOD                 100000007
#define     fr                  first
#define     sc                  second
#define     iter(a,b)           for (b=a.begin();b!=a.end();b++)
#define     PI                  2.0*acos(0.0)
#define     all(a)              a.begin(),a.end()
#define     oo                  (1<<30)
#define     popc(a)             __builtin_popcount(a)
#define     lloo 		(1ll<<62)

lol sqr ( lol n ) { return n * n; }
double LOG ( lol a , lol b ) { return ( log(a)/log(b));  }
lol GCD ( lol a , lol b ) { if ( a<0 ) return GCD(-a,b);if ( b<0 ) return GCD ( a , -b ); return (!b)?a:GCD(b,a%b); }
lol LCM ( lol a , lol b ) { if ( a<0 ) return LCM(-a,b);if(b<0) return LCM (a,-b); return (a*(b/GCD(a,b))); }
lol BigMod ( lol B , lol P , lol M ) { if ( !P ) return 1; if ( !(P%2) ) return sqr(BigMod( B , P/2 , M)) % M; return (B%M)*(BigMod(B,P-1,M)) % M;}



///sqrt(1000000000) = 31622.776601683793319988935444327

#define     REP(i,n)                for (i=0;i<n;i++)
#define     REV(i,n)                for (i=n;i>=0;i--)
#define     FOREACH(it,x)           for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define     FOR(i,p,k)              for (i=p; i<k;i++)

#define SZ 1000000

pii dp[100005];
vector < pii > inps;
int n , m , k;

pii findVal ( int cur , pii tag )
{
    if ( tag.sc + cur <= k ) return MP( tag.fr , tag.sc+cur );
    if ( tag.fr+1 <= m && cur <= k ) return MP(tag.fr+1 , cur );
    return MP(1000,100050);
}

int main ( void )
{
    int t_c;
    scanf ("%d",&t_c);

    while ( t_c-- )
    {
        scanf ("%d %d %d",&n,&m,&k);

        int x , y;
        cl ( inps );
        for ( int i=0 ; i<n ; i++ )
        {
            scanf ("%d %d",&x,&y);
            pb ( inps , MP(x,y) );
        }

        for ( int i=0 ; i<100005 ; i++ )
            dp[i] = MP( 100050 , 100050 );
        dp[0] = MP(0,100050);

        for ( int i=0 ; i<n ; i++ )
        {
            for ( int j=10050 ; j>=0 ; j-- )
            {
                if ( j+inps[i].sc <= 10000 )
                {
                    dp[j+inps[i].sc] = min( dp[j+inps[i].sc] , findVal ( inps[i].fr+1 , dp[j] ) );
                }
            }
        }

        for ( int i=10000 ; i>=0 ; i-- )
        {
            if ( dp[i].fr <= m )
            {
                deb ( i );
                break;
            }
        }

    }

    return 0;
}