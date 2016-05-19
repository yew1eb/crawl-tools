#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#define INF 50005
#define inf 0x0f0f0f0f
#define mp make_pair

using namespace std;
vector <int> vec[INF],dis[INF];
int F[INF],Dis[INF];
int qmax[INF], qmin[INF];
bool vis[INF];
int n;
void _addedge(int i,int j,int d)
{
    vec[i].push_back(j),dis[i].push_back(d);
    vec[j].push_back(i),dis[j].push_back(d);
}
int BFS(int s)
{
    int n,j,t,siz,now=-1,ans=0; queue <int> q;
    memset(vis,true,sizeof(vis));
    for (Dis[s]=0,vis[s]=false,q.push(s);!q.empty();)
    {
        n=q.front(),q.pop();
        if (now<Dis[n]) now=Dis[n],ans=n;
        for (siz=vec[n].size(),j=0;j<siz;j++)
            if (vis[t=vec[n][j]])
                Dis[t]=Dis[n]+dis[n][j],vis[t]=0,q.push(t);
    }
    return ans;
}

int check(int u){
    int maxhead, minhead, maxtail, mintail;
    maxhead = minhead = 1;
    maxtail = mintail = 0;
    int now = 1,
    ans = 1;
    for(int i=1;i<=n;++i){
        while(maxhead<=maxtail && F[qmax[maxtail]]<=F[i]) --maxtail;
        qmax[++maxtail] = i;
        while(minhead<=mintail && F[qmin[mintail]]>=F[i]) --mintail;
        qmin[++mintail] = i;
        while(maxhead<=maxtail && minhead<=mintail && F[qmax[maxhead]]-F[qmin[minhead]] > u){
            now = min(qmax[maxhead],qmin[minhead])+1;
            while(maxhead<=maxtail && qmax[maxhead] < now) ++maxhead;
            while(minhead<=mintail && qmin[minhead]< now)  ++minhead;
        }
        if(F[qmax[maxhead]]-F[qmin[minhead]] <= u)
            ans =max(ans, i-now+1);
    }
    return ans;
}

int main()
{
    //freopen("1.txt","r",stdin);
    int i,j,m,x,y,z;
    while (scanf("%d%d",&n,&m),n)
    {
        memset(F,0,sizeof(F));
        for (i=1;i<=n;i++) vec[i].clear(),dis[i].clear();
        for (i=1;i<n;i++)
            scanf("%d%d%d",&x,&y,&z),
            _addedge(x,y,z);
        int s1=BFS(1),s2=BFS(s1);
        for (i=1;i<=n;i++)
            F[i]=max(Dis[i],F[i]);
        BFS(s2);
        for (i=1;i<=n;i++)
            F[i]=max(Dis[i],F[i]);
        while(m--){
            int k;
            scanf("%d",&k);
           /* int l = 1, r = n, mid;
            while(l<=r){
                mid = (l+r)>>1;
                if(check(mid, k)) l = mid+1;else
                r = mid-1;
            }*/
            printf("%d\n",check(k));
        }
    }
    return 0;
}