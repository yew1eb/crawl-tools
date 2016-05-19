#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
const int N=10010;

ll p,m,v[N],vis[N],indir[N];
vector<ll>G[N];

ll bfs(ll x)
{
    queue<ll>q;
    q.push(x);
    vis[x]=1;
    ll k=0;
    ll sum=v[x];
    while (!q.empty())
    {

        int s=q.front();
        q.pop(); //cout<<s<<endl;
        k++;
        for (int i=0; i<G[s].size(); i++)
        {
            if (!vis[G[s][i]]&&indir[G[s][i]]>=2)//å æçç¹ä¸å¯ä»¥å è¿æ¥
            {
                sum+=v[G[s][i]];
                q.push(G[s][i]);
                vis[G[s][i]]=1;
            }
        }
    }
    if (k>=3&&k%2==1)
        return sum;
    else
        return 0;
}

int main()
{
    int T,a,b;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&p,&m);
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(indir,0,sizeof(indir));
        for (int i=1; i<=p; i++)
        {
            scanf("%lld",&v[i]);
        }
        for (int i=1; i<=p; i++)
            G[i].clear();
        for (int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);//å°bæ¾å¨aéåçæåä¸ä¸ª
            G[b].push_back(a);
            indir[a]++;
            indir[b]++;
        }
        int j;
        for (int i=1; i<=p; i++)
        {
            for ( j=1; j<=p; j++)
            {
                if (indir[j]==0||indir[j]==1)
                {
                    break;
                }
            }
            if (j>p)
                break;
            indir[j]=-1;
            for (int k=0; k<G[j].size(); k++)
            {
                indir[G[j][k]]--;
            }
        }
        ll ans=0;
        for (int i=1; i<=p; i++)//æéææçç¯
            if (!vis[i]&&indir[i]>=2)
                ans+=bfs(i);
        cout<<ans<<endl;
    }
    return 0;
}
