#include<stdio.h>
#define L 50005
#define ll __int64
#define ls 2*i
#define rs 2*i+1
#define w(x) while(x)
#define max(a,b) (a>b?a:b)
int t,n,m,cas=1;
ll x,y,ans,res;
char str[10];
struct node
{
    int l,r,flag;
    ll maxn,sum;
} a[L<<2];
void PushUp(int i)
{
    a[i].sum=a[2*i].sum+a[2*i+1].sum;
    a[i].maxn=max(a[2*i].maxn,a[2*i+1].maxn);
}
void PushDown(int i)
{
    if(a[i].flag)
    {
        a[ls].flag += a[i].flag;
        a[rs].flag += a[i].flag;
        w(a[i].flag--)
        {
            a[ls].maxn *= 2;
            a[rs].maxn *= 2;
            a[ls].sum *= 2;
            a[rs].sum *= 2;
        }
        a[i].flag=0;
    }
}
void init(int l,int r,int i)
{
    a[i].l=l;
    a[i].r=r;
    a[i].flag=0;
    a[i].maxn=1;
    if(l==r)
    {
        a[i].sum=1;
        return;
    }
    int mid=(l+r)/2;
    init(l,mid,ls);
    init(mid+1,r,rs);
    PushUp(i);
}
int find(int i,ll x,ll &k,ll &tem)
{
    if(a[i].l==a[i].r)
    {
        k=x;
        tem=a[i].sum;
        return a[i].l;
    }
    PushDown(i);
    if(x<=a[ls].sum) return find(ls,x,k,tem);
    else return find(rs,x-a[ls].sum,k,tem);
}
void insert1(int i,int p,ll v)
{
    if(a[i].l==a[i].r)
    {
        a[i].maxn+=v;
        a[i].sum+=v;
        return;
    }
    PushDown(i);
    int mid=(a[i].l+a[i].r)/2;
    if(p<=mid) insert1(ls,p,v);
    else insert1(rs,p,v);
    PushUp(i);
}
void insert2(int l,int r,int i)
{
    if(l<=a[i].l&&a[i].r<=r)
    {
        PushDown(i);
        a[i].flag++;
        a[i].sum*=2;
        a[i].maxn*=2;
        return;
    }
    PushDown(i);
    int mid=(a[i].l+a[i].r)/2;
    if(l<=mid) insert2(l,r,ls);
    if(r>mid) insert2(l,r,rs);
    PushUp(i);
}
void query(int l,int r,int i)
{
    if(l<=a[i].l&&a[i].r<=r)
    {
        res=max(res,a[i].maxn);
        return;
    }
    PushDown(i);
    int mid=(a[i].l+a[i].r)/2;
    if(l<=mid) query(l,r,ls);
    if(r>mid) query(l,r,rs);
}
int main()
{
    scanf("%d",&t);
    w(t--)
    {
        scanf("%d%d",&n,&m);
        init(1,n,1);
        printf("Case #%d:\n",cas++);
        w(m--)
        {
            scanf("%s%I64d%I64d",str,&x,&y);
            ll lk,rk,tem;
            int r=find(1,y,rk,tem);
            int l=find(1,x,lk,tem);
            if(str[0]=='D')
            {
                if(l==r)
                {
                    insert1(1,l,rk-lk+1);
                    continue;
                }
                insert1(1,r,rk);
                insert1(1,l,tem-lk+1);
                if(r-l>1)
                    insert2(l+1,r-1,1);
            }
            else
            {
                ans=0;
                if(l==r)
                {
                    printf("%I64d\n",rk-lk+1);
                    continue;
                }
                ans=max(ans,max(rk,tem-lk+1));
                if(r-l>1)
                {
                    res=0;
                    query(l+1,r-1,1);
                    ans=max(ans,res);
                }
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
