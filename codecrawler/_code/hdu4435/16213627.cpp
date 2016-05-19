#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<30
#define M 2005
#define N 130
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct Point
{
    int x,y;
}p[N];
int n,d;
int path[N][N];
int ok[N];
double dist(int i,int j)
{
    return sqrt((double)sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y));
}
bool bfs()
{
    bool vis[N];
    int dist[N];
    queue<int>que;
    mem(vis,false);
    for(int i=0;i<n;i++)
    {
        //æ¬èº«æ¯å æ²¹ç«ï¼è·ç¦»æ¯0
        if(ok[i]) dist[i]=0;
        else dist[i]=inf;
    }
    que.push(0);vis[0]=true;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&path[u][i]<=d)
            {
                dist[i]=min(dist[i],dist[u]+path[u][i]);
                if(ok[i])
                {
                    que.push(i);
                    vis[i]=true;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        //è½ç¶æ¬èº«æ¯ä¸ªå æ²¹ç«ï¼ä½æ¯ä»1åºåæ ¹æ¬å°ä¸äº
        if(ok[i]&&!vis[i]) return false;
        //ä¸æ¯ä¸ä¸ªå æ²¹ç«ï¼ä¸è½ä¿è¯ä»ä¸ä¸ªæå æ²¹ç«çå°æ¹æ¥å
        if(!ok[i]&&dist[i]*2>d) return false;
    }
    return true;
}
void slove()
{
    for(int i=0;i<n;i++) ok[i]=1;
    if(!bfs()) {puts("-1");return ;}  //å¨é¨é½å»ºè¿ä¸è½éå
    for(int i=n-1;i>0;i--)
    {
        ok[i]=0;
        if(!bfs()) ok[i]=1;
    }
    int j=n-1;
    while(!ok[j]) j--;
    for(int i=j;i>=0;i--) printf("%d",ok[i]);
    puts("");
}
int main()
{
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                path[i][j]=ceil(dist(i,j));
            }
        }
        slove();
    }
    return 0;
}