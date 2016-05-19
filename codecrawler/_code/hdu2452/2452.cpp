#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int N=10009;
const int INF =  0x7fffffff;
int v[N][2];
int wh[N];
struct lin
{
    int nex,to;
} link[N*100];
int first[N];
int n,m,f,cnt;
void add(int f,int t)
{
    link[cnt].to=t;
    link[cnt].nex=first[f];
    first[f]=cnt;
    cnt++;
}
int in[N];
void init()
{
    cnt=0;
    int f,t;
    memset(first,-1,sizeof(first));
    memset(in,0,sizeof(in));
    memset(v,0,sizeof(v));
    for(int i=1; i<=n; i++)
        scanf("%d",&wh[i]);
    for(int i=0; i<m;i++)
    {
        scanf("%d%d",&f,&t);
        in[t]++;
        add(f,t);
    }
}
bool ok;
int dfs(int k,int c)
{
    if(c==1)
    {
        if(v[k][1]) return v[k][1];
        for(int i=first[k];i!=-1;i=link[i].nex)
        {
            int tmp=dfs(link[i].to,0);
            if(tmp>v[k][1])
            v[k][1]=tmp;
        }
        v[k][1]+=wh[k];
        return v[k][1];
    }
    else
    {
        if(v[k][0]) return v[k][0];
        v[k][0]=INF;
        for(int i=first[k];i!=-1;i=link[i].nex)
        {
            int tmp=dfs(link[i].to,1);
            if(tmp<v[k][0])
            v[k][0]=tmp;
        }
        if(v[k][0]==INF)
        v[k][0]=wh[k];
        else
        v[k][0]+=wh[k];
        return v[k][0];
    }
}
void solve()
{
    ok=false;
    for(int i=1;i<=n;i++)
    if(in[i]==0)
    {
        if(dfs(i,1)>=f)
        ok=true;
        if(ok) break;
    }
    if(ok)
    {
        printf("Victory\n");
    }
    else
    {
        printf("Glory\n");
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&f))
    {
        init();
        solve();
    }
    return 0;
}