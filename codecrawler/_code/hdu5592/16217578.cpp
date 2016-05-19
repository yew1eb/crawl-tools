#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
const int maxn=55555;
int a[maxn<<2],ans[maxn<<2];
int sum[maxn<<2];
void pushup(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void build(int o,int l,int r)
{
    if(l==r)
    {
        sum[o]=r-l+1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(o);
}
int query(int o,int l,int r,int k)
{
    if(l==r)
    {
        sum[o]=0;
        return l;
    }
    int res;
    int m=(l+r)>>1;
    if(sum[o<<1|1]>=k)
        res=query(rson,k);
    else
        res=query(lson,k-sum[o<<1|1]);
    pushup(o);
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        for(int i=n;i>=1;i--)
        {
            int x=a[i]-a[i-1];
            ans[i]=query(1,1,n,x+1);
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d%c",ans[i],(i==n)?'\n':' ');
        }
    }
    return 0;
}
