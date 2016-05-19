#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 2222;
const int mod = 1e9 + 7;

#define MM(a,b,c) memset(a,b,sizeof(a[0]) * ((c) + 2));

struct Node{
    static int h,w,m;
    int x1,y1,x2,y2,v;
    void add(){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&v);
    }
    Node operator + (const Node &a)const{
        Node ret;
        ret.x1 = max(x1,a.x1);
        ret.x2 = min(x2,a.x2);
        ret.y1 = max(y1,a.y1);
        ret.y2 = min(y2,a.y2);
        ret.v = min(v,a.v);
        return ret;
    }
    int getarea(){
        if(x2 < x1) return 0;
        if(y2 < y1) return 0;
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    void init(){
        x1 = 1,y1 = 1;
        x2 = h;y2 = w;
        v = m;
    }
}nd1[11],nd2[N];
int cnt[N],ok[N];
int dp[2][N],txt = 1;
int Node::h = 0,Node::w = 0,Node::m = 0;
int Pow(int a,int b){
    int ret = 1;
    if(a == 0 || a == 1) return a;
    while(b){
        if(b & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ret;
}
inline void add(int &x,int y){
    x += y;
    if(x >= mod) x -= mod;
}
void solve(){
    int h,w,m,n;
    scanf("%d%d%d%d",&h,&w,&m,&n);
    Node::h = h;Node::w = w;Node::m = m;
    int lim = 1 << n;
    for(int i = 0 ; i < n ; i ++) nd1[i].add();
    for(int i = 0 ; i < n ; i ++) nd2[(1 << i)] = nd1[i];
    nd2[0].init();
    for(int i = 1 ; i < lim ; i ++){
        if((i - (i & -i)) == 0) continue;
        nd2[i] = nd2[i - (i & -i)] + nd2[(i & -i)];
    }
    for(int i = lim - 1 ; i >= 0 ; i --){
        ok[i] = 0;
        cnt[i] = nd2[i].getarea();
        for(int j = i + 1 ; j < (1 << n) ; j ++){
            if((j ^ i) & i) continue;
            cnt[i] -= cnt[j];
        }
        for(int j = 0 ; j < n ; j ++)
            if((i & (1 << j)) && nd2[i].v == nd1[j].v) ok[i] |= (1 << j);
    }
    int cur = 1;
    MM(dp[cur],0,(1 << n));
    dp[cur][0] = 1;
    for(int i = 0 ; i < (1 << n) ; i ++){
        if(cnt[i] == 0) continue;
        cur ^= 1;
        MM(dp[cur],0,(1 << n));
        int t1 = Pow(nd2[i].v,cnt[i]);
        int t2 = Pow(nd2[i].v - 1,cnt[i]);
        for(int j = 0 ; j < (1 << n) ; j ++){
            if(dp[cur ^ 1][j] == 0) continue;
            add(dp[cur][j | ok[i]],1ll * dp[cur ^ 1][j] * ((t1 - t2 + mod) % mod) % mod);
            add(dp[cur][j],1ll * dp[cur ^ 1][j] * t2 % mod);
        }
    }
    printf("Case #%d: %d\n",txt ++,dp[cur][(1 << n) - 1]);
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}