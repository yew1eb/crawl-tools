#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define lson num<<1,s,mid
#define rson num<<1|1,mid+1,e
#define maxn 1000005

using namespace std;

int color[maxn<<2],cov[maxn<<2];

void pushdown(int num)
{
    if(cov[num])
    {
        cov[num<<1]=cov[num<<1|1]=cov[num];
        color[num<<1]=color[num<<1|1]=color[num];
        cov[num]=0;
    }
}
void pushup(int num)
{
    color[num]=(color[num<<1]|color[num<<1|1]);
}


void build(int num,int s,int e)
{
    color[num]=(1<<2);
    cov[num]=0;
    if(s==e)return;
    int mid=(s+e)>>1;
    build(lson);build(rson);
}

void update(int num,int s,int e,int l,int r,int v)
{
    if(l<=s && r>=e)
    {
        color[num]=v;
        cov[num]=v;
        return;
    }
    int mid=(s+e)>>1;
    pushdown(num);
    if(l<=mid)update(lson,l,r,v);
    if(r>mid)update(rson,l,r,v);
    pushup(num);
}

int query(int num,int s,int e,int l,int r)
{
    if(l<=s && r>=e)
    {
        return color[num];
    }
    int mid=(s+e)>>1;
    pushdown(num);
    if(r<=mid)return query(lson,l,r);
    else if(l>mid)return query(rson,l,r);
    else return (query(lson,l,mid)|query(rson,mid+1,r));
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)break;

        build(1,1,n);
        while(m--)
        {
            char str[5];
            scanf("%s",str);
            if(str[0]=='P')
            {
                int l,r,v;
                scanf("%d%d%d",&l,&r,&v);
                update(1,1,n,l,r,(1<<v));
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                int ans=query(1,1,n,l,r);
                bool first=true;
                for(int i=1;i<=30;i++)
                {
                    if((1<<i)&ans)
                    {
                        if(first){printf("%d",i);first=false;}
                        else printf(" %d",i);
                    }
                }
                puts("");
            }
        }
    }
    return 0;
}