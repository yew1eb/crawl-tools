#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#define L(rt) (rt<<1)
#define R(rt)  (rt<<1|1)
using namespace std;

const int mod=1000000007;
const int N=50005;
int  num[N];

struct node
{
    int l,r;
    long long ans;
}tree[N*4];

void build(int l,int r,int rt)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].ans=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
    tree[rt].ans=(tree[L(rt)].ans*tree[R(rt)].ans)%mod;
}
long long query(int l,int r,int rt)
{
    if(tree[rt].l==l&&tree[rt].r==r)
    return tree[rt].ans;
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(r<=mid)
    return query(l,r,L(rt));
    else if(l>=mid+1)
    return query(l,r,R(rt));
    else
    {
        long long a=query(l,mid,L(rt));
        long long b=query(mid+1,r,R(rt));
        return (a*b)%mod;
    }
}
void update(int val,int loc,int rt)
{
    if(tree[rt].l==loc&&tree[rt].r==loc)
    {
        tree[rt].ans=val;
        return;
    }
    if(loc<=tree[L(rt)].r)
    update(val,loc,L(rt));
    if(loc>=tree[R(rt)].l)
    update(val,loc,R(rt));
    tree[rt].ans=(tree[L(rt)].ans*tree[R(rt)].ans)%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
        build(1,n,1);
        scanf("%d",&m);
        int op,x,y;
        while(m--)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op==0)
            {
                long long ans=query(x,y,1);
                printf("%lld\n",ans%mod);
            }
            else
            update(y,x,1);
        }          
    }
    return 0;
}