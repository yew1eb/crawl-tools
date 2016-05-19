#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAXN 30005
#define MAXM 200
struct Node
{
    int l,r,id,add;
    bool operator < (const Node & c)const{
        return l / MAXM == c.l / MAXM ? r < c.r : l / MAXM < c.l / MAXM;
    }
}q[MAXN << 2];
int k,n,m,num[MAXN],has[MAXN],last[MAXN];
void solve()
{
    int mid,r,cur = -1;
    int ans1,ans2;
    for(int j = 0;j < m << 2;j++)
    {
        int ind = q[j].l / MAXM;
        if(ind != cur)
        {
            memset(has,0,sizeof(has));
            cur = mid;
            mid = (ind + 1) * MAXM , r = (ind + 1) * MAXM;
            ans2 = 0;
        }
        ans1 = 0;
        for(int i = r;i < q[j].r;i++)
        {
            if(k - num[i] <= n && 0 <= k - num[i])
                ans2 += has[k - num[i]];
            has[num[i]]++;
        }
        for(int i = q[j].l;i < min(q[j].r,mid);i++)
        {
            if(k - num[i] <= n && 0 <= k - num[i])
                ans1 += has[k - num[i]];
            has[num[i]]++;
        }
        for(int i = q[j].l;i < min(q[j].r,mid);i++)
            has[num[i]]--;
        //cout << ans << " ans " << endl;
        r = max(q[j].r,r);
        last[q[j].id] += q[j].add * (ans1 + ans2);
        cur = ind;
    }
}
int main()
{
    int l1,l2,r1,r2;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        memset(last,0,sizeof(last));
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        scanf("%d",&m);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            l1--,l2--;
            q[i * 4].l = l1,q[i * 4].r = r2,q[i * 4].id = i,q[i * 4].add = 1;
            q[i * 4 + 1].l = l1,q[i * 4 + 1].r = l2,q[i * 4 + 1].id = i,q[i * 4 + 1].add = -1;
            q[i * 4 + 2].l = r1,q[i * 4 + 2].r = r2,q[i * 4 + 2].id = i,q[i * 4 + 2].add = -1;
            q[i * 4 + 3].l = r1,q[i * 4 + 3].r = l2,q[i * 4 + 3].id = i,q[i * 4 + 3].add = 1;
        }
        sort(q,q + m * 4);
        solve();
        for(int i = 0;i < m;i++)
            printf("%d\n",last[i]);
    }
}
