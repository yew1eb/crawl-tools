/*
* @author FreeWifi_novicer
* language : C++/C
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>

using namespace std;

#define clr( x , y ) memset(x,y,sizeof(x))
#define cls( x ) memset(x,0,sizeof(x))
#define mp make_pair
#define pb push_back
typedef long long lint;
typedef long long ll;
typedef long long LL;

const int maxn = 1005 ;
const int mod = 1e9 + 7 ;
lint C[505][505];
lint b[25] ;
map<int , int>m ;

int n ;
void init(){
    cls( C ) ;
    C[0][0] = 1 ;
    for( int i = 1 ; i <= 500 ; i++ ){
        C[i][0] = 1 ;
        for( int j = 1 ; j <= i ; j++ ){
            C[i][j] = C[i-1][j] + C[i-1][j-1] ;
            if( C[i][j] > mod ) C[i][j] -= mod ;
        }
    }
}

lint work(){
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 2 ; j * j <= b[i] ; j++ ){
            while( b[i] % j == 0 ) {
                m[j] ++ ;
                b[i] /= j ;
            }
        }
        if( b[i] > 1 ) m[b[i]] ++ ;
    }
    map<int,int>::iterator it ;

    lint ans = 1 ;
    for( it = m.begin() ; it != m.end() ; it++ ){
        int num = it->second ;
        ans = ( ans * C[ num + n - 1 ][ n - 1 ] ) % mod ;
    }
    for( int i = 1 ; i < n ; i++ ){
        lint val = C[n][i] ;
        for( it = m.begin() ; it != m.end() ; it++ ){
            int num = it->second ;
            val = ( val * C[ num + n - i - 1 ][ n - i - 1 ] ) % mod ;
        }
        if( i & 1 )
            ans = ( ans - val + mod ) % mod ;
        else
            ans = ( ans + val ) % mod ;
    }
    return ans ;

}
int main(){
//  freopen("input.txt","r",stdin);
    init() ;
    while( cin >> n ){
        m.clear();
        for( int i = 1 ; i <= n ; i++ )
            cin >> b[i] ;
       cout << work() << endl;
    }
    return 0;
}
