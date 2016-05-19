#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
#define Maxn 50100

struct node{int pos;long long ma;};
struct segtree{int l,r;long long tag,sum;node d;}t[Maxn*4];

void lazy(int p){
    if (t[p].l==t[p].r) return;
    if (t[p].tag!=1){
        t[ls].tag*=t[p].tag;
        t[rs].tag*=t[p].tag;
        t[ls].sum*=t[p].tag;
        t[rs].sum*=t[p].tag;
        t[ls].d.ma*=t[p].tag;t[rs].d.ma*=t[p].tag;
        t[p].tag=1;
    }
    if (t[ls].d.ma>t[rs].d.ma) t[p].d=t[ls].d;
    else t[p].d=t[rs].d;

}

void update(int p){
    if (t[p].l==t[p].r) return;
    if (t[ls].d.ma>t[rs].d.ma) t[p].d=t[ls].d;
    else t[p].d=t[rs].d;
    t[p].sum=t[ls].sum+t[rs].sum;
}

void build(int l,int r,int p){
    t[p].l=l;t[p].r=r;t[p].tag=1;
    if (l==r){
        t[p].d.pos=l;
        t[p].d.ma=1;
        t[p].sum=1;
        return;
    }
    int m=l+r>>1;
    build(l,m,ls);
    build(m+1,r,rs);
    update(p);
}

void add(int pos,int p,long long val){
    if (t[p].l==t[p].r){t[p].sum+=val;t[p].d.ma+=val;return;}
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    if (pos<=m) add(pos,ls,val);
    else add(pos,rs,val);
    update(p);
}

void mul(int l,int r,int p){
    if (t[p].l==l&&t[p].r==r){
        t[p].sum*=2;
        t[p].d.ma*=2;
        t[p].tag*=2;
        return;
    }
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    if (r<=m) mul(l,r,ls);
    else if (l>m) mul(l,r,rs);
    else {
        mul(l,m,ls);
        mul(m+1,r,rs);
    }
    update(p);

}

node query1(int l,int r,int p){
    if (t[p].l==l&&r==t[p].r){
        return t[p].d;
    }
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    node ret;
    if (r<=m) ret=query1(l,r,ls);
    else if (l>m) ret=query1(l,r,rs);
    else{
        node n1=query1(l,m,ls);
        node n2=query1(m+1,r,rs);
        if (n1.ma>n2.ma){
            ret=n1;
        }
        else ret=n2;
    }
    update(p);
    return ret;

}

long long query2(int l,int r,int p){
    if (t[p].l==l&&t[p].r==r){
        return t[p].sum;
    }
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    long long ret;
    if (r<=m) ret=query2(l,r,ls);
    else if (l>m) ret=query2(l,r,rs);
    else{
        ret=query2(l,m,ls)+query2(m+1,r,rs);
    }
    update(p);
    return ret;
}

int n;

int getpos(long long num,int p){
    if (t[p].l==t[p].r) return t[p].l;
    lazy(p);
    int ret;
    if (num>t[ls].sum) {
        ret=getpos(num-t[ls].sum,rs);
    }
    else{
        ret=getpos(num,ls);
    }
    update(p);
    return ret;

}

long long max(long long a,long long b){return a>b?a:b;}

int main(){
    //freopen("1003in.txt","r",stdin);
    int tcas,cas,m,i,l,r;
    long long a,b,ta,tb,ans;
    node nd;
    char s[10];
    scanf("%d",&tcas);
    for(cas=1;cas<=tcas;++cas){
        scanf("%d%d",&n,&m);
        build(1,n,1);
        printf("Case #%d:\n",cas);
        for(i=1;i<=m;++i){
            scanf("%s%I64d%I64d",s,&a,&b);
            if (s[0]=='D'){
                l=getpos(a,1);
                r=getpos(b,1);
                if (l==r){
                    add(l,1,b+1-a);
                }
                else{
                    ta=query2(1,l,1);
                    ta=ta+1-a;
                    long long tc=tb=query2(1,r-1,1);
                    tb=b-tb;
                    add(l,1,ta);
                    add(r,1,tb);
                    l+=1;r-=1;
                    if (l<=r) mul(l,r,1);
                }
            }
            else{
                l=getpos(a,1);
                r=getpos(b,1);
                if (l==r) {
                    printf("%I64d\n",b+1-a);
                }
                else{
                    ta=query2(1,l,1);
                    ta=ta+1-a;
                    tb=query2(1,r-1,1);
                    tb=b-tb;
                    l+=1;
                    r-=1;
                    if (l<=r) {nd=query1(l,r,1);}
                    else nd.ma=0;
                    ans=max(ta,max(tb,nd.ma));
                    printf("%I64d\n",ans);
                }
            }
        }
    }
    return 0;
}
