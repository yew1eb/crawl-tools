#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long LL;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

const int N=2e5+5;

set<int> order;
map<int,int> H;
int a[N],pre[N],pos[N],valu[N];

struct Segtree
{
    LL sum[N*4];
    int lKey[N*4],rKey[N*4],delay[N*4];
    void PushUp(int ind)
    {
        lKey[ind]=lKey[LL(ind)];
        rKey[ind]=rKey[RR(ind)];
        sum[ind]=sum[LL(ind)]+sum[RR(ind)];
    }
    void fun(int valu,int lft,int rht,int ind)
    {
        lKey[ind]=rKey[ind]=delay[ind]=valu;
        sum[ind]=valu*(rht-lft+1);
    }
    void PushDown(int ind,int lft,int rht)
    {
        if(delay[ind]!=-1)
        {
            int mid=MID(lft,rht);
            fun(delay[ind],lft,mid,LL(ind));
            fun(delay[ind],mid+1,rht,RR(ind));
            delay[ind]=-1;
        }
    }
    void build(int lft,int rht,int ind)
    {
        sum[ind]=lKey[ind]=rKey[ind]=0; delay[ind]=-1;

        if(lft==rht) lKey[ind]=rKey[ind]=sum[ind]=valu[lft];
        else
        {
            int mid=MID(lft,rht);
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
            PushUp(ind);
        }
    }
    void updata(int st,int ed,int valu,int lft,int rht,int ind)
    {
        if(st<=lft&&rht<=ed) fun(valu,lft,rht,ind);
        else
        {
            PushDown(ind,lft,rht);
            int mid=MID(lft,rht);
            if(st<=mid) updata(st,ed,valu,lft,mid,LL(ind));
            if(ed> mid) updata(st,ed,valu,mid+1,rht,RR(ind));
            PushUp(ind);
        }
    }
    int query(int st,int ed,int valu,int lft,int rht,int ind)
    {
        if(lft==rht)
        {
            if(lKey[ind]>=valu) return lft;
            return -1;
        }
        else
        {
            int mid=MID(lft,rht),pos=-1;
            PushDown(ind,lft,rht);

            if(ed<=mid) pos=query(st,ed,valu,lft,mid,LL(ind));
            else if(st>mid) pos=query(st,ed,valu,mid+1,rht,RR(ind));
            else
            {
                if(lKey[RR(ind)]>=valu) pos=query(st,ed,valu,mid+1,rht,RR(ind));
                else pos=query(st,ed,valu,lft,mid,LL(ind));
            }
            PushUp(ind);
            return pos;
        }
    }
    int getValu(int pos,int lft,int rht,int ind)
    {
        if(lft==rht) return lKey[ind];
        else
        {
            int mid=MID(lft,rht),tmp=0;
            PushDown(ind,lft,rht);
            if(pos<=mid) tmp=getValu(pos,lft,mid,LL(ind));
            else tmp=getValu(pos,mid+1,rht,RR(ind));
            PushUp(ind);
            return tmp;
        }
    }
}seg;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;

        int sc=0;
        order.clear(); H.clear();
        memset(pre,-1,sizeof(pre));

        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(H.find(a[i])==H.end()) { H.insert(make_pair(a[i],sc++)); }
            else { pre[i]=pos[ H[a[i]] ]; }
            pos[H[a[i]]]=i;
        }

        int tmp=0;
        for(int i=n-1;i>=0;i--)
        {
            order.insert(a[i]);
            while(order.find(tmp)!=order.end()) tmp++;
            valu[i]=tmp;
        }

        seg.build(0,n-1,1);

        LL ans=0;

        for(int i=n-1;i>=0;i--)
        {
            ans+=seg.sum[1];
            int st=pre[i]+1,ed=i-1,pos=-1;

            if(st<=ed) pos=seg.query(st,ed,a[i],0,n-1,1);
            if(pos!=-1) seg.updata(st,pos,a[i],0,n-1,1);

            seg.updata(i,n-1,0,0,n-1,1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
