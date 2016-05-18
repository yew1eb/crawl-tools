/*
 * Author:  xioumu
 * Created Time:  2012/8/4 10:44:31
 * File Name: 1001.CPP
 * solve: 1001.CPP
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long lint;
const int maxint = -1u>>1;
const double esp = 1e-8;
const int maxn = 1007;
int a[maxn][maxn], l[maxn][maxn], r[maxn][maxn], d[maxn][maxn], u[maxn][maxn];
int ans, n, m;
void  init(){
    scanf("%d", &n);
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(d, 0, sizeof(d));
    memset(u, 0, sizeof(u));
    repf (i, 1, n)
        repf (j, 1, n){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0){
                l[i][j] = u[i][j] = 0;
                continue;
            }
            l[i][j] = l[i][j - 1] + a[i][j] ;
            u[i][j] = u[i - 1][j] + a[i][j];
        }
    repd (i, n, 1)
        repd (j, n, 1){
            if(a[i][j] == 0){
                r[i][j] = d[i][j] = 0;
                continue;
            }
            r[i][j] = r[i][j + 1] + a[i][j];
            d[i][j] = d[i + 1][j] + a[i][j];
        }
    
    //repf(i, 1, n){
        //repf(j, 1, n)
            //printf("%d ", r[i][j]);
        //printf("\n");
    //}
}
int f[10 * maxn];
void add(int *f, int i, int value){
    for(; i < 2 * n; f[i] += value, i += (i & (-i)) );
}
int getsum(int *f, int i){
    int s = 0;
    for(; i > 0; s += f[i], i -= (i & (-i) ));
    return s;
}
void gao2(int ox, int oy){
    int k = 1, c[10 * maxn];
    int x = ox, y = oy;
    vector< pair<int, pair<int, int> > > b;
    while(x <= n && y <= n){
        c[k] = k - min(u[x][y], l[x][y]) + 1;
        if(a[x][y] == 1){
            if(k  - 1 != 0) b.push_back( make_pair(k - 1, make_pair(k, 1) ) );
            b.push_back( make_pair(k + min(r[x][y], d[x][y]) - 1, make_pair(k, 2) ) );
            //printf("(%d %d %d %d)\n", a[x][y], r[x][y], d[x][y], k + min(r[x][y], d[x][y]) - 1);
        }
        x++, y++;
        k++;
    }
    sort(b.begin(), b.end());
    x = ox, y = oy, k = 1;
    int j = 0;
    memset(f, 0, sizeof(f));
    while(x <= n && y <= n){
        if(a[x][y] == 1) add(f, c[k] , 1);
        while(j < sz(b) && b[j].first <= k){
            int op = 1;
            if(b[j].second.second == 1) op = -1;
            ans += op * getsum(f, b[j].second.first); 
            //printf("(%d,%d,%d)\n", b[j].first, b[j].second.first, getsum(f, b[j].second.first));
             j++;
        }
        x++, y++, k++;
    }
    while(j < sz(b)){
        ans += getsum(f, b[j].second.first);
        j++;
    }
    //printf("%d %d %d\n", ox, oy, ans);
}
void gao() {
    ans = 0;
    repd (i, n, 1)
        gao2(i, 1);
    repf (i, 2, n)
        gao2(1, i);
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    repf (i, 1, T){
        init();
        printf("Case %d: ", i);
        gao();
    }
    return 0;
}