#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
 
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL __int64
#define inf -100000000000000000

const int maxn = 111111;
struct point 
{
    __int64 jiji,ouou,jiou,ouji;
};


point pp[maxn<<2]; 
int jiou[maxn<<2];


point big(point a,point b)
{
    point c;
    c.jiji=max(a.jiji,b.jiji);
    c.jiji=max(c.jiji,a.jiji+b.ouji);
    c.jiji=max(c.jiji,a.jiou+b.jiji);
    c.jiji=max(c.jiji,inf);


    c.jiou=max(a.jiou,b.jiou);
    c.jiou=max(c.jiou,a.jiji+b.ouou);
    c.jiou=max(c.jiou,a.jiou+b.jiou);
    c.jiou=max(c.jiou,inf);

    c.ouji=max(a.ouji,b.ouji);
    c.ouji=max(c.ouji,a.ouji+b.ouji);
    c.ouji=max(c.ouji,a.ouou+b.jiji);
    c.ouji=max(c.ouji,inf);


    c.ouou=max(a.ouou,b.ouou);
    c.ouou=max(c.ouou,a.ouji+b.ouou);
    c.ouou=max(c.ouou,a.ouou+b.jiou);
    c.ouou=max(c.ouou,inf);
    return c;
}


void PushUp(int rt) {
    pp[rt]=big(pp[rt<<1],pp[rt<<1|1]);
}

int kk=1;
void build(int l,int r,int rt) {
    if (l == r) {
        if(kk&1)
        {
            jiou[rt]=1;
            scanf("%I64d",&pp[rt].jiji);
            pp[rt].ouou=inf;
            pp[rt].ouji=inf;
            pp[rt].jiou=inf;
        }
        else
        {
            jiou[rt]=0;
            scanf("%I64d",&pp[rt].ouou);
            pp[rt].jiou=pp[rt].jiji=pp[rt].ouji=inf;
        }
        kk++;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int c,int l,int r,int rt) {
    if (l==r&&l==L) { 
        if(jiou[rt]==1)
            pp[rt].jiji=c;
        if(jiou[rt]==0)
            pp[rt].ouou=c;
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L , c , lson);
    else
        update(L  , c , rson);
    PushUp(rt);
}
point query(int L,int R,int l,int r,int rt) {
    if (L <= l && r <= R) { 
        return pp[rt];
    }

    int m = (l + r) >> 1;

    if(L<=m&&m<R)  return big( query(L , R , lson),query(L , R , rson));
    if(L<=m) return query(L , R , lson);
    if(m<R) return query(L , R , rson);
      
}
int main() {
    int t;
    int n,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        kk=1;
        if(n)
        build(1 , n , 1);
        while(q--)
        {
            int op; 
            int a,b;
            scanf("%d",&op);
            scanf("%d%d",&a,&b);
            if(n==0)
            {
                if(op==0)
                    puts("0"); 
                continue;
            }
            
            if(op==0)
            {
                if(a>b)
                    swap(a,b);
                point ppp=query(a,b,1,n,1);
                printf("%I64d\n",max(ppp.jiji,max(ppp.jiou,max(ppp.ouji,ppp.ouou))));
            }
            else
                update(a , b , 1 , n , 1);
        } 
    } 
    return 0;
}
