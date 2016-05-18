#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
#define inf 9999999
const int maxn=10000+5;
const int maxm=100+10;
struct Node
{
    int to,val;
    Node(int x,int y):to(x),val(y){}
};
int g[maxm][maxm],st[maxm],dist[maxn],que[maxn];
bool mark[maxn];
map<int,int>Map;
vector<Node>edge[maxn];
int n,h;
void SPFA(int v)
{
    for(int i=1; i<=n; i++) dist[i]=inf,mark[i]=0;
    dist[v]=0;
    int front=0,back=0;
    que[back++]=v;
    mark[v]=true;
    while(front!=back)
    {
        int u=que[front++];
        if(front==maxn) front=0;
        mark[u]=false;
        for(int i=0; i<edge[u].size(); i++)
        {
            int to=edge[u][i].to;
            int val=edge[u][i].val;
            if(dist[to]>dist[u]+val)
            {
                dist[to]=dist[u]+val;
                if(!mark[to])
                {
                    mark[to]=true;
                    que[back++]=to;
                    if(back==maxn) back=0;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
        if(dist[i]<=600)
            g[Map[v]][Map[i]]=1;
}
void floyd()
{
    for(int k=0; k<=h+1; k++)
        for(int i=0; i<=h+1; i++)
            for(int j=0; j<=h+1; j++)
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        Map.clear();
        for(int i=1; i<=n; i++) edge[i].clear();
        scanf("%d",&h);
        for(int i=1; i<=h; i++)
        {
            scanf("%d",&st[i]);
            Map[st[i]]=i;
        }
        st[0]=1;st[h+1]=n;
        Map[1]=0;Map[n]=h+1;
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge[u].push_back(Node(v,w));
        }
        for(int i=0; i<=105; i++)
            for(int j=0; j<=105; j++)
                if(i!=j) g[i][j]=inf;
                else g[i][j]=0;
        for(int i=1; i<=h; i++)
            SPFA(st[i]);
        floyd();
        if(g[0][h+1]==inf) printf("-1\n");
        else printf("%d\n",g[0][h+1]-1);
    }
    return 0;
}