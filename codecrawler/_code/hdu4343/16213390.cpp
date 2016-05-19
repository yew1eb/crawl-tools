#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int inf = 1000000002;
const int maxn = 100002;
struct interval
{
    int l,r;
    bool operator < (const interval &other) const
    {
        if(l == other.l)
        {
            return r > other.r;
        }
        return l < other.l;
    }
}inter[maxn];
int m,n,cnt;

void read()
{
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&inter[i].l,&inter[i].r);
    }
    sort(inter , inter + n);
    return;
}

void make()  //ç­éæè½è¦çä½å¶ä»ä»»æåºé´çå¤§åºé´
{
    int tot = 0;
    for(int i=0;i<n;++i)
    {
        bool flag = true;
        for(int j=i+1;j<n;++j)
        {
            if(inter[j].l >= inter[i].l && inter[j].r <= inter[i].r)
            {
                flag = false;
                break;
            }
            if(inter[j].l >= inter[i].r)
            {
                break;
            }
        }
        if(flag)
        {
            inter[tot++] = inter[i];
        }
    }
    n = tot;
    return;
}

int bis(int val)
{
    int le = 0,ri = n-1;
    while(le <= ri)
    {
        int mid = (le + ri) >> 1;
        if(inter[mid].l >= val)
        {
            ri = mid - 1;
        }
        else
        {
            le = mid + 1;
        }
    }
    return le;
}

void dfs(int l,int r)
{
    int wei = bis(l);   //æ¾å°ç¬¬ä¸ä¸ªå¨lå³æ¹æè¿åºé´çå·¦ç«¯ç¹
    if(wei == n || inter[wei].l >= r || inter[wei].r > r) return;
    cnt++;
    l = inter[wei].r;
    return dfs(l , r);
}

void solve()
{
    int fr,to;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&fr,&to);
        cnt = 0;
        dfs(fr , to);
        printf("%d\n",cnt);
    }
    return;
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        read();
        make();
        solve();
    }
    return 0;
}