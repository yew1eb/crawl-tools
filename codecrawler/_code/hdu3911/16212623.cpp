/*
Pro: 0

Sol:

date:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#define maxn 111111
#define lson l, m , rt << 1
#define rson m + 1, r,rt << 1 | 1
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define havem int m = (l + r) >> 1
using namespace std;
int n,Q,ax;
int preb[maxn << 2],sufb[maxn << 2],mxb[maxn << 2];
int prew[maxn << 2],sufw[maxn << 2],mxw[maxn << 2],col[maxn << 2];
int num[maxn];
inline int max(int a, int b) {return a > b? a: b;}
inline int min(int a, int b) {return a < b? a: b;}
void push_up(int rt,int m){
//ç»´æ¤åç¼
    preb[rt] = preb[ls];//åç­äºå·¦å­©å­çåç¼
    prew[rt] = prew[ls];
    if(preb[ls] == m - (m >> 1)) preb[rt] += preb[rs];//å¦æå·¦å­©å­çåç¼é¿åº¦ç­äºå·¦å­©å­åºé´é¿åº¦ï¼
    if(prew[ls] == m - (m >> 1)) prew[rt] += prew[rs];//é£ä¹ï¼å ä¸å³å­©å­çåç¼
//ç»´æ¤åç¼
    sufb[rt] = sufb[rs];//åç­äºå³å­©å­çåç¼
    sufw[rt] = sufw[rs];//æåä¸ªå»ï¼å°±æ¯è¿éåæsufbäºï¼WAäºnæ¬¡åããã
    if(sufb[rs] == (m >> 1))  sufb[rt] += sufb[ls];//å¦æå³å­©å­çåç¼é¿åº¦ç­äºå³å­©å­åºé´é¿åº¦
    if(sufw[rs] == (m >> 1))  sufw[rt] += sufw[ls];//é£ä¹ï¼å ä¸å·¦å­©å­çåç¼
//ç»´æ¤æ¬åºé´æé¿çé¿ä¸²
    mxb[rt] = max(mxb[ls],mxb[rs]);//è¿éä¹éäºã
    mxb[rt] = max(mxb[rt], sufb[ls] + preb[rs]);
    mxw[rt] = max(mxw[ls],mxw[rs]);//æé¿ä¸²è¦ä¸åç¬å¨å·¦å­©å­ï¼è¦ä¸å¨å³å­©å­
    mxw[rt] = max(mxw[rt], sufw[ls] + prew[rs]);//è¦ä¸åæ¶åå¸å¨å·¦å­©å­ãå³å­©å­
}
inline void exchange(int rt){//äº¤æ¢
    swap(preb[rt],prew[rt]);
    swap(sufb[rt],sufw[rt]);
    swap(mxb[rt],mxw[rt]);
}
void push_dn(int rt){
    if(col[rt]){
        col[ls] ^= 1, col[rs] ^= 1, col[rt] = 0;
        exchange(ls);     exchange(rs);//è¿ééäº
    }
}
void build(int l, int r, int rt){
    col[rt] = 0;
    if(l == r){
        scanf("%d",&ax);
        if(ax == 1){//å¦ææ¯é»è²ç
            preb[rt] = sufb[rt] = mxb[rt] = 1;
            prew[rt] = sufw[rt] = mxw[rt] = 0;
        }else{//å¦ææ¯ç½è²ç
            preb[rt] = sufb[rt] = mxb[rt] = 0;
            prew[rt] = sufw[rt] = mxw[rt] = 1;
        }
        return ;
    }havem;
    build(lson); build(rson);
    push_up(rt,r - l + 1);
}
void update(int& L, int& R, int l, int r, int rt){//åºé´æ´æ°
    if(L <= l && r <= R){
        col[rt] ^= 1; exchange(rt);//æ¹åèªèº«ä¹åï¼æ¹ålazyæ å¿
        return ;
    }push_dn(rt);
    havem;
    if(L <= m) update(L,R,lson);
    if(R > m) update(L,R,rson);
    push_up(rt,r - l + 1);
}
int query(int& L, int& R, int l, int r, int rt){
    if(L <= l && r <= R) return mxb[rt];
    push_dn(rt);    havem;
    if(L > m)   return query(L,R,rson);
    if(R <= m) return   query(L,R,lson);
    int t1 = query(L,R,lson);
    int t2 = query(L, R, rson);
    int wa1 = min(m - L + 1, sufb[ls]);//è¿éåéäºä¸¤æ¬¡m - L æå¯¹ï¼æåæL - mäº
    int wa2 = min(R - m, preb[rs]);//åºè¯¥åä¸ä¸ªæå°å¼æè¡ã
    return max(max(t1,t2),wa1 + wa2);
}
int main(){
    int op,a,b;
    while(scanf("%d",&n) != EOF){
        build(1,n,1);
        scanf("%d",&Q);
        for(int i = 1;i <= Q; i ++){
            scanf("%d%d%d",&op,&a,&b);
            if(op == 1){
                update(a,b,1,n,1);
            }else{
                int ans = query(a,b,1,n,1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
