#include<stdio.h>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
using namespace std;
const int maxn=100005;
const int inf=1<<29;
int n,m,t;
long long sum[500000],M;

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]*sum[rt<<1|1]%M;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int i,int add,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=add;
        return ;
    }
    int m=(l+r)>>1;
    if(i<=m)
        update(i,add,lson);
    else
        update(i,add,rson);
    pushup(rt);
}
long long query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    long long res=1;
    if(L<=m)
        res=(res*query(L,R,lson))%M;
    if(R>m)
        res=(res*query(L,R,rson))%M;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cout<<"Case #"<<p<<":"<<endl;
        cin>>n>>M;
        build(1,n,1);
        for(int i=1;i<=n;i++)
        {
            int op,x;
            cin>>op>>x;
            if(op==1)
            {
                update(i,x,1,n,1);
                cout<<query(1,i,1,n,1)<<endl;
            }
            else
            {
                update(x,1,1,n,1);
                cout<<query(1,i,1,n,1)<<endl;
            }
        }
    }
    return 0;
}
