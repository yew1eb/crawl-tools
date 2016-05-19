#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#pragma comment(linker, "/STACK:16777216")
#define N 100500
#define ll long long
vector<int>vec[N];
int n;
ll ans;
ll s[N],tot[N];
ll dfs(int u,int pre)
{
    for(int i=0;i<vec[u].size();++i)
        if(vec[u][i]!=pre)
    {
        ans+=s[u]*tot[vec[u][i]]*(n-tot[u]);
        ans+=s[u]*tot[vec[u][i]]*(tot[u]-1-s[u]-tot[vec[u][i]]);
        s[u]+=dfs(vec[u][i],u);
    }
    s[u]++;
    return s[u];
}
ll cal(int u,int pre)
{
    for(int i=0;i<vec[u].size();++i)
        if(vec[u][i]!=pre)
        tot[u]+=cal(vec[u][i],u);
    tot[u]++;
    return tot[u];
}
int main ()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
            vec[i].clear();
        ans=0;
        memset(s,0,sizeof(s));
        memset(tot,0,sizeof(tot));
        for(int i=1,u,v;i<n;++i)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        cal(1,-1);
        dfs(1,-1);
        cout<<ans<<endl;
    }
    return 0;
}
