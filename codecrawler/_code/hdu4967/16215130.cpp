#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
#define Maxn 50100

int n,a[Maxn],b[Maxn],o[Maxn],pos[Maxn],r[Maxn],tim[Maxn];

int getpos(int j){
    int l=1,r=n,m;
    while(l<=r){
        m=l+r>>1;
        if (tim[m]==j) return m;
        else if (tim[m]>j) r=m-1;
        else l=m+1;
    }
}

struct segtree{int l,r,sum,rmax;}t[Maxn*4];

inline void update(int p){
    if (t[p].l==t[p].r) return;
    t[p].sum=t[ls].sum+t[rs].sum;
    t[p].rmax=max(t[rs].rmax,t[ls].rmax+t[rs].sum);
}

void build(int l,int r,int p){
    t[p].l=l;t[p].r=r;
    t[p].sum=0;t[p].rmax=0;
    if (l==r) return;
    int m=l+r>>1;
    build(l,m,ls);
    build(m+1,r,rs);
}

void insert(int u,int p,int val){
    if (t[p].l==t[p].r){
        t[p].sum+=val;
        t[p].rmax=t[p].sum;
        return;
    }
    int m=t[p].l+t[p].r>>1;
    if (u<=m)insert(u,ls,val);
    else insert(u,rs,val);
    update(p);
}

int query(int l,int r,int p,int sum,int &tsum){
    int m=t[p].l+t[p].r>>1;
    int tsum1=0;
    if (t[p].l==l&&t[p].r==r){
        tsum=t[p].sum;
        if (sum+t[p].rmax<=0) return -1;
        else{
            if (t[p].l==t[p].r) return t[p].l;
            if (sum+t[rs].rmax>0) return query(m+1,r,rs,sum,tsum1);
            else if(sum+t[rs].sum+t[ls].rmax>0) return query(l,m,ls,sum+t[rs].sum,tsum1);
        }
    }
    int ret;
    if (r<=m) {ret=query(l,r,ls,sum,tsum1);tsum=tsum1;}
    else if (l>m) {ret=query(l,r,rs,sum,tsum1);tsum=tsum1;}
    else{
        int tsum2=0,tmp1,tmp2;
        tmp1=query(m+1,r,rs,sum,tsum1);
        tsum2=tsum1;
        tmp2=query(l,m,ls,sum+tsum1,tsum1);
        tsum2+=tsum1;
        tsum=tsum2;
        if (tmp1==-1) ret=tmp2;
        else ret=tmp1;
    }
    return ret;
}

void init(){
    int i;
    for(i=1;i<=n;++i){
        if (o[i]==1) tim[i]=b[i];
        else tim[i]=a[i];
    }
    sort(tim+1,tim+n+1);

    for(i=1;i<=n;++i){
        if (o[i]==1) {pos[i]=getpos(b[i]);r[pos[i]]=i;}
        else {pos[i]=getpos(a[i]);r[pos[i]]=i;}
    }
    build(1,n,1);
}


char s[50];

int main(){
    //freopen("4967in.txt","r",stdin);
    int cas,i;
    cas=0;
    while(scanf("%d",&n)&&n){
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        for(i=1;i<=n;++i){
            scanf("%s",s);

            if (s[1]=='u') o[i]=1;
            else if (s[1]=='o') o[i]=2;
            else o[i]=3;
            if (o[i]==1) scanf("%d%d",&a[i],&b[i]);
            else scanf("%d",&a[i]);
        }
        init();

        printf("Case #%d:\n",++cas);
        for(i=1;i<=n;++i){
            if (o[i]==1){
                insert(pos[i],1,1);
            }
            else if (o[i]==2){
                insert(pos[i],1,-1);
            }
            else{
                int tsum=0;
                printf("%d\n",a[r[query(1,pos[i],1,0,tsum)]]);
            }
        }
    }
    return 0;
}



