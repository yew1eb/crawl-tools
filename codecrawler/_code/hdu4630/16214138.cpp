#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

const int N=50005;

struct Segtree
{
    int mx[N*4];
    void PushUp(int ind)
    {
        mx[ind]=max(mx[LL(ind)],mx[RR(ind)]);
    }
    void build(int lft,int rht,int ind)
    {
        mx[ind]=0;
        if(lft!=rht)
        {
            int mid=MID(lft,rht);
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int pos,int valu,int lft,int rht,int ind)
    {
        if(lft==rht) mx[ind]=max(mx[ind],valu);
        else
        {
            int mid=MID(lft,rht);
            if(pos<=mid) updata(pos,valu,lft,mid,LL(ind));
            else updata(pos,valu,mid+1,rht,RR(ind));
            PushUp(ind);
        }
    }
    int query(int st,int ed,int lft,int rht,int ind)
    {
        if(st<=lft&&rht<=ed) return mx[ind];
        else
        {
            int mid=MID(lft,rht);
            int mx1=0,mx2=0;
            if(st<=mid) mx1=query(st,ed,lft,mid,LL(ind));
            if(ed> mid) mx2=query(st,ed,mid+1,rht,RR(ind));
            return max(mx1,mx2);
        }
    }
}seg;
struct OP
{
    int st,ed,id;
    OP(){}
    OP(int st,int ed,int id) : st(st),ed(ed),id(id) {}
    bool operator<(const OP &B)const
    {
        return ed<B.ed;
    }
}op[N];

int n,m;
int a[N];
int pre[N];
int res[N];

int main()
{
    //freopen("4630.in","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int st,ed; scanf("%d%d",&st,&ed);
            op[i]=OP(st,ed,i);
        }
        sort(op,op+m);

        seg.build(1,n,1);
        memset(pre,-1,sizeof(pre));

        int ind=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=a[i];j++) if(a[i]%j==0)
            {
                if(pre[j]!=-1)
                {
                    seg.updata(pre[j],j,1,n,1);
                }

                if(pre[a[i]/j]!=-1)
                {
                    seg.updata(pre[a[i]/j],a[i]/j,1,n,1);
                }


                pre[j]=i; pre[a[i]/j]=i;
            }
            
            while(ind<m&&op[ind].ed==i)
            {
                int tmp=seg.query(op[ind].st,i,1,n,1);
                res[ op[ind].id ]=tmp;
                ind++;
            }
        }
        for(int i=0;i<m;i++) printf("%d\n",res[i]);
    }
    return 0;
}