#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<map>
#include<stack>
#include<cassert>
#include<algorithm>
using namespace std;

const int maxn = 1024;
const int end = 1023;
const int inf = 0x3f3f3f3f;

struct zz
{
    int from;
    int to;
    int c;
    int cost;
    int id;
}zx,tz;

int w[maxn];
vector<zz>g[maxn];
bool inq[maxn];
queue<int>q;
int way[maxn];
bool vis[maxn];
int backid[maxn];
int n,m,k,tot,minflow,sum;


void link(int now,int to,int c,int cost,int bc,int bcost)
{
    zx.from = now;
    zx.to = to;
    zx.c = c;
    zx.cost = cost;
    zx.id = g[to].size();
    g[now].push_back(zx);
    swap(zx.from , zx.to);
    zx.c = bc;
    zx.cost = bcost;
    zx.id = g[now].size() - 1;
    g[zx.from].push_back(zx);
    return ;
}

bool spfa()
{
    while(!q.empty())
    {
        q.pop();
    }
    memset(inq,false,sizeof(inq));
    memset(backid,-1,sizeof(backid));
    for(int i=1;i<=tot;i++)
    {
        way[i] = inf;
    }
    way[end] = inf;
    way[0] = 0;
    inq[0] = true;
    q.push(0);
    int now,to,cost,id,temp;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++)
        {
            if(g[now][i].c > 0)
            {
                to = g[now][i].to;
                id = g[now][i].id;
                cost = g[now][i].cost;
                temp = way[now] + cost;
                if(temp < way[to])
                {
                    backid[to] = id;
                 //   assert(g[to][id].to == now)
                    way[to] = temp;
                    if(!inq[to])
                    {
                        q.push(to);
                        inq[to] = true;
                    }
                }
            }
        }
        inq[now] = false;
    }
    minflow = inf;
    int nowid;
    temp = end;
    while(backid[temp] != -1)
    {
        id = backid[temp];
        now = g[temp][id].to;
        nowid = g[temp][id].id;
        minflow = min(g[now][nowid].c , minflow);
        temp = now;
    }
    temp = end;
    while(backid[temp] != -1)
    {
        id = backid[temp];
        now = g[temp][id].to;
        nowid = g[temp][id].id;
        g[now][nowid].c -= minflow;
        g[temp][id].c += minflow;
        temp = now;
    }
    if(way[end] < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int EK()
{
    int ans=0;
    while( spfa() )
    {
        ans += way[end]*minflow;
    }
    return -ans;
}



int main()
{
    while(scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        sum = 0;
        for(int i=0;i<maxn;i++)
        {
            g[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
          //  cin>>w[i];
            scanf("%d",&w[i]);
            sum += w[i];
        }
     //   assert(m > k);
        if(m<=k)
        {
            printf("%d\n",sum);
        //    cout<<sum<<endl;
            continue;
        }
        tot = n - m + 2;
        for(int i=1; i<tot; i++)
        {
            link(i,i+1,inf,0,0,0);
        }
        link(0,1,k,0,0,0);
        link(tot,end,k,0,0,0);
        int now,to;
        for(int i=1;i<=n;i++)
        {
            now = max(1,i-m+1);
            to = min(i,tot-1)+1;
            link(now,to,1,-w[i],0,w[i]);
        }
        printf("%d\n",EK());
     //   cout<<EK()<<endl;
    }
    return 0;
}
