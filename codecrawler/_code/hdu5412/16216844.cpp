#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define maxn 300100
struct node{
    int type, l, r, v , ans;
}p[maxn];
int c[maxn], n, q, cnt, max1;
int a[maxn];
int id1[maxn], id2[maxn];
void p_add(int type, int l,int r, int v) {
    p[cnt].type = type;
    p[cnt].l = l; p[cnt].r = r;
    p[cnt].v = v;
    id1[cnt] = cnt;
    cnt++;
}
int lowbit(int x) {
    return x & -x ;
}
void add(int i,int k) {
    while( i <= n ) {
        c[i] += k ;
        i += lowbit(i) ;
    }
}
int sum(int i) {
    int num = 0 ;
    while( i ) {
        num += c[i] ;
        i -= lowbit(i) ;
    }
    return num ;
}
void solve(int L, int R, int low, int high) {
    if( L > R ) return;
    if( low == high ) {
        while(L <= R) {
            if( p[ id1[L] ].type == 2 ) p[ id1[L] ].ans = low;
            L++;
        }
        return ;
    }
    int i, j, num, l = L, r = R;
    int mid = (low + high)/2;
    for(i = L; i <= R; i++) {
        j = id1[i];
        if( p[j].type == 2 ) {
            num = sum(p[j].r) - sum(p[j].l-1);
            if( num < p[j].v ) {
                p[j].v -= num;
                id2[r--] = j;
            }
            else
                id2[l++] = j;
        }
        else {
            if( p[j].v <= mid ) {
                add(p[j].l,p[j].type);
                id2[l++] = j;
            }
            else
                id2[r--] = j;
        }
    }
    for(i = L; i <= R; i++) {
        j = id1[i];
        if( p[j].type != 2 && p[j].v <= mid ) add(p[j].l,-p[j].type);
    }
    for(i = L; i < l; i++)
        id1[i] = id2[i];
    for(r = R; i <= R; r--, i++)
        id1[i] = id2[r];
    solve(L,l-1,low,mid);
    solve(l,R,mid+1,high);
}
int main() {
    int i, j, type, l, r, v;
    while( scanf("%d", &n) != EOF ) {
        memset(c,0,sizeof(c));
        cnt = max1 = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            p_add(1, i, i, a[i]);
            max1 = max(max1, a[i]);
        }
        scanf("%d", &q);
        while( q-- ) {
            scanf("%d", &type);
            if( type == 1 ) {
                scanf("%d %d", &l, &v);
                p_add(-1, l, l, a[l]);
                a[l] = v;
                p_add(1, l, l, a[l]);
                max1 = max(max1, a[l]);
            }
            else {
                scanf("%d %d %d", &l, &r, &v);
                p_add(2, l, r, v);
            }
        }
        solve(0,cnt-1,0,max1) ;
        for(i = 0; i < cnt; i++) {
            if( p[i].type == 2 )
                printf("%d\n", p[i].ans);
        }
    }
    return 0 ;
}
