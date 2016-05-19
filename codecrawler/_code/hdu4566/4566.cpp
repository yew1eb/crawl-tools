#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <ctime>
using namespace std;

typedef long long LL;
const int N = 100000;
const int M = 50;
const LL MAXS = 1LL<<50;
const LL MAXT = (LL)1e16;

inline LL two( int x ) { return 1LL<<x; }

// f means <=, g means >
LL  f[M+1][N+5], g[M+1][N+5], a[N+5];
int rank[2][2][N+5];
int n , m;
LL  s;

void solve( LL t , LL &ans1, LL &ans2) {
   fill( f[0], f[0]+n+1, 0 );
   fill( g[0], g[0]+n+1, 0 );
   f[0][0] = 1;
   int bits[55], bitt[55];
   for( int i = 0 ; i < m; ++i ) {
        bits[i] = (s&two(i))>0;
        bitt[i] = (t&two(i))>0;
   }

   rank[0][0][0] = n;
   rank[0][1][0] = 0;
   for( int i = 1; i <= n; ++i ) {
        rank[0][0][i] = i-1;
   }

   for( int i = 1; i <= m; ++i ) {
        int cur = i&1, pre = cur^1 ;
        fill( f[i], f[i]+n+1, 0 );
        fill( g[i], g[i]+n+1, 0 );

        // radix sort, from large to small
        for( int j = 0 ; j < 2; ++j ) rank[cur][j][0] = 0;
        for( int j = 1 ; j >= 0; –j ) {
             for( int k = 1 ; k <= rank[pre][j][0]; ++k ) {
                  int idx = rank[pre][j][k];
                  if( a[idx] & two(i-1) ) rank[cur][1][ ++rank[cur][1][0] ] = idx ;
                  else rank[cur][0][ ++rank[cur][0][0] ] = idx ;
             }
        }

        int oneCnt = 0, curOnes = rank[cur][1][0], curZeros = rank[cur][0][0];
        // update i bit with i-1 bit
        for( int j = 0; j <= n; ++j ) {
             int idx = -1, presize1 = rank[pre][1][0];
             if( j > presize1 ) {
                 idx = rank[pre][0][j-presize1];
             } else {
                  if( j > 0 ) idx = rank[pre][1][j];
             }

             // when j = 0 ==> idx = -1;
             if( idx != -1 && (a[idx]&two(i-1)) != 0 ) {
                 ++oneCnt;
             }
             int tBit = bitt[i-1];

             // do nothing
             int curOne = curOnes + j – 2*oneCnt;
             if( (curOne&1) == bits[i-1] ) {
                 if( tBit == 0 ) {
                     f[i][ oneCnt ] += f[i-1][j];
                     g[i][ oneCnt ] += g[i-1][j];
                 } else {  // less than
                     f[i][ oneCnt ] += f[i-1][j]+g[i-1][j];
                 }
             }

             // add 1<<(i-1);
             curOne = curZeros – j + 2*oneCnt;
             int nextOne = j + curOnes – oneCnt;
             if( (curOne&1) == bits[i-1] ) {
                 if( tBit == 0 ) {
                     g[i][ nextOne ] += g[i-1][j] + f[i-1][j];
                 } else {  // less than
                     f[i][ nextOne] += f[i-1][j];
                     g[i][ nextOne] += g[i-1][j];
                 }
             }
        }

        //for( int j = 0; j <= n; ++j )  cout<<i<<” “<<j<<” “<<f[i][j]<<” “<<g[i][j]<<endl;
   }
   ans1 = ans2 = 0;
   for( int i = 0 ; i <= n; ++i ) {
        ans1 += f[m][i];
        ans2 += g[m][i];
   }
   ans2 += ans1;
   return ;
}

int main() {
    LL  t;
    //freopen(“CircleGame.in”,”r”,stdin);
    //freopen(“large.out”,”w”,stdout);
    int start = clock();
    //cout<<MAXT<<” “<<MAXS<<endl;
    while( scanf(“%d%d%lld%lld”,&n,&m,&s,&t) != EOF ) {
           //assert( n > 0 && n <= N );
           //assert( m > 0 && m <= M );
           //assert( s >= 0 && s < MAXS );
           //assert( t > 0 && t <= MAXT );
           if( t > MAXT ) {
               cerr<<t<<” “<<MAXT<<endl;
           }
           LL x = 0;
           for( int i = 0 ; i < n; ++i ) {
                scanf(“%lld”,&a[i]);
                x ^= a[i];
                //assert( a[i] >= 0 && a[i] < 1LL<<m );
           }

           LL M = 1LL << m, loops = t/M;
           LL ans1, ans2;
           solve( t%M ,ans1, ans2);
           loops *= ans2;
           loops += ans1;
           if( x == s ) loops–;
           printf(“%lld\n”, loops);
           //printf(“ans1=%lld %lld\n”, ans2, loops);
    }
    //printf(“%lf\n”,(clock()-start)*1.0/CLOCKS_PER_SEC);
    return 0;
}