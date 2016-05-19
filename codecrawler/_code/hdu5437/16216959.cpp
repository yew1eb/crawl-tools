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

const int maxc = 205 ;
const int maxk = 150000 + 50 ;
struct Fri{
    char name[maxc] ;
    int id , val ;
    bool operator < ( const Fri &a )const{
        if( val != a.val )
            return val < a.val ;
            //return val > a.val ;
        return id > a.id ;
        //return id < a.id ;
    }
} ;
//set<Fri> f ;
priority_queue<Fri>f ;
map<int , int> h ;
int Q[maxk] , ans[maxk] ;
Fri F[maxk] ;
int main(){
    //freopen("input.txt","r",stdin);
    int t ; cin >> t ;
    while( t-- ){
        int k , m , q ;
        cin >> k >> m >> q ;
        for( int i = 1 ; i <= k ; i++ ){
            Fri A ;
            A.id = i ;
            scanf( "%s %d" , A.name , &A.val ) ;
            F[i] = A ;
        }
        for( int i = 1 ; i <= m ; i++ ){
            int open , num ;
            scanf( "%d%d" , &open , &num ) ;
            h[open] += num ;
        }
        for( int i = 1 ; i <= q ; i++ ){
            scanf( "%d" , Q+i ) ;
        }
        int idx = 1 ;
        for( int i = 1 ; i <= k ; i ++ ){
            f.push( F[i] ) ;
            //f.insert( F[i] ) ;
            while( !h.empty() && h.begin()->first == i ){
                int num = h.begin()->second ;
                while( !f.empty() && num-- ){
                    ans[idx++] = f.top().id ;
                    //ans[idx++] = f.begin()->id ;
                    f.pop() ;
                    //f.erase( f.begin() ) ;
                }
                h.erase( h.begin() ) ;
            }
        }
        while( !f.empty() ){
            ans[idx++] = f.top().id ;
            //ans[idx++] = f.begin()->id ;
            f.pop();
            //f.erase( f.begin() ) ;
        }
        for( int i = 1 ; i <= q ; i++ ){
            if( i != q )
                printf( "%s " , F[ans[Q[i]]].name ) ;
            else
                printf( "%s" , F[ans[Q[i]]].name ) ;
        }
        puts("") ;
    }
    return 0;
}
