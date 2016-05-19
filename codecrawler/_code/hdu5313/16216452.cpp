#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
using namespace std ;
#define LL __int64
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
const int mod = 1e9+7 ;
const double eqs = 1e-9 ;
struct node{
    int u , v ;
    int next ;
}edge[210000] ;
int head[11000] , cnt ;
int a[11000] ;
void add(int u,int v) {
    edge[cnt].u = u ; edge[cnt].v = v ;
    edge[cnt].next = head[u] ; head[u] = cnt++ ;
    edge[cnt].u = v ; edge[cnt].v = u ;
    edge[cnt].next = head[v] ; head[v] = cnt++ ;
}
void dfs(int u) {
    int i , v ;
    for(i = head[u] ; i !=-1 ; i = edge[i].next) {
        v = edge[i].v ;
        if( a[v] != -1 ) continue ;
        a[v] = 1 - a[u] ;
        dfs(v) ;
    }
}
int main() {
    int t , n , m , l_num , r_num;
    int u , v , i , j ;
    scanf("%d", &t) ;
    while(t--) {
        scanf("%d %d", &n, &m) ;
        memset(head,-1,sizeof(head)) ;
        cnt = l_num = r_num = 0 ;
        while( m-- ) {
            scanf("%d %d", &u, &v) ;
            add(u,v) ;
        }
        memset(a,-1,sizeof(a)) ;
        for(i = 1 ; i <= n ; i++) {
            if( a[i] == -1 && head[i] != -1 ) {
                a[i] = 0 ;
                dfs(i) ;
            }
        }
        int num = 0 ;
        for(u = 1 ; u <= n ; u++) {
            if( a[u] == 1 ) r_num++ ;
            else if( a[u] == 0 ) l_num++ ;
            if( a[u] ) continue ;
            for(j = head[u] ; j != -1 ; j = edge[j].next) {
                v = edge[j].v ;
                if( a[v] == 0 ) continue ;
                num++ ;
            }
        }
        int k1 , k2 , c = n-l_num-r_num ;
        k1 = max(l_num,r_num) ;
        k2 = min(l_num,r_num) ;
        if( k1 >= k1 + c ) {
            k1 += c ;
        }
        else {
            c -= k1-k2 ;
            k2 = k1 ;
            k1 += c/2 ;
            k2 += c-c/2 ;
        }
        printf("%d\n", k1*k2-num ) ;
    }
    return 0 ;
}