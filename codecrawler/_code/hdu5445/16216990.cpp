#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
#define ll long long
#define max(a,b) a>b?a:b
const int INF = 0x3f3f3f3f;
const int MAXN = 50010;
const int N = 205;
int dp[MAXN], pd[MAXN];
struct node{
    int t,u;
    void init(int _t, int _u){
        t = _t, u =_u;
    }
}de[N*N];
struct point{
    int x,y,z;
    void init(int _x, int _y){
        x = _x, y = _y;
    }
}ca[N*N];
int main(){
    //freopen("in.txt","r",stdin);
    int T, n, m, p;
    int cot, cot2, mx, minc, minv;
    int t, u, v, x, y, z;
    scanf("%d",&T);
    while(T--){
        mx = 0;
        minv = minc =INF;
        cot  = cot2 = 0;
        memset(pd, 0, sizeof(pd));
        scanf("%d%d%d",&n,&m,&p);
        memset(dp,0x3f,sizeof(int)*(p+105));
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d",&t, &u, &v);
            int k = 1;
            while(k < v){
                de[cot++].init(k*t, k*u);
                v -= k;
                k *= 2;
            }
            if(v)de[cot++].init(v*t, v*u);
        }
        dp[0] = 0;
        //ç¬¬ä¸æ¬¡DPæ¾åºè½è¾¾å°pè½éçæå°ä½ç§¯
        for(int i = 0; i < cot; i++){
            for(int j = p+100; j >= de[i].t; j--){
                dp[j] = min(dp[j], dp[j - de[i].t] + de[i].u);
                if(j >= p){
                    if(minv > dp[j]){
                        minv = dp[j];
                    }
                }
            }
        }
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d",&x, &y, &z);
            int k = 1;
            mx += x*z;
            while(k < z){
                ca[cot2++].init(x*k,y*k);
                z -= k;
                k *= 2;
            }
            if(z)ca[cot2++].init(x*z,y*z);
        }
        if(mx < minv){
            puts("TAT");
            continue;
        }
        //ç¬¬äºæ¬¡DPæ¾åºè½è¾¾å°æå°ä½ç§¯çæå°è´¹ç¨
        for(int i = 0; i < cot2; i++){
            for(int j = 50000; j >= ca[i].y; j--){
                pd[j] = max(pd[j], pd[j-ca[i].y] + ca[i].x);
                if(pd[j] >= minv){
                    minc = min(minc,j);
                }
            }
        }
        if(minc<=50000)printf("%d\n",minc);
        else puts("TAT");
    }
    return 0;
}
