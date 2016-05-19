#include "stdio.h"
#include "string.h"
const __int64 inf=0x3f3f3f3f3f3f3f3f;
__int64 ans,a[100100];

struct node
{
    int l,r;
    __int64 ee,eo,oe,oo;
}data[400010];

__int64 Max(__int64 a,__int64 b)
{
    if (a<b) return b;else return a;
}

void Pushup(int k)
{
    data[k].ee=Max(-inf,Max(data[k*2].ee+data[k*2+1].oe,data[k*2].eo+data[k*2+1].ee));
    data[k].ee=Max(data[k].ee,data[k*2].ee);
    data[k].ee=Max(data[k].ee,data[k*2+1].ee);

    data[k].oo=Max(-inf,Max(data[k*2].oo+data[k*2+1].eo,data[k*2].oe+data[k*2+1].oo));
    data[k].oo=Max(data[k].oo,data[k*2].oo);
    data[k].oo=Max(data[k].oo,data[k*2+1].oo);

    data[k].eo=Max(-inf,Max(data[k*2].ee+data[k*2+1].oo,data[k*2].eo+data[k*2+1].eo));
    data[k].eo=Max(data[k].eo,data[k*2].eo);
    data[k].eo=Max(data[k].eo,data[k*2+1].eo);

    data[k].oe=Max(-inf,Max(data[k*2].oo+data[k*2+1].ee,data[k*2].oe+data[k*2+1].oe));
    data[k].oe=Max(data[k].oe,data[k*2].oe);
    data[k].oe=Max(data[k].oe,data[k*2+1].oe);
}

void build(int l,int r,int k)
{
    int mid;
    data[k].l=l;
    data[k].r=r;
    if (l==r)
    {
        if (l%2==1)
        {
            data[k].oo=a[l];
            data[k].oe=data[k].eo=data[k].ee=-inf;
        }
        else
        {
            data[k].ee=a[l];
            data[k].oe=data[k].eo=data[k].oo=-inf;
        }
        return ;
    }

    mid=(l+r)/2;

    build(l,mid,k*2);
    build(mid+1,r,k*2+1);

    Pushup(k);
}

void updata(int n,int x,int k)
{
    if (data[k].l==n && data[k].r==n)
    {
        if (data[k].l%2==1)
        {
            data[k].oo=x;
            data[k].eo=data[k].oe=data[k].ee=-inf;
        }
        else
        {
            data[k].ee=x;
            data[k].eo=data[k].oe=data[k].oo=-inf;
        }
        return ;
    }

    if (n<=data[k*2].r) updata(n,x,k*2);
    else updata(n,x,k*2+1);

    Pushup(k);
}

node search(int l,int r,int k)
{
    node temp,t1,t2;
    int mid;
    if (data[k].l==l && data[k].r==r)
    {
        temp.ee=data[k].ee;
        temp.oo=data[k].oo;
        temp.eo=data[k].eo;
        temp.oe=data[k].oe;
        return temp;
    }

    mid=(data[k].l+data[k].r)/2;
    if (r<=mid) return search(l,r,k*2);
    else
        if (l>mid) return search(l,r,k*2+1);
    else
    {
        t1=search(l,mid,k*2);
        t2=search(mid+1,r,k*2+1);
        temp.ee=Max(Max(Max(t1.ee+t2.oe,t1.eo+t2.ee),t1.ee),t2.ee);
        temp.eo=Max(Max(Max(t1.eo+t2.eo,t1.ee+t2.oo),t1.eo),t2.eo);
        temp.oo=Max(Max(Max(t1.oo+t2.eo,t1.oe+t2.oo),t1.oo),t2.oo);
        temp.oe=Max(Max(Max(t1.oo+t2.ee,t1.oe+t2.oe),t1.oe),t2.oe);
        return temp;
    }
}

int main()
{
    int t,n,m,i,op,l,r;
    node mark;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        build(1,n,1);
        while (m--)
        {
            scanf("%d%d%d",&op,&l,&r);
            if (op==0)
            {
                ans=-inf;
                mark=search(l,r,1);
                ans=Max(ans,mark.oo);
                ans=Max(ans,mark.ee);
                ans=Max(ans,mark.eo);
                ans=Max(ans,mark.oe);

                printf("%I64d\n",ans);
            }
            else
                updata(l,r,1);
        }
    }
    return 0;
}
