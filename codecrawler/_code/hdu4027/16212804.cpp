#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

const int L = 100000+10;
__int64 sum[L<<2],cnt[L<<2];

void add(int i)
{
    sum[i] = sum[2*i]+sum[2*i+1];
    cnt[i] = cnt[2*i]&&cnt[2*i+1];
}

void init(int l,int r,int i)
{
    if(l == r)
    {
        scanf("%I64d",&sum[i]);
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,2*i);
    init(mid+1,r,2*i+1);
    add(i);
}

void insert(int L,int R,int l,int r,int i)
{
    if(l == r)
    {
        sum[i] = sqrt(sum[i]);//åä¸åæ´
        if(sum[i]<=1)//å¦æä¸º0ï¼åæ è®°ä¸è½åè®¿é®äº
            cnt[i] = 1;
        return ;
    }
    int mid = (l+r)>>1;
    if(L<=mid && !cnt[2*i])//å­©å­å·²ç»ç ´åäºåä¸éåè®¿é®
        insert(L,R,l,mid,2*i);
    if(R>mid && !cnt[2*i+1])
        insert(L,R,mid+1,r,2*i+1);
    add(i);
}

__int64 query(int L,int R,int l,int r,int i)//æ¥è¯¢åºé´å
{
    if(L<=l && r<=R)
        return sum[i];
    int mid = (l+r)>>1;
    __int64 ans = 0;
    if(L<=mid)
        ans+=query(L,R,l,mid,2*i);
    if(R>mid)
        ans+=query(L,R,mid+1,r,2*i+1);
    return ans;
}

int main()
{
    int n,m,i,j,x,l,r,cas = 1,flag;
    while(~scanf("%d",&n))
    {
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        init(1,n,1);
        printf("Case #%d:\n",cas++);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&flag,&l,&r);
            if(l>r)//è¿éè¦æ³¨æ
                swap(l,r);
            if(flag)
                printf("%I64d\n",query(l,r,1,n,1));
            else
                insert(l,r,1,n,1);
        }
        printf("\n");
    }

    return 0;
}
