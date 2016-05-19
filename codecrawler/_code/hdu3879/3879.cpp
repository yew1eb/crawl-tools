#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 60000              //点的个数
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
}E[400050];                     //边的个数  记得乘2
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],pre[MAXN],dis[MAXN];
int l,r,mid;
int N,M,scr,sink,vn,num;
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
int Sap(int s,int t,int n)//核心代码(模版)
{
    int ans=0,aug=INF;//aug表示增广路的流量
    int i,v,u=pre[s]=s;
    for(i=0;i<=n;i++)
    {
        cur[i]=head[i];
        dis[i]=gap[i]=0;
    }
    gap[s]=n;
    bool flag;
    while(dis[s]<n)
    {
        flag=false;
        for(int &j=cur[u];j!=-1;j=E[j].next)//一定要定义成int &j,why
        {
            v=E[j].v;
            if(E[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=true;//找到容许边
                aug=min(aug,E[j].w);
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    ans+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        E[cur[u]].w-=aug;
                        E[cur[u]^1].w+=aug;//注意
                    }
                    aug=INF;
                }
                break;//找到一条就退出
            }
        }
        if(flag) continue;
        int mindis=n;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(E[i].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=i;
            }
        }
        if((--gap[dis[u]])==0) break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return ans;
}
int n,m;
int main()
{
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       memset(head,-1,sizeof(head));ecnt=0;
       scr=0;sink=n+m+1;vn=sink+1;
       for(int i=1;i<=n;i++)
       {
           int v;
           scanf("%d",&v);
           Insert(i,sink,v);
       }
       int sum=0;
       for(int i=1;i<=m;i++)
       {
           int a,b,v;
           scanf("%d%d%d",&a,&b,&v);
           Insert(scr,i+n,v);
           Insert(i+n,a,INF);
           Insert(i+n,b,INF);
           sum+=v;
       }
        printf("%d\n",sum-Sap(scr,sink,vn));
   }
   return 0;
}
