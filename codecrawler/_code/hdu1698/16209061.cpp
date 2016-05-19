#include"stdio.h"

struct segtree
{
    int l,r;
    int mid;
    int val;
    int flag;
}T[300011];

void build(int l,int r,int k)
{
    T[k].l=l;
    T[k].r=r;
    T[k].mid=(l+r)>>1;
    T[k].val=r-l+1;
    T[k].flag=1;

    if(l==r)    return ;

    build(l,T[k].mid,2*k);
    build(T[k].mid+1,r,2*k+1);
}

void update(int flag,int l,int r,int k)
{
    if(T[k].flag==flag)    return ;
    if(T[k].l==l&&T[k].r==r)    {T[k].flag=flag;return ;}
    if(T[k].flag!=-1)
    {
        if(T[k].l<l&&l<=T[k].mid+1)    update(T[k].flag,T[k].l,l-1,2*k);
        else if(l>T[k].mid+1)
        {
            update(T[k].flag,T[k].l,T[k].mid,2*k);
            update(T[k].flag,T[k].mid+1,l-1,2*k+1);
        }
        if(r<T[k].mid)
        {
            update(T[k].flag,r+1,T[k].mid,2*k);
            update(T[k].flag,T[k].mid+1,T[k].r,2*k+1);
        }
        else if(T[k].mid<=r&&r<T[k].r)    update(T[k].flag,r+1,T[k].r,2*k+1);
    }
    if(r<=T[k].mid)        update(flag,l,r,2*k);
    else if(l>T[k].mid)    update(flag,l,r,2*k+1);
    else
    {
        update(flag,l,T[k].mid,2*k);
        update(flag,T[k].mid+1,r,2*k+1);
    }
    if(T[2*k].flag==T[2*k+1].flag&&T[2*k].flag!=-1)    T[k].flag=T[2*k].flag;
    else T[k].flag=-1;
}

int ans;
void search(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r&&T[k].flag!=-1)    {ans+=T[k].flag*(r-l+1);return ;}

    if(r<=T[k].mid)        search(l,r,2*k);
    else if(l>T[k].mid)    search(l,r,2*k+1);
    else
    {
        search(l,T[k].mid,2*k);
        search(T[k].mid+1,r,2*k+1);
    }
}

int main()
{
    int Case,N;
    int n;
    int q;
    int i;
    int a,b,z;
    scanf("%d",&N);
    for(Case=1;Case<=N;Case++)
    {
        scanf("%d%d",&n,&q);

        build(1,n,1);

        for(i=0;i<q;i++)
        {
            scanf("%d%d%d",&a,&b,&z);
            update(z,a,b,1);
        }
        ans=0;
        search(1,n,1);

        printf("Case %d: The total value of the hook is %d.\n",Case,ans);
    }
    return 0;
}