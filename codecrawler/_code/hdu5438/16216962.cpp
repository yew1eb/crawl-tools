#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iomanip>
using namespace std;
#define LL long long
const int maxn=1e4+10;
LL p;
LL m;
LL a[maxn];
LL vis[maxn];
LL vis2[maxn];
vector<LL> G[maxn];
LL deg[maxn];
void topsort()
{
    queue<int> q;
    for(LL i=1;i<=p;i++)
    {
        if(deg[i]==1) {q.push(i);vis[i]=1;}
        else if(deg[i]==0) vis[i]=1;
    }
    while(!q.empty())
    {
        LL d=q.front();
        q.pop();
        deg[d]--;
       // cout<<d<<endl;
        for(LL i=0;i<G[d].size();i++)
        {
            LL dd=G[d][i];
            deg[dd]--;
            if(deg[dd]==1)
            {
                q.push(dd);
                vis[dd]=1;
            }
        }
        //cout<<"hehe"<<endl;
    }
}
LL dfs(LL u)
{
    queue<LL> q;
    q.push(u);
    vis2[u]=1;
    LL len=0;
    LL sum=0;
    while(!q.empty())
    {
        int d=q.front();
        q.pop();
        sum+=a[d];
        len++;
        for(LL i=0;i<G[d].size();i++)
        {
            LL dd=G[d][i];
            if(!vis[dd]&&!vis2[dd])
            {
                q.push(dd);
                vis2[dd]=1;
            }
        }
    }
   // cout<<len<<' '<<sum<<endl;
    if(len%2==1)
        return sum;
    else
        return 0;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>p;
       cin>>m;
       memset(vis,0,sizeof(vis));
       memset(G,0,sizeof(G));
       memset(deg,0,sizeof(deg));
       memset(vis2,0,sizeof(vis2));
       for(int i=1;i<=p;i++)
        cin>>a[i];
        for(int i=1;i<=p;i++)
            G[i].clear();
       for(int i=0;i<m;i++)
       {
           int x,y;
           cin>>x>>y;
           G[x].push_back(y);
           G[y].push_back(x);
           deg[x]++;
           deg[y]++;
       }
       topsort();
       LL sum=0;
       for(int i=1;i<=p;i++)
        if(!vis[i]&&!vis2[i])   sum+=dfs(i);
        cout<<sum<<endl;
    }
    return 0;
}