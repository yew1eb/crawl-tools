#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include<vector>
#include<bitset>
#include<queue>
using namespace std;
#define N 100010
#define ll __int64

struct node
{
    ll a,b;
}p[N];
const ll mod=1e9+7;
bool cmp(node c,node d)
{
    if(c.a==d.a)
        return c.b<d.b;
    return c.a<d.a;
}
struct pos{
    ll x,f;
}q[N];
ll a[N];
bool comp(pos a,pos b)
{
    if(a.x==b.x)
        return a.f>b.f;
    return a.x<b.x;
}
ll quickpow(ll n,ll m)
{
    ll b=1;
    while(m)
    {
        if(m&1)
            b=b*n%mod;
        m>>=1;
        n=n*n%mod;
    }
    return b;
}
struct Tree
{
    ll sum,quan,sumquan;
    ll l,r;
}tree[4*N];
ll c[N];
void build(ll id,ll x,ll y)
{
    tree[id].l=x,tree[id].r=y;
    tree[id].sum=tree[id].sumquan=0;
    tree[id].quan=1;
    if(x==y)
        return ;
    ll mid=(x+y)>>1;
    build(id<<1,x,mid);
    build(id<<1|1,mid+1,y);
}
void pushdown(ll id)
{
    if(tree[id].l!=tree[id].r)
    {
        tree[id<<1].quan=tree[id<<1].quan*tree[id].quan%mod;
        tree[id<<1|1].quan=tree[id<<1|1].quan*tree[id].quan%mod;
        tree[id].quan=1;
    }
}
void pushup(ll id)
{
    tree[id].sum=(tree[id<<1].sum*tree[id<<1].quan%mod+tree[id<<1|1].sum*tree[id<<1|1].quan%mod)%mod;
    tree[id].sumquan=(tree[id<<1].sumquan*tree[id<<1].quan%mod+tree[id<<1|1].sumquan*tree[id<<1|1].quan%mod)%mod;
}
ll query(ll id,ll x,ll y)
{
    if(tree[id].l==x && tree[id].r==y)
    {
        return (tree[id].sum*tree[id].quan)%mod;
    }
    pushdown(id);
    ll mid=(tree[id].l+tree[id].r)>>1;
    if(y<=mid)
        return query(id<<1,x,y);
    else if(x>=mid+1)
        return query(id<<1|1,x,y);
    else 
        return (query(id<<1,x,mid)+query(id<<1|1,mid+1,y))%mod;
}
ll queryquan(ll id,ll x,ll y)
{
    if(tree[id].l==x && tree[id].r==y)
        return tree[id].sumquan*tree[id].quan%mod;
    pushdown(id);
    ll mid=(tree[id].l+tree[id].r)>>1;
    if(y<=mid)
        return queryquan(id<<1,x,y);
    else if(x>=mid+1)
        return queryquan(id<<1|1,x,y);
    else 
        return (queryquan(id<<1,x,mid)+queryquan(id<<1|1,mid+1,y))%mod;
}
void add(ll id,ll x,ll y)
{
    if(tree[id].l==tree[id].r)
    {
        tree[id].sum=tree[id].sum*tree[id].quan%mod;
        tree[id].quan=1;
        tree[id].sum+=y;
        tree[id].sumquan=tree[id].sum*(c[x])%mod;
        return ;
    }
    pushdown(id);
    ll mid=(tree[id].l+tree[id].r)>>1;
    if(x<=mid)
        add(id<<1,x,y);
    else
        add(id<<1|1,x,y);
    pushup(id);
}
void multi(ll id,ll x,ll y,ll k)
{
    if(tree[id].l==x && tree[id].r==y)
    {
        tree[id].quan=tree[id].quan*k%mod;
        return ;
    }
    pushdown(id);
    ll mid=(tree[id].l+tree[id].r)>>1;
    if(y<=mid)
        multi(id<<1,x,y,k);
    else if(x>mid)
        multi(id<<1|1,x,y,k);
    else 
    {
        multi(id<<1,x,mid,k);
        multi(id<<1|1,mid+1,y,k);
    }
    pushup(id);
}
int main()

{
    ll n;
    while(scanf("%I64d",&n)!=EOF)
    {
        ll i,j,k;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d %I64d",&p[i].a,&p[i].b);
        }
        sort(p+1,p+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            q[i].x=p[i].b;
            q[i].f=i;
        }
        sort(q+1,q+1+n,comp);
        for(i=1;i<=n;i++)
        {
            a[q[i].f]=i;
        }
        ll ans=0;
        build(1,1,n+1);
        for(i=1;i<=n;i++)
            c[i]=quickpow((ll)3,(ll)q[i].x);
        for(i=1;i<=n;i++)
        {
            ll t1=quickpow((ll)2,(ll)p[i].a);
            ll t0=t1;
            ll t2=query(1,1,a[i]);
            t1=t1*quickpow((ll)3,(ll)p[i].b)%mod;
            t1=t1*(t2+1)%mod;
            ans=(ans+t1)%mod;
            ll t3=queryquan(1,a[i]+1,n+1);
            t0=t0*t3%mod;
            ans=(ans+t0)%mod;
            add(1,a[i],t2+1);
            multi(1,a[i]+1,n+1,2);
        }
        printf("%I64d\n",ans);
    }
}