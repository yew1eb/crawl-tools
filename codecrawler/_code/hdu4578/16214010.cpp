#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF (1<<30)
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

const int MOD=10007;
const int N=1e5+5;

int sum1,sum2,sum3,tmp2,tmp3;

struct Segtree
{
    int add[N*4],mult[N*4],same[N*4],sum[N*4][4],sz[N*4];
    void fun_add(int ind,int valu)
    {
        add[ind]=(add[ind]+valu)%MOD;

        sum1=sum[ind][1],sum2=sum[ind][2],sum3=sum[ind][3];

        sum[ind][1]+=(valu*sz[ind])%MOD;
        sum[ind][1]%=MOD;

        tmp2=(valu*valu)%MOD;
        sum[ind][2]+=(2*sum1*valu)%MOD+(tmp2*sz[ind])%MOD;
        sum[ind][2]%=MOD;

        tmp3=(tmp2*valu)%MOD;
        sum[ind][3]+=(3*tmp2*sum1)%MOD+(3*valu*sum2)%MOD+(tmp3*sz[ind])%MOD;
        sum[ind][3]%=MOD;
    }
    void fun_mult(int ind,int valu)
    {
        if(mult[ind]) mult[ind]=(mult[ind]*valu)%MOD;
        else mult[ind]=valu;

        add[ind]=(add[ind]*valu)%MOD;

        sum1=sum[ind][1],sum2=sum[ind][2],sum3=sum[ind][3];

        sum[ind][1]=(sum1*valu)%MOD;

        tmp2=(valu*valu)%MOD;
        sum[ind][2]=(sum2*tmp2)%MOD;

        tmp3=(tmp2*valu)%MOD;
        sum[ind][3]=(sum3*tmp3)%MOD;
    }
    void fun_same(int ind,int valu)
    {
        same[ind]=valu;
        add[ind]=mult[ind]=0;

        sum[ind][1]=(valu*sz[ind])%MOD;

        tmp2=(valu*valu)%MOD;
        sum[ind][2]=(tmp2*sz[ind])%MOD;

        tmp3=(tmp2*valu)%MOD;
        sum[ind][3]=(tmp3*sz[ind])%MOD;
    }
    void PushUp(int ind)
    {
        sum[ind][1]=(sum[LL(ind)][1]+sum[RR(ind)][1])%MOD;
        sum[ind][2]=(sum[LL(ind)][2]+sum[RR(ind)][2])%MOD;
        sum[ind][3]=(sum[LL(ind)][3]+sum[RR(ind)][3])%MOD;
    }
    void PushDown(int ind)
    {
        if(same[ind])
        {
            fun_same(LL(ind),same[ind]);
            fun_same(RR(ind),same[ind]);
            same[ind]=0;
        }
        if(mult[ind])
        {
            fun_mult(LL(ind),mult[ind]);
            fun_mult(RR(ind),mult[ind]);
            mult[ind]=0;
        }
        if(add[ind])
        {
            fun_add(LL(ind),add[ind]);
            fun_add(RR(ind),add[ind]);
            add[ind]=0;
        }
    }
    void build(int lft,int rht,int ind)
    {
        add[ind]=mult[ind]=same[ind]=0;
        sum[ind][1]=sum[ind][2]=sum[ind][3]=0;
        sz[ind]=rht-lft+1;
        if(lft!=rht)
        {
            int mid=MID(lft,rht);
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int st,int ed,int valu,int type,int lft,int rht,int ind)
    {
        if(st<=lft&&rht<=ed)
        {
            if(type==1) fun_add(ind,valu);
            else if(type==2) fun_mult(ind,valu);
            else fun_same(ind,valu);
        }
        else
        {
            PushDown(ind);
            int mid=MID(lft,rht);
            if(st<=mid) updata(st,ed,valu,type,lft,mid,LL(ind));
            if(ed> mid) updata(st,ed,valu,type,mid+1,rht,RR(ind));
            PushUp(ind);
        }
    }
    int query(int st,int ed,int p,int lft,int rht,int ind)
    {
        if(st<=lft&&rht<=ed) return sum[ind][p];
        else
        {
            PushDown(ind);
            int mid=MID(lft,rht),sum1=0,sum2=0;
            if(st<=mid) sum1=query(st,ed,p,lft,mid,LL(ind));
            if(ed> mid) sum2=query(st,ed,p,mid+1,rht,RR(ind));
            PushUp(ind);
            return (sum1+sum2)%MOD;
        }
    }
}seg;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;

        int type,x,y,c;
        seg.build(1,n,1);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&type,&x,&y,&c);
            if(type!=4) seg.updata(x,y,c,type,1,n,1);
            else printf("%d\n",seg.query(x,y,c,1,n,1));
        }
    }
    return 0;
}
