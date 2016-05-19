//c++  #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define INF (1<<29)
#define eps (1e-5)
#define pb push_back
using namespace std;
/*
struct Edge{
    int v,next,w;
}edge[MAXN*3];
int E,list[MAXN];
void init() {memset(list,E=-1,sizeof(list)); }
void add(int u,int v,int w)
{
    edge[++E].v=v; edge[E].w=w; edge[E].next=list[u]; list[u]=E;
}
*/
int input()
{
    int a,k=1; char c;
    while ( (c=getchar())>'9' || c<'0')
        if (c=='-') k=-1;
    a=c-'0';
    while ( (c=getchar())<='9' && c>='0') a=a*10+c-'0';
    return a*k;
}

struct node
{
    int x,y,s;
};
node make_node(int x,int y,int s)
{
    node a;
    a.x=x; a.y=y; a.s=s;
    return a;
}
queue<node> q;
#define MAXN 205
char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
double f[MAXN][MAXN];
int n,m;
bool judge(int x,int y)
{
    return !vis[x][y] && x>0 && x<=n && y>0 && y<=m && s[x][y]!='X' && s[x][y]!='E';
}

void bfs(int EX,int EY,double mid,int sum)
{
    memset(vis,0,sizeof(vis));
    while (q.size()) q.pop();
    q.push( make_node(EX,EY,0) );
    vis[EX][EY]=true;
    while (q.size())
    {
        node now=q.front(); q.pop();
        if (now.s>mid/sum+1)
            f[now.x][now.y]=min(f[now.x][now.y],mid/sum+1);
        else
            f[now.x][now.y]=min(f[now.x][now.y],1.0*now.s);
        rep(dx,-1,1)
            rep(dy,-1,1)
                if (dx*dy==0 && (dx||dy))
                if (judge(now.x+dx,now.y+dy))
                {
                    node tmp=make_node(now.x+dx,now.y+dy,now.s+1);
                    vis[tmp.x][tmp.y]=true;
                    q.push(tmp);
                }
    }
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while (scanf("%d%d",&n,&m) && (n||m))
    {
        rep(i,1,n) scanf("%s",&s[i][1]);
        int sum=0,YX,YY;
        rep(i,1,n) rep(j,1,m)
        {
            if (s[i][j]=='Y') YX=i,YY=j;
            if (s[i][j]!='X') sum++;
        }
        double l,r,mid,ans;
        l=0; r=n*m*n*m;
        rep(ii,1,40)
        {
            mid=(l+r)/2;
            double w=0;
            rep(i,1,n) rep(j,1,m) f[i][j]=INF;
            rep(i,1,n) rep(j,1,m) if (s[i][j]=='E') bfs(i,j,mid,sum);
            rep(i,1,n) rep(j,1,m) if (s[i][j]!='X') f[i][j]=min(f[i][j],mid/sum+1) , w=w+f[i][j];
            if (w<mid) r=mid ,ans=f[YX][YY];
            else l=mid;
        }
        printf("%.3lf\n",ans);
    }
    //system("pause");
    return 0;
}