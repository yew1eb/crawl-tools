#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#define clear(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )


using namespace std;
struct node1
{
    long long nsum,fsum;
    int sta,l,r,m; //all none -1 all f 1
} node[100000<<2];
long long f[100];
void build(int l,int r,int tr)
{
    node[tr].nsum=0;
    node[tr].fsum=1;
    node[tr].sta=-1;
    node[tr].l=l;
    node[tr].r=r;
    node[tr].m=(l+r)>>1;
    if(l==r)return;
    int m=(l+r)>>1;
    build(l,m,tr<<1);
    build(m+1,r,tr<<1|1);
    node[tr].fsum=node[tr<<1].fsum+node[tr<<1|1].fsum;
}
void update1(int p,long long num,int tr)
{
    if(node[tr].l==node[tr].r&&node[tr].l==p)
    {
        if(node[tr].sta==1)node[tr].nsum=node[tr].fsum;
        node[tr].nsum+=num;
        int l=2,r=90,i;
        while(l<r)
        {
            i=(l+r)>>1;
            if(f[i]>node[tr].nsum)r=i;
            else l=i+1;
        }
        i=r;
        if(f[i]-node[tr].nsum<node[tr].nsum-f[i-1])node[tr].fsum=f[i];
        else node[tr].fsum=f[i-1];
        node[tr].sta=-1;
        return;
    }
    if(node[tr].sta==1)
    {
        node[tr<<1].sta=1;
        node[tr<<1|1].sta=1;
    }
    if(p>=node[tr].l&&p<=node[tr].m)update1(p,num,tr<<1);
    else if(node[tr].m<p&&p<=node[tr].r)update1(p,num,tr<<1|1);
    node[tr].nsum=node[tr<<1].nsum+node[tr<<1|1].nsum;
    node[tr].fsum=node[tr<<1].fsum+node[tr<<1|1].fsum;
    if(node[tr<<1].sta+node[tr<<1|1].sta==-2)node[tr].sta=-1;
    else if(node[tr<<1].sta+node[tr<<1|1].sta==2)node[tr].sta=1;
    else node[tr].sta=0;
}
void update(int L,int R,int tr)
{
    if(node[tr].sta==1)
    {
        return ;
    }
    if(L<=node[tr].l&&node[tr].r<=R)
    {
        node[tr].sta=1;
        return ;
    }
    if(L<=node[tr].m)update(L,R,tr<<1);
    if(node[tr].m<R)update(L,R,tr<<1|1);
    if(node[tr<<1].sta+node[tr<<1|1].sta==-2)node[tr].sta=-1;
    else if(node[tr<<1].sta+node[tr<<1|1].sta==2)node[tr].sta=1;
    else node[tr].sta=0;
}
long long query(int L,int R,int tr)
{
    if(L<=node[tr].l&&node[tr].r<=R&&node[tr].sta==-1)return node[tr].nsum;
    else if(L<=node[tr].l&&node[tr].r<=R&&node[tr].sta==1)return node[tr].fsum;
    if(node[tr].sta==1)
    {
        node[tr<<1].sta=1;
        node[tr<<1|1].sta=1;
    }
    long long ans=0;
    if(L<=node[tr].m)ans+=query(L,R,tr<<1);
    if(node[tr].m<R)ans+=query(L,R,tr<<1|1);
    if(node[tr<<1].sta+node[tr<<1|1].sta==-2)node[tr].sta=-1;
    else if(node[tr<<1].sta+node[tr<<1|1].sta==2)node[tr].sta=1;
    else node[tr].sta=0;
    return ans;
}
int main()
{
    int n,m;

    f[1]=1;
    f[2]=1;
    for(int i=3; i<93; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    int x,l,r;
    long long tt;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d%I64d",&l,&tt);
                update1(l,tt,1);
            }
            else if(x==2)
            {
                scanf("%d%d",&l,&r);
                printf("%I64d\n",query(l,r,1));
            }
            else
            {
                scanf("%d%d",&l,&r);
                update(l,r,1);
            }
        }
    }
    return 0;
}
