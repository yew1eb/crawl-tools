#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 30005
#define MAXM 150
#define MOD 1000000007
struct Node
{
    int l,r,id;
    bool operator < (const Node & c)const{
        return l / MAXM == c.l / MAXM ? r < c.r : l / MAXM < c.l / MAXM;
    }
}q[MAXN];
LL d[MAXN],nd[MAXN];
int _,n,m,num[MAXN],last[MAXN],has[MAXN];
LL _pow(LL a,int b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1)ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
void init()
{
    d[0] = d[1] = nd[0] = nd[1] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        d[i] = (i * d[i - 1]) % MOD;
        nd[i] = _pow(d[i],MOD - 2);
    }
}
void solve()
{
    int mid,r,cur = -1;
    LL top,below1,below2;
    for(int j = 0;j < m;j++)
    {
        int ind = q[j].l / MAXM;
        if(ind != cur)
        {
            memset(has,0,sizeof(has));
            cur = mid;
            mid = (ind + 1) * MAXM , r = (ind + 1) * MAXM;
            below2 = 1;
        }
        top = d[q[j].r - q[j].l];
        below1 = 1;
        for(int i = r;i < q[j].r;i++)
        {
            below2 = (below2 * d[has[num[i]]]) % MOD;
            has[num[i]]++;
            below2 = (below2 * nd[has[num[i]]]) % MOD;
        }
        for(int i = q[j].l;i < min(q[j].r,mid);i++)
        {
            below1 = (below1 * d[has[num[i]]]) % MOD;
            has[num[i]]++;
            below1 = (below1 * nd[has[num[i]]]) % MOD;
        }
        for(int i = q[j].l;i < min(q[j].r,mid);i++)
            has[num[i]]--;
        r = max(q[j].r,r);
        last[q[j].id] = top * below1 % MOD * below2 % MOD;
        cur = ind;
    }
}
int main()
{
    scanf("%d",&_);
    init();
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].l--,q[i].r;
            q[i].id = i;
        }
        sort(q,q + m);
        solve();
        for(int i = 0;i < m;i++)
            printf("%d\n",last[i]);
    }
}
