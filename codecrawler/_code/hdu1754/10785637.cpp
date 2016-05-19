#include <cstdio>
#include <iostream>
using namespace std;
#define N 200010
int n,u,v,i,m;
int tree[N<<2];
char s,ch;
void build(int l,int r,int rt)
{
    tree[rt]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1 | 1);
}
void update(int w,int key,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=key;
        return;
    }
    int m=(l+r)>>1;
    if(w<=m) update(w,key,l,m,rt<<1);
    if(w>m) update(w,key,m+1,r,rt<<1|1);
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
int query(int L,int R,int l,int r,int rt)
{
    if(l>=L && r<=R) return tree[rt];
    int ans=0,m=(l+r)>>1;
    if(L<=m) ans=max(query(L,R,l,m,rt<<1),ans);
    if(R>m) ans=max(query(L,R,m+1,r,rt<<1|1),ans);
    return ans;
}
int main ()
{
    while (scanf("%d %d%c",&n,&m,&ch)!=-1)
    {
        build(1,n,1);
        for(i=1;i<=n;i++)
        {
            scanf("%d%c",&u,&ch);
            update(i,u,1,n,1);
        }
        //ch=getchar();
        while (m--)
        {
            scanf("%c %d %d%c",&s,&u,&v,&ch);
            if(s=='Q') printf("%d\n",query(u,v,1,n,1));
            if(s=='U') update(u,v,1,n,1);
        }
    }
    
    return 0;
}
