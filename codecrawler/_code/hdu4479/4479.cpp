#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
#define LL long long
const int N = 10009;
const int M = 100009;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct load{
    int f,t,dis;
    bool operator<(const load t)const{
        return dis<t.dis;
    }
} ld[M];
int n,m;
int fa[N];
LL dis[N];
int v[N];
LL vdis[N];
void oper(int st,int len)
{
    int cnt=  0,l,r,d;
    for(int i=0;i<len;i++)
    {
        l = ld[i+st].f,r= ld[st+i].t,d = ld[st+i].dis;
        if(fa[l]&&dis[r]>d+dis[l])
        {
            v[cnt] = r;
            vdis[cnt]= d+dis[l];
            cnt++;
        }
        if(fa[r]&&dis[l]>d+dis[r])
        {
            v[cnt] = l;
            vdis[cnt] = d+dis[r];
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        dis[v[i]] = min(dis[v[i]],vdis[i]);
        fa[v[i]] = 1;
    }
}
void solve()
{
    memset(fa,0,sizeof(fa));
    for(int i=0;i<=n;i++) dis[i] = INF;
    dis[1] = 0;
    fa[1] = 1;
    for(int i=0;i<m;)
    {
        int j;
        for(j=i+1;j<m;j++)
        {
            if(ld[j].dis!=ld[i].dis) break;
        }
        oper(i,j-i);
        i = j;
    }
    if(dis[n]!=INF)
    cout<<dis[n]<<endl;
    else printf("No answer\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        scanf("%d%d%d",&ld[i].f,&ld[i].t,&ld[i].dis);
        sort(ld,ld+m);
        solve();
    }
    return 0;
}
