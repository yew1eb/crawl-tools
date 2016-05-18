#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn=100001;
int n,m;
int s[maxn<<2],sl[maxn<<2],sr[maxn<<2],ss[maxn<<2];
void pushup(int rt)
{
    s[rt]=s[rt<<1]+s[rt<<1|1];
    sl[rt]=max(s[rt<<1|1]+sl[rt<<1],sl[rt<<1|1]);
    sr[rt]=max(s[rt<<1]+sr[rt<<1|1],sr[rt<<1]);
    ss[rt]=max(ss[rt<<1],ss[rt<<1|1]);
    ss[rt]=max(ss[rt],sl[rt<<1]+sr[rt<<1|1]);
}
void init(int rt,int l,int r)
{
    int m=(l+r)>>1;
    if(l!=r)
    {
        init(rt<<1,l,m);
        init(rt<<1|1,m+1,r);
        pushup(rt);
    }
    else
    {
        scanf("%d",&s[rt]);
        sl[rt]=sr[rt]=ss[rt]=s[rt];
    }
}
void change(int rt,int l,int r,int t,int tt)
{
    if(l==t&&r==t)
    {
        sl[rt]=sr[rt]=ss[rt]=s[rt]=tt;
    }
    else
    {
        int m=(l+r)>>1;
        if(m>=t)
            change(rt<<1,l,m,t,tt);
        else
            change(rt<<1|1,m+1,r,t,tt);
        pushup(rt);
    }
}
int main()
{
    int t,tt;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init(1,1,n);
        while(m--)
        {
            scanf("%d%d",&t,&tt);
            change(1,1,n,t,tt);
            printf("%d\n",ss[1]);
        }
    }
}