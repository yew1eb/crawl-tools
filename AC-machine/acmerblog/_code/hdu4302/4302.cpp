#include<stdio.h>
#include<string.h>
#define N 100000
#define INF 100000020
#define lowbit(x) ((x)&(-(x)))

int a[N*2];
int L;
void add(int t,int v)
{
    while(t<=L)
    {
        a[t]+=v;
        t=(t|(t-1))+1;
    }
}

long long query(int t)
{
    long long ans=0;
    while(t>0)
    {
        ans+=a[t];
        t&=t-1;
    }
    return ans;
}

int right_search(int t)
{
    if(t==L)
    {
        if(query(L)-query(L-1))
            return L;
        return INF;
    }
    int l=t,r=L;
    int cmp=query(t-1);
    while(l<=r)
    {
        int mid=(l+r)>>1;
        query(mid)-cmp>0?(r=mid-1):(l=mid+1);
    }
    if(query(l)-cmp==0)
        return INF;
    return l;
}

int left_search(int t)
{
    if(t==1)
    {
        if(query(1))
            return 1;
        else return INF;
    }
    int l=1,r=t;
    int cmp=query(t);
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        cmp-query(mid)>0?(l=mid+1):(r=mid-1);
    }
    if(query(l)==0)
        return INF;
    return l;
}

int main(void)
{
    int t,n,ct=0,dist,pos,dir,x;
    scanf("%d",&t);
    while(t--)
    {
        pos=1;
        dist=0;
        dir=1;
        memset(a,0,sizeof(a));
        scanf("%d%d",&L,&n);
        L++;
        while(n--)
        {
            scanf("%d",&x);
            if(x)
            {
                int l=left_search(pos);
                int r=right_search(pos);
                if(l==INF&&r==INF)
                    ;
                else  if(pos-l>r-pos||l==INF)
                {
                    dist+=r-pos;
                    pos=r;
                    dir=1;
                    add(r,-1);
                }
                else if(pos-l<r-pos||r==INF)
                {
                    dist+=pos-l;
                    pos=l;
                    dir=-1;
                    add(l,-1);
                }
                else if(dir==1)
                {
                    dist+=r-pos;
                    pos=r;
                    add(r,-1);
                }
                else
                {
                    dist+=pos-l;
                    pos=l;
                    add(l,-1);
                }
            }
            else
            {
                scanf("%d",&x);
                add(x+1,1);
            }
        }
        printf("Case %d: %d\n",++ct,dist);
    }
    return 0;
}