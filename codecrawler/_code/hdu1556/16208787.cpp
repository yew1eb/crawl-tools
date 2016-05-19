#include"stdio.h"
#include"string.h"


struct segtree
{
    int l,r;
    int mid;
    int count;
}T[300011];


void construct(int l,int r,int k)
{
    T[k].l=l;
    T[k].r=r; 
    T[k].mid=(l+r)>>1;
    T[k].count=0;


    if(l==r)    return ;


    construct(l,T[k].mid,2*k);
    construct(T[k].mid+1,r,2*k+1);
}


void insert(int l,int r,int k)
{
    if(T[k].l==l&&T[k].r==r)    {T[k].count++;return ;}


    if(r<=T[k].mid)        insert(l,r,2*k);
    else if(l>T[k].mid)    insert(l,r,2*k+1);
    else
    {
        insert(l,T[k].mid,2*k);
        insert(T[k].mid+1,r,2*k+1);
    }
}


int ans;
void search(int d,int k)
{
    ans+=T[k].count;


    if(T[k].l==T[k].r&&T[k].l==d)    return ;


    if(d<=T[k].mid)    search(d,2*k);
    else            search(d,2*k+1);
}


int main()
{
    int n;
    int i;
    int a,b;


    while(scanf("%d",&n),n)
    {
        construct(1,n,1);


        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            insert(a,b,1);
        }


        for(i=1;i<n;i++)    {ans=0;search(i,1);printf("%d ",ans);}
        ans=0;search(i,1);printf("%d\n",ans);
    }
    return 0;
}