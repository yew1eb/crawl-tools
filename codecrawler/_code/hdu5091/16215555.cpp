#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;

struct Mark
{
    int x,y,s;
}mark[30010];

struct node
{
    int l,r,x,lazy;
}data[200010];

bool cmp(Mark a, Mark b)
{
    if (a.x!=b.x)
    return a.x<b.x;
    else
        return a.s>b.s;
}

int Max(int a,int b)
{
    if (a<b) return b;
    else return a;
}

void build(int l,int r,int k)
{
    int mid;

    data[k].l=l;
    data[k].r=r;
    data[k].x=0;
    data[k].lazy=0;

    if (l==r) return ;
    mid=(l+r)/2;

    build(l,mid,k*2);
    build(mid+1,r,k*2+1);
}

void updata(int l,int r,int k,int op)
{
    int mid;
    if (data[k].l==l && data[k].r==r)
    {
        data[k].x+=op;
        data[k].lazy+=op;
        return ;
    }

    if (data[k].lazy!=0)
    {
        data[k*2].x+=data[k].lazy;
        data[k*2].lazy+=data[k].lazy;
        data[k*2+1].x+=data[k].lazy;
        data[k*2+1].lazy+=data[k].lazy;
        data[k].lazy=0;
    }

    mid=(data[k].l+data[k].r)/2;

    if (r<=mid) updata(l,r,k*2,op);
    else
        if (l>mid) updata(l,r,k*2+1,op);
    else
    {
        updata(l,mid,k*2,op);
        updata(mid+1,r,k*2+1,op);
    }

    data[k].x=Max(data[k*2].x,data[k*2+1].x);
}
int main()
{
    int n,w,h,i,x,y,ans;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<0) break;
        scanf("%d%d",&w,&h);
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            x+=20000;
            y+=20000;
            mark[i*2].x=x;
            mark[i*2].y=y;
            mark[i*2].s=1;
            mark[i*2+1].x=x+w;
            mark[i*2+1].y=y;
            mark[i*2+1].s=-1;
        }
        sort(mark,mark+n*2,cmp);
        build(0,40000,1);

        ans=0;
        for (i=0;i<n*2;i++)
        {
            y=mark[i].y+h;
            if (y>40000) y=40000;
            updata(mark[i].y,y,1,mark[i].s);
            ans=Max(ans,data[1].x);
        }
        printf("%d\n",ans);

    }
    return 0;
}