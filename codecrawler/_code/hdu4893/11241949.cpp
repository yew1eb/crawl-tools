#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Lson l,m,rt<<1
#define Rson m+1,r,rt<<1|1
typedef __int64 ll;
int const MAXN = 100010;
ll f[110];
struct Tree{
    int l,r;
    ll v,s;
    int add;
}tree[MAXN*6];
ll abss(ll a){
    return a<0?-a:a;
}
inline void PushUp(int rt){
    tree[rt].v = tree[rt<<1].v + tree[rt<<1|1].v;
    tree[rt].s = tree[rt<<1].s + tree[rt<<1|1].s;
}
inline void PushDown(int rt){
    if(tree[rt].add){
        tree[rt<<1].add = tree[rt].add;
        tree[rt<<1|1].add = tree[rt].add;
        tree[rt<<1].v = tree[rt<<1].s;
        tree[rt<<1|1].v = tree[rt<<1|1].s;
        tree[rt].add = 0;
    }
}
void Build(int l,int r,int rt){
    tree[rt].add = 0;
    tree[rt].v = 0;
    if(l == r){
        tree[rt].s = 1;
        return ;
    }
    int m = (l + r)>>1;
    Build(Lson);
    Build(Rson);
    PushUp(rt);
}
void Update(int k,int d,int l,int r,int rt){
    if(k < l || k > r || rt > (MAXN<<2)) return ;
    if(l == r){
        if(tree[rt].add){
            tree[rt].v = d + tree[rt].s;
            tree[rt].add = 0;
        }
        else tree[rt].v += d;
        int pos = lower_bound(f,f+90,tree[rt].v) - f;
        if(pos == 0)tree[rt].s = 1;
        else if(abss(f[pos] - tree[rt].v) < abss(f[pos - 1] - tree[rt].v)){
             tree[rt].s = f[pos];
        }
        else tree[rt].s = f[pos-1];
        return ;
    }
    PushDown(rt);
    int m = (l + r)>>1;
    if(k <= m) Update(k,d,Lson);
    else Update(k,d,Rson);
    PushUp(rt);
}
void Change(int L,int R,int l,int r,int rt){
    if(R < l || L > r) return ;
    if(L <= l && r <= R){
        tree[rt].v=tree[rt].s;
        tree[rt].add = 1;
        return ;
    }
    PushDown(rt);
    int m = (l + r)>>1;
    if(L <= m) Change(L,R,Lson);
    if(R > m)  Change(L,R,Rson);
    PushUp(rt);
}
ll Query(int L,int R,int l,int r,int rt){
    if(R < l || L > r) return 0;
    if(L <= l && r <= R) return tree[rt].v;
    PushDown(rt);
    int m =(l + r)>>1;
    ll ret = 0;
    if(L <= m) ret += Query(L,R,Lson);
    if(R > m) ret += Query(L,R,Rson);
    return ret;
}
void Init(){
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i <= 90;i++){
        f[i] = f[i - 1] + f[i - 2];
    }
}
int main(){
    Init();
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        Build(1,n,1);
        for(int i =  1;i <= m;i++){
            int x;
            scanf("%d",&x);
            if(x == 1){
                int k,d;
                scanf("%d%d",&k,&d);
                Update(k,d,1,n,1);
            }
            else if(x == 2){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%I64d\n",Query(x,y,1,n,1));
            }
            else if(x == 3){
                int x,y;
                scanf("%d%d",&x,&y);
                Change(x,y,1,n,1);
            }
        }
    }
    return 0;
}

/*
1 1
2 1 1
5 4
1 1 7
1 3 17
3 2 4
2 1 5
*/
