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
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL __int64
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
const int mod = 1e9+7 ;
const double eqs = 1e-9 ;
#define maxn 100000+10
#define root 1,n,1
#define int_rt int l,int r,int rt
#define lson l,(l+r)/2,rt<<1
#define rson (l+r)/2+1,r,rt<<1|1
int cl1[maxn<<2] , cl2[maxn<<2] ;
int a[maxn] , ans[maxn] , vis[maxn] , id[maxn] , flag[maxn];
void push_up1(int rt) {
    cl1[rt] = max(cl1[rt<<1],cl1[rt<<1|1]) ;
    return ;
}
void create(int_rt) {
    if( l == r ) {
        scanf("%d", &a[l]) ;
        cl1[rt] = a[l] ;
        id[ a[l] ] = l ;
        return ;
    }
    create(lson) ;
    create(rson) ;
    push_up1(rt) ;
    return ;
}
void update1(int k,int_rt) {
    if( l == r ) {
        cl1[rt] = -1 ;
        return ;
    }
    if( (l+r)/2 >= k ) update1(k,lson) ;
    else if( k > (l+r)/2 ) update1(k,rson) ;
    else return ;
    push_up1(rt) ;
}
int query1(int ll,int rr,int_rt) {
    if( rr < l || ll > r ) return -1 ;
    if( ll <= l && rr >= r ) return cl1[rt] ;
    return max( query1(ll,rr,lson) , query1(ll,rr,rson) ) ;
}
void push_up2(int rt) {
    cl2[rt] = max(cl2[rt<<1] , cl2[rt<<1|1]) ;
    return ;
}
void update2(int k,int_rt) {
    if( l == r ) {
        cl2[rt] = l ;
        return ;
    }
    if( k <= (l+r)/2 ) update2(k,lson) ;
    else if( k > (l+r)/2 ) update2(k,rson) ;
    else return ;
    push_up2(rt) ;
    return ;
}
int query2(int ll,int rr,int_rt) {
    if( rr < l || ll > r ) return -1 ;
    if( ll <= l && rr >= r ) return cl2[rt] ;
    return max( query2(ll,rr,lson) , query2(ll,rr,rson) ) ;
}
int main() {
    int t , n , i , j ;
    int k1 , k2 , k3 ;
    int l , r ;
    //freopen("1012.in","r",stdin) ;
   // freopen("23333.txt","w",stdout) ;
    scanf("%d", &t) ;
    while( t-- ) {
        memset(cl1,-1,sizeof(cl1)) ;
        memset(cl2,-1,sizeof(cl2)) ;
        memset(vis,0,sizeof(vis)) ;
        memset(flag,0,sizeof(flag)) ;
        scanf("%d", &n) ;
        create(root) ;
        a[n+1] = -1 ;
        for(i = 1 ; i <= n ; i++) {
                if(i == 715)
                 i = 715 ;
            if( vis[i] == 1 ) continue ;
            l = query2(1,id[i]-1,root) ;
            l++ ;
            if( l <= 0 ) l = 1 ;
            k1 = query1(l,id[i]-1,root) ;
            if( vis[i] == 0 ) k2 = i ;
            else if( vis[i] < 0 && !vis[ -vis[i] ] ) k2 = -vis[i] ;
            else k2 = -1 ;
            k3 = a[ id[i]+1 ] ;
            if( vis[ a[ id[i]+1 ] ] == 1 ) k3 = -1 ;
            if( k1 > k2 && k1 > k3 ) {
                ans[i] = k1 ;
                vis[k1] = 1 ;
                for( j = id[k1] ; j < id[i] ; j++ ) {
                    ans[ a[j] ] = a[j+1] ;
                    vis[ a[j+1] ] = 1 ;
                }
                update2(id[i],root) ;
            }
            else if( k2 > k1 && k2 > k3 ) {
                ans[i] = k2 ;
                vis[ ans[i] ] = 1 ;
                flag[ flag[ k2 ] ] = 0 ;
                flag[k2] = 0 ;
                update2(id[i],root) ;

            }
            else if( k3 > k1 && k3 > k2 ) {
                if( vis[i] == 0 ) {
                    vis[ k3 ] = -i ;
                    ans[i] = k3 ;
                    flag[k3] = i ;
                    flag[i] = k3 ;
                }
                else {
                    if( flag[ k3 ] ) {
                        ans[i] = k3 ;
                        vis[ k3 ] = 1 ;
                        flag[ flag[k3] ] = flag[i] ;
                        flag[ flag[i] ] = flag[k3] ;
                        vis[ flag[k3] ] = vis[i] ;
                        continue ;
                    }
                    else{
                        flag[k3] = flag[i] ;
                        flag[flag[i]] = k3 ;
                        vis[k3] = vis[i] ;
                        ans[i] = k3 ;
                    }
                }
                update1(id[i],root) ;
                update1(id[k3],root) ;
            }
        }
        for(i = 1 ; i < n ; i++)
            printf("%d ", ans[i]) ;
        printf("%d\n", ans[n]) ;
    }
    return 0 ;
}
