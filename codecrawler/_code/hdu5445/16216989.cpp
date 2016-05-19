#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2005;
const int INF = 0x3f3f3f3f;
const int M = 55555;
int t[N],u[N],v[N];
int x[N],y[N],z[N];
int dp1[2][M],dp2[2][M];
int V[N],C[N],tcnt;
void init(){
    memset(dp1,0x3f,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dp1[0][0] = 0;
}
void calc(int a[],int b[],int c[],int id){
    int num = 1;
    int vv = c[id];
    while(vv){
        if(num <= vv){
            V[tcnt] = a[id] * num;
            C[tcnt] = b[id] * num;
            vv -= num;
        }
        else{
            V[tcnt] = a[id] * vv;
            C[tcnt] = b[id] * vv;
            vv = 0;
        }
        num *= 2;
        tcnt ++;
    }
}
void solve(){
    int n,m,p;
    init();
    scanf("%d%d%d",&n,&m,&p);
    p += 155;
    for(int i = 0 ; i < n ; i ++)
        scanf("%d%d%d",&t[i],&u[i],&v[i]);
    for(int i = 0 ; i < m ; i ++)
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    tcnt = 0;
    for(int i = 0 ; i < n ; i ++) calc(u,t,v,i);
    int cur = 0;
    for(int i = 0 ; i < tcnt ; i ++){
        cur ^= 1;
        for(int j = p ; j >= C[i] ; j --)
            dp1[cur][j] = min(dp1[cur ^ 1][j],dp1[cur ^ 1][j - C[i]] + V[i]);
        for(int j = 0 ; j < C[i] ; j ++) dp1[cur][j] = dp1[cur ^ 1][j];
    }
    int Minv = INF;
    for(int i = p - 155 ; i <= p ; i ++) Minv = min(Minv,dp1[cur][i]);
    cur = tcnt = 0;
    for(int i = 0 ; i < m ; i ++) calc(x,y,z,i);
    for(int i = 0 ; i < tcnt ; i ++){
        cur ^= 1;
        for(int j = 50000 ; j >= C[i] ; j --){
            dp2[cur][j] = max(dp2[cur ^ 1][j],dp2[cur ^ 1][j - C[i]] + V[i]);
        }
        for(int j = 0  ; j < C[i] ; j ++) dp2[cur][j] = dp2[cur ^ 1][j];
    }
    int res = -1;
    for(int i = 0 ; i <= 50000 ; i ++)
        if(dp2[cur][i] >= Minv){
            res = i;
            break;
        }
    if(res == -1) printf("TAT\n");
    else printf("%d\n",res);
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}