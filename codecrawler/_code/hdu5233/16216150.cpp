#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
#define maxn 100000 + 10

//ä¿å­æ¯ä¸ªé«åº¦æåå«çä½ç½®

set<int> S[maxn];
int n, m;
int len;
int h[maxn], t[maxn];

void read()
{
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &h[i]);
        t[i] = h[i];
    }

    sort(t+1, t+n+1);
    len = unique(t+1, t+n+1) - (t+1);

    for(int k=1; k<=len; k++)
        S[k].clear();

    for(int i=1; i<=n; i++)
    {
        int tmp = lower_bound(t+1, t+len+1, h[i]) - t;
        S[tmp].insert(i);
    }
}

void solve()
{
    int q;
    for(int i=0; i<m; i++)
    {
        scanf("%d", &q);
        int id = lower_bound(t, t+len+1, q) - t;
        if(t[id] != q)
            printf("-1\n");
        else if(S[id].empty())
            printf("-1\n");
        else
        {
            printf("%d\n", *S[id].begin());
            S[id].erase(S[id].begin());
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        read();
        solve();
    }
    return 0;
}
