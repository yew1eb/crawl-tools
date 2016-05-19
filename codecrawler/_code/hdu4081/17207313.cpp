#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define N 1050
#define INF 1000000
struct point
{
    double x,y;
    int num;
}p[N];
int n;
double map[N][N],dist[N],A,B;
vector<int>vec[N];
double getdistance(point aa,point bb)
{
    return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y));
}
int pre[N];
void prim()
{
    for(int i=1;i<=n;++i)
        dist[i]=INF*1.0;
    double min_edge;
    int min_p,now=1;
    for(int i=1;i<n;++i)// è¿édist è¡¨ç¤ºå°è¾¾å·²ç»æ´æ°å¥½çç¹éçæå°è·ç¦»
    {
        min_edge=INF*1.0;
        for(int i=1;i<=n;++i)
            if(map[now][i]>0)
            {
                if(dist[i]>map[now][i])
                    dist[i]=map[now][i],pre[i]=now;
            }
        dist[now]=-1.0;
        for(int i=1;i<=n;++i)
            if(dist[i]>0&&dist[i]<min_edge)
            {
                min_edge=dist[i];
                min_p=i;
            }
        vec[pre[min_p]].push_back(min_p);  // æå°è¾¹æå¯è½æ¥èªä¹åæ´æ°è¿çï¼è¿éWA
        vec[min_p].push_back(pre[min_p]);
        now=min_p;
        B+=min_edge;
    }
}
int vis[N];
int dfs(int u,int fa)
{
    int max_num=p[u].num;
    int ret=u;int tt;
    for(int i=0;i<vec[u].size();++i)
        if(vec[u][i]!=fa)
        {
            tt=dfs(vec[u][i],u);
            if(max_num<p[tt].num)
                max_num=p[tt].num,ret=tt;
        }
    return ret;
}

int main ()
{
    //freopen("aa.txt","r",stdin);
    //freopen("bb.txt","w",stdout);
    int test;scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].num);
    
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
                map[i][j]=map[j][i]=getdistance(p[i],p[j]);
            map[i][i]=0.0;
        }
        for(int i=0;i<=n;++i)
            vec[i].clear();
        B=0.0;
        memset(pre,-1,sizeof(pre));
        prim();
        double ans=-1.0;
        double res;int t1,t2;
        for(int i=1;i<=n;++i)
            for(int j=0;j<vec[i].size();++j)  // æä¸¾è¾¹ï¼å¯¹äºè¿æ¡å²è¾¹ä¸¤ä¾§çè¿éå¾åå«æ¾åºç¹ææå¤§çç¹
            {
                t1=dfs(i,vec[i][j]);
                t2=dfs(vec[i][j],i);
                res=(p[t1].num+p[t2].num)/(B-map[i][vec[i][j]]);
                if(res>ans)
                    ans=res;
            }
        ans+=(1e-8);
        printf("%.2lf\n",ans);
    }
    //system("pause");
    return 0;
}