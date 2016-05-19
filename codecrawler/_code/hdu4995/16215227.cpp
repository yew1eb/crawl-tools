/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/12 19:39:45
 |File Name: c.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
struct st{
    int id;
    int x;
    double v;
    int l,r;
}da[100005];
int n,m,k;
bool cmp(st a,st b){
    return a.x < b.x;
}
int u;
map<int,int> ma;
int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        ma.clear();
        rep(i,n){
            scanf("%d%lf",&da[i].x,&da[i].v);
            da[i].id = i+1;
        }
        sort(da,da+n,cmp);
        rep(i,n){
            ma[da[i].id] = i;
        }
        da[0].l = 0;
        da[0].r = 0+k;
        for(int i=1;i<n-1;++i){
            int lx = i-1;
            int rx = i+1;
            int p = k;
            while(p-- > 0){
                if(da[i].x - da[lx].x == da[rx].x - da[i].x){
                    if(da[lx].id < da[rx].id){
                        lx --;
                        if(lx == -1) while(p-- > 0){
                            rx ++;
                        }
                    } else {
                        rx ++;
                        if(rx == n){
                            while(p-- > 0){
                                lx --;
                            }
                        }
                    }
                    continue;   //important!
                }
                if(da[i].x - da[lx].x < da[rx].x - da[i].x){
                    lx --;
                    if(lx == -1) while(p-- > 0){
                        rx ++;
                    }
                }else {
                    rx ++;
                    if(rx == n){
                        while(p-- > 0){
                            lx --;
                        }
                    }
                }
            }
            da[i].l = lx+1;da[i].r = rx-1;
        }
        da[n-1].l = n-1-k;
        da[n-1].r = n-1;
        //rep(i,n) cout<<i<<" "<<da[i].l<<" "<<da[i].r<<endl;
        double sum = 0;
        while(m--){
            scanf("%d",&u);
            int tt = ma[u];
            double su = 0;
            int l = da[tt].l,r = da[tt].r;
            for(int i = l;i<=r;++i) su += da[i].v;
            su -= da[tt].v;
            da[tt].v = su / k;
            sum += da[tt].v;
        }
        printf("%.6lf\n",sum);
    }
    return 0;
}
