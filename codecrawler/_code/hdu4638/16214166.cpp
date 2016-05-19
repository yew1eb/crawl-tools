#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define ls 2*i
#define rs 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
const int mod = 10007;

struct node
{
    int l,r,val;
} a[N*4],s[N];

int num[N],pos[N],vis[N],ans[N];
int n,m;

int cmp(node a,node b)
{
    return a.r<b.r;
}

void build(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].val = 0;
    if(l==r) return;
    int mid = (l+r)/2;
    build(l,mid,ls);
    build(mid+1,r,rs);
}

void updata(int i,int pos,int v)
{
    a[i].val+=v;
    if(a[i].l==a[i].r) return;
    int mid = (a[i].l+a[i].r)/2;
    if(pos<=mid) updata(ls,pos,v);
    else updata(rs,pos,v);
}

int query(int l,int r,int i)
{
    if(a[i].l==l&&a[i].r==r)
    {
        return a[i].val;
    }
    int mid = (a[i].l+a[i].r)/2;
    if(r<=mid) return query(l,r,ls);
    if(l>mid) return query(l,r,rs);
    return query(l,mid,ls)+query(mid+1,r,rs);
}

int main()
{
    int t,i,j,k,cnt;
    scanf("%d",&t);
    while(t--)
    {
        MEM(vis,0);
        scanf("%d%d",&n,&m);
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            pos[num[i]] = i;
        }
        for(i = 1; i<=m; i++)
        {
            scanf("%d%d",&s[i].l,&s[i].r);
            s[i].val = i;
        }
        sort(s+1,s+1+m,cmp);
        build(1,n,1);
        cnt = 1;
        for(i = 1; i<=n&&cnt<=m; i++)
        {
            updata(1,i,1);
            vis[num[i]]=1;
            if(vis[num[i]-1]) updata(1,pos[num[i]-1],-1);
            if(vis[num[i]+1]) updata(1,pos[num[i]+1],-1);
            while(s[cnt].r==i&&cnt<=m)
            {
                ans[s[cnt].val] = query(s[cnt].l,s[cnt].r,1);
                cnt++;
            }
        }
        for(i = 1; i<=m; i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
