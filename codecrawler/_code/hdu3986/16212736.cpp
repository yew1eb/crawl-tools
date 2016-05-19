#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1010;
const int M=100010;
const int INF=0xffffff;

struct Edge
{
    int u;
    int to;
    int w;
    int flag;
    int next;
} e[M];

int head[N];
int dist[N];
int path[N];
int inq[N];
int n,m,cnt,flag;

void AddEdge(int u,int v,int w)
{
    e[cnt].u=u;
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].flag=1;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

int SPFA(int s)
{
    queue<int>Q;
    for(int i=1; i<=n; i++)
    {
        dist[i]=INF;
        inq[i]=0;
    }
    dist[s]=0;
    inq[s]=1;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        inq[u]=0;
        for(int j=head[u]; j!=-1; j=e[j].next)
        {
            int x=e[j].to;
            if(e[j].flag&&dist[x]>dist[u]+e[j].w)
            {
                dist[x]=dist[u]+e[j].w;
                if(!flag)
                    path[x]=j;
                if(!inq[x])
                {
                    Q.push(x);
                    inq[x]=1;
                }
            }
        }
    }
    return dist[n];
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=flag=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            AddEdge(u,v,w);
            AddEdge(v,u,w);
        }
        memset(path,-1,sizeof(path));
        SPFA(1);
        flag=1;
        int i=n,j=-1;
        int res=-1;
        while(path[i]!=-1)
        {
            j=path[i];
            e[j].flag=e[j+1].flag=0;
            int tmp=SPFA(1);
            e[j].flag=e[j+1].flag=1;
            if(tmp>res)
                res=tmp;
            i=e[j].u;
        }
        if(res<INF)
            printf("%d\n",res);
        else
            puts("-1");
    }
}
