#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=810;
struct SNode
{
    int l;
    int r;
    int smax;
    int smin;
    int getmid()
    {
        return (l+r)>>1;
    }
};
struct Node
{
    int l;
    int r;
    SNode t[maxn*4];
    int getmid()
    {
        return (l+r)>>1;
    }
}t[maxn*4];
int n,m,a[maxn][maxn];
void BuildY(int l,int r,int index,int p,int flag)
{
    t[p].t[index].l=l;
    t[p].t[index].r=r;
    if(l==r)
    {
        if(flag)
        {
            t[p].t[index].smax=max(t[p<<1].t[index].smax,t[p<<1|1].t[index].smax);
            t[p].t[index].smin=min(t[p<<1].t[index].smin,t[p<<1|1].t[index].smin);
        }
        else
            t[p].t[index].smin=t[p].t[index].smax=a[t[p].l][l];
        return;
    }
    int mid=(l+r)>>1;
    BuildY(l,mid,index<<1,p,flag);
    BuildY(mid+1,r,index<<1|1,p,flag);
    t[p].t[index].smax=max(t[p].t[index<<1].smax,t[p].t[index<<1|1].smax);
    t[p].t[index].smin=min(t[p].t[index<<1].smin,t[p].t[index<<1|1].smin);
}
void BuildX(int l,int r,int index)
{
    t[index].l=l;
    t[index].r=r;
    if(l==r)
    {
        BuildY(1,n,1,index,0); 
        return;
    }
    int mid=t[index].getmid();
    BuildX(l,mid,index<<1);
    BuildX(mid+1,r,index<<1|1);
    BuildY(1,n,1,index,1);
}
int QueryMaxY(int l,int r,int index,int p)
{
    if(t[p].t[index].l==l&&t[p].t[index].r==r)
        return t[p].t[index].smax;
    int mid=t[p].t[index].getmid();
    if(r<=mid)
        return QueryMaxY(l,r,index<<1,p);
    else if(l>mid)
        return QueryMaxY(l,r,index<<1|1,p);
    else
        return max(QueryMaxY(l,mid,index<<1,p),QueryMaxY(mid+1,r,index<<1|1,p));
}
int QueryMaxX(int l,int r,int x,int y,int index)
{
    if(t[index].l==l&&t[index].r==r)
        return QueryMaxY(x,y,1,index);
    int mid=(t[index].l+t[index].r)>>1;
    if(r<=mid)
        return QueryMaxX(l,r,x,y,index<<1);
    else if(l>mid)
        return QueryMaxX(l,r,x,y,index<<1|1);
    else
        return max(QueryMaxX(l,mid,x,y,index<<1),QueryMaxX(mid+1,r,x,y,index<<1|1));
}
int QueryMinY(int l,int r,int index,int p)
{
    if(t[index].l==l&&t[index].r==r)
        return t[p].t[index].smin;
    int mid=(t[p].t[index].l+t[p].t[index].r)>>1;
    if(r<=mid)
        return QueryMinY(l,r,index<<1,p);
    else if(l>mid)
        return QueryMinY(l,r,index<<1|1,p);
    else
        return min(QueryMinY(l,mid,index<<1,p),QueryMinY(mid+1,r,index<<1|1,p));
}
int QueryMinX(int l,int r,int x,int y,int index)
{
    if(t[index].l==l&&t[index].r==r)
        return QueryMinY(x,y,1,index);
    int mid=(t[index].l+t[index].r)>>1;
    if(r<=mid)
        return QueryMinX(l,r,x,y,index<<1);
    else if(l>mid)
        return QueryMinX(l,r,x,y,index<<1|1);
    else
        return min(QueryMinX(l,mid,x,y,index<<1),QueryMinX(mid+1,r,x,y,index<<1|1));
}
void ModifyY(int y,int index,int val,int p,int flag)
{
    if(t[p].t[index].l==t[p].t[index].r)
    {
        if(!flag)
            t[p].t[index].smin=t[p].t[index].smax=val;
        else
        {
            t[p].t[index].smin=min(t[p<<1].t[index].smin,t[p<<1|1].t[index].smin);
            t[p].t[index].smax=max(t[p<<1].t[index].smax,t[p<<1|1].t[index].smax);
        }
        return;
    }    
    int mid=(t[p].t[index].l+t[p].t[index].r)>>1;
    if(y<=mid)
        ModifyY(y,index<<1,val,p,flag);
    else
        ModifyY(y,index<<1|1,val,p,flag);
    t[p].t[index].smax=max(t[p].t[index<<1].smax,t[p].t[index<<1|1].smax);
    t[p].t[index].smin=min(t[p].t[index<<1].smin,t[p].t[index<<1|1].smin);
}
void ModifyX(int x,int y,int index,int val)
{
    if(t[index].l==t[index].r)
    {
        ModifyY(y,1,val,index,0);
        return;
    }
    int mid=(t[index].l+t[index].r)>>1;
    if(x<=mid)
        ModifyX(x,y,index<<1,val);
    else
        ModifyX(x,y,index<<1|1,val);
    ModifyY(y,1,val,index,1);
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        BuildX(1,n,1);
        scanf("%d",&m);
        printf("Case #%d:\n",cas++);
        while(m--)
        {
            int x,y,l;
            scanf("%d%d%d",&x,&y,&l);
            int sx=max(1,x-l/2);
            int sy=max(1,y-l/2);
            int mx=min(n,x+l/2);
            int my=min(n,y+l/2);
            int smax=QueryMaxX(sx,mx,sy,my,1);
            int smin=QueryMinX(sx,mx,sy,my,1);
            printf("%d\n",(smax+smin)>>1);
            ModifyX(x,y,1,(smax+smin)>>1);
        }
    }
    return 0;
}
