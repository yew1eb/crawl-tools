#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#define LL long long
using namespace std;
#define lson l, mid, root<<1
#define rson mid+1, r, root<<1|1
const LL N = 1e5+10;
LL mod,q;
LL flag[N];
struct node
{
    LL l, r, sum;
} a[N<<2];

void PushUp(LL root) //æå½åèç¹çä¿¡æ¯æ´æ°å°ç¶èç¹
{
    a[root].sum = (a[root<<1].sum*a[root<<1|1].sum)%mod;
}

void build_tree(LL l, LL r, LL root)
{
    a[root].sum=1;
    a[root].l = l;
    a[root].r = r;
    if(l == r)
    {
        a[root].sum=1;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(lson);
    build_tree(rson);
}

void update(LL l, LL r, LL root,LL k)
{
    if(l == a[root].l && r == a[root].r)
    {
        a[root].sum = k;
        return ;
    }
    LL mid = (a[root].l + a[root].r) >> 1;
    if(r <= mid) update(l, r, root<<1, k);
    else if(l > mid) update(l, r, root<<1|1, k);
    else
    {
        update(lson, k);
        update(rson, k);
    }
    PushUp(root);
}
int main()
{
    LL T, n, l, r, cas = 0;
    scanf("%d",&T);
    while(T--)
    {
        cin>>q>>mod;
        build_tree(1,q,1);
        printf("Case #%lld:\n", ++cas);
        int tem=1;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==1)
            {
                update(tem,tem,1,y);
                printf("%lld\n",a[1].sum%mod);
                flag[i+1]=tem;
                tem++;
            }
            else
            {
                update(flag[y],flag[y],1,1);
                printf("%lld\n",a[1].sum%mod);
            }

        }
    }
    return 0;
}