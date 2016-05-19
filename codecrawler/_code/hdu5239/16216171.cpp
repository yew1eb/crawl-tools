#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;
typedef unsigned long long LL;
const int maxn=100010;
const int maxm=30;
const LL MOD=9223372034707292160LL;

LL a[maxn];
int N,M;
LL pow_mul(LL x,LL y)
{
    LL res=0;
    while(y)
    {
        if(y&1)res=(res+x)%MOD;
        y>>=1;
        x=(x+x)%MOD;
    }
    return res;
}
struct IntervalTree
{
    LL sum[maxn<<2][30];
    int setv[maxn<<2];
    void build(int o,int l,int r)
    {
        setv[o]=0;
        if(l==r)
        {
            sum[o][0]=a[l];//cout<<sum[o][0]<<endl;
            for(int i=1;i<maxm;i++)
            {
                sum[o][i]=pow_mul(sum[o][i-1],sum[o][i-1]);
                //cout<<sum[o][i]<<endl;
            }
            return ;
        }
        int mid=(l+r)>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        pushup(o);
    }
    void pushup(int o)
    {
        for(int i=0;i<maxm;i++)
            sum[o][i]=(sum[o<<1][i]+sum[o<<1|1][i])%MOD;
    }
    LL query(int o,int l,int r,int q1,int q2)
    {
        if(q1<=l&&r<=q2)
        {
            return sum[o][0];
        }
        pushdown(o);
        int mid=(l+r)>>1;
        LL ans=0;
        if(q1<=mid)ans=(ans+query(o<<1,l,mid,q1,q2))%MOD;
        if(q2>mid)ans=(ans+query(o<<1|1,mid+1,r,q1,q2))%MOD;
        pushup(o);
        return ans;
    }
    void maintain(int o,int k)
    {
        for(int j=0;j<maxm-1;j++)
            sum[o][j]=sum[o][min(j+k,maxm-1)];
    }
    void pushdown(int o)
    {
        if(setv[o])
        {
            setv[o<<1]+=setv[o];
            setv[o<<1|1]+=setv[o];
            maintain(o<<1,setv[o]);
            maintain(o<<1|1,setv[o]);
            setv[o]=0;
        }
    }
    void update(int o,int l,int r,int q1,int q2)
    {
        if(q1<=l&r<=q2)
        {
            setv[o]+=1;
            maintain(o,1);
            return ;
        }
        pushdown(o);
        int mid=(l+r)>>1;
        if(q1<=mid)update(o<<1,l,mid,q1,q2);
        if(q2>mid)update(o<<1|1,mid+1,r,q1,q2);
        pushup(o);
    }
}tree;
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            scanf("%I64u",&a[i]);
        tree.build(1,1,N);
        LL ans=0;
        printf("Case #%d:\n",cas++);
        while(M--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            ans=(ans+tree.query(1,1,N,l,r))%MOD;
            tree.update(1,1,N,l,r);
            cout<<(ans%MOD)<<endl;
        }
    }
    return 0;
}
