#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=1<<29;
const int maxn=1e5+100;
const int maxm=maxn*4;
struct Node
{
    int l;
    int r;
    int val;
    bool update;
    vector<int> X;
}t[maxm];
int n,a[maxn];
void Build(int l,int r,int index)
{
    t[index].l=l;
    t[index].r=r;
    t[index].update=false;
    t[index].X.clear();
    if(l==r)
    {
        t[index].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    Build(l,mid,index<<1);
    Build(mid+1,r,index<<1|1);
}
void PushDown(int index)
{
    if(t[index].l==t[index].r)
        return;
    if(t[index].update)
    {
        t[index<<1].val=t[index<<1|1].val=t[index].val;
        t[index<<1].update=t[index<<1|1].update=true;
        t[index].update=false;
        t[index<<1].X=t[index].X;
        t[index<<1|1].X=t[index].X;
    }
    else
    {
        int len=t[index].X.size();
        for(int i=0;i<len;i++)
        {
            t[index<<1].X.push_back(t[index].X[i]);
            t[index<<1|1].X.push_back(t[index].X[i]);
        }
    }
    t[index].X.clear();
}
void Update(int l,int r,int index,int val,int op)
{
    PushDown(index);
    //printf("LR %d %d %d %d %d\n",t[index].l,t[index].r,l,r,val);
    if(t[index].l==l&&t[index].r==r)
    {
        if(op==1)
        {
            t[index].val=val;
            t[index].X.clear();
            t[index].update=true;
        }
        else if(op==2)
            t[index].X.push_back(val);
        else
        {
            int len=t[index].X.size();
            for(int i=0;i<len;i++)
                if(t[index].val>t[index].X[i])
                {
                    t[index].val=__gcd(t[index].val,t[index].X[i]);
                    if(t[index].val==1)
                        break;
                }
            a[t[index].l]=t[index].val;
        }
        return;
    }
    int mid=(t[index].l+t[index].r)>>1;
    if(r<=mid)
        Update(l,r,index<<1,val,op);
    else if(l>mid)
        Update(l,r,index<<1|1,val,op);
    else
    {
        Update(l,mid,index<<1,val,op);
        Update(mid+1,r,index<<1|1,val,op);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        Build(1,n,1);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int op,l,r,x;
            scanf("%d%d%d%d",&op,&l,&r,&x);
            if(op==1)
                Update(l,r,1,x,1);
            else
                Update(l,r,1,x,2);
        }
        for(int i=1;i<=n;i++)
            Update(i,i,1,0,3);
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
