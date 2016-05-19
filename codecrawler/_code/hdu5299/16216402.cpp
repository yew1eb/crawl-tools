#include"stdio.h"
#include"algorithm"
#include"string.h"
#include"iostream"
#include"queue"
#include"map"
#include"vector"
#include"string"
#include"cmath"
using namespace std;
#define N 22222
vector<int>edge[N];
struct node
{
    int x,y,r;
} c[N];
int cmp(node a,node b)
{
    return a.r>b.r;
}
double dis(int a,int b)
{
    return sqrt((c[a].x-c[b].x)*(c[a].x-c[b].x)+(c[a].y-c[b].y)*(c[a].y-c[b].y)*1.0);
}
void go(int x,int k)
{
    int lit=edge[x].size();
    for(int i=0; i<lit; i++)
    {
        int v=edge[x][i];
        double s=dis(v,k);
        if(s+c[k].r>c[v].r) continue;
        go(v,k);
        return ;
    }
    edge[x].push_back(k);
    return ;
}
int dfs(int x)
{
    int lit=edge[x].size();
    if(lit==0) return 0;
    int ans=0;
    for(int i=0; i<lit; i++)
    {
        int v=edge[x][i];
        ans^=dfs(v)+1;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    c[0].x=c[0].y=0;
    c[0].r=100000;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);
        sort(c+1,c+1+n,cmp);
        for(int i=0; i<=n; i++) edge[i].clear();
        for(int i=1; i<=n; i++) go(0,i);
        if(dfs(0)==0) puts("Bob");
        else puts("Alice");
    }
    return 0;
}
