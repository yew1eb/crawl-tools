#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1e5+5;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
int a[N],imx[N];
struct Segtree
{
    struct node
    {
        int lft,rht,mx;
        int mid(){return MID(lft,rht);}
    }tree[N*4];
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].mx=0;
        if(lft!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int pos,int ind,int valu)
    {
        if(tree[ind].lft==tree[ind].rht) tree[ind].mx=max(tree[ind].mx,valu);
        else
        {
            int mid=tree[ind].mid();
            if(pos<=mid) updata(pos,LL(ind),valu);
            if(pos> mid) updata(pos,RR(ind),valu);
            tree[ind].mx=max(tree[LL(ind)].mx,tree[RR(ind)].mx);
        }
    }
    int query(int st,int ed,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) return tree[ind].mx;
        else
        {
            int mid=tree[ind].mid();
            int mx1=0,mx2=0;
            if(st<=mid) mx1=query(st,ed,LL(ind));
            if(ed> mid) mx2=query(st,ed,RR(ind));
            return max(mx1,mx2);
        }
    }
}seg;
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        int ans=0,ed=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            ed=max(ed,a[i]);
        }

        seg.build(0,ed,1);
        for(int i=0;i<n;i++)
        {
            if(i-d-1>=0) seg.updata(a[i-d-1],1,imx[i-d-1]);
            if(a[i]>0) imx[i]=seg.query(0,a[i]-1,1)+1;
            else imx[i]=1;
            ans=max(ans,imx[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}