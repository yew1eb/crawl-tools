#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;
const int N = 50005;

vector<int> v[N],w[N],query[N],num[N];
int pre[N],dist[N],ans[N];
bool vis[N];
int n;

void Init()
{
    for(int i=1; i<=n; i++)
    {
        v[i].clear();
        w[i].clear();
        query[i].clear();
        num[i].clear();
        pre[i] = i;
        dist[i] = 0;
        vis[i] = false;
    }
}

int Find(int x)
{
    if(pre[x] != x)
        pre[x] = Find(pre[x]);
    return pre[x];
}

void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    pre[y] = x;
}

void Tarjan(int cur,int val)
{
    vis[cur] = true;
    dist[cur] = val;
    int size = v[cur].size();
    for(int i=0;i<size;i++)
    {
        int tmp = v[cur][i];
        if(vis[tmp]) continue;
        Tarjan(tmp,val + w[cur][i]);
        Union(cur,tmp);
    }
    int Size = query[cur].size();
    for(int i=0;i<Size;i++)
    {
        int tmp = query[cur][i];
        if(!vis[tmp]) continue;
        ans[num[cur][i]] = dist[cur] + dist[tmp] - 2*dist[Find(tmp)];
    }
}

int main()
{
    int T,Q,x,y,z;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&Q);
        Init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(y);
            w[x].push_back(z);
            v[y].push_back(x);
            w[y].push_back(z);
        }
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&x,&y);
            query[x].push_back(y);
            query[y].push_back(x);
            num[x].push_back(i);
            num[y].push_back(i);
        }
        Tarjan(1,0);
        for(int i=0;i<Q;i++)
           printf("%d\n",ans[i]);
    }
    return 0;
}
