/*
每个点找其最小的入边In[v] ? 如果有除跟节点以外的点找不到入边,则无解 : 否则答案累加In[v]
看看有没有环 ? 无环则已经找到解,返回答案 : 将环缩点
重新构图,每条边[u->v]的权值减去In[v],然后重复第一步*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 1101
#define INF 1000000000
using namespace std;
struct edge
{
    int u , v , w;
}e[M * M];
struct point
{
    int x,y,z;
}home[M];
int pre[M],id[M],vis[M],in[M];
int n,m,X,Y,Z;
int Directed_MST(int root,int NV,int NE)
{
    int ret = 0;
    while(true){
        //步骤1：找到最小边
        for(int i = 0;i < NV;i ++)
            in[i] = INF;
        for(int i = 0;i < NE;i ++){
            int u = e[i].u , v = e[i].v;
            if(e[i].w < in[v] && u != v){
                pre[v] = u;
                in[v] = e[i].w;
            }
        }
        for(int i = 0;i < NV;i ++){
            if(i == root) continue;
            if(in[i] == INF) return -1;//除了根节点以外有点没有入边，则根无法到达他
        }
        int cntnode = 0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        //找环
        in[root] = 0;
        for(int i = 0;i < NV;i ++){//标记每个环，编号
            ret += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1){
                for(int u = pre[v];u != v;u = pre[u]){
                    id[u] = cntnode;
                }
                id[v] = cntnode ++;
            }
        }
        if(cntnode == 0) break;//无环
        for(int i = 0;i < NV;i ++)
            if(id[i] == -1){
                id[i] = cntnode ++;
            }
        //步骤3：缩点，重新标记
        for(int i = 0;i < NE;i ++){
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if(e[i].u != e[i].v) e[i].w -= in[v];
        }
        NV = cntnode;
        root = id[root];
    }
    return ret;
}
int dis(int a,int b)
{
    return abs(home[a].x - home[b].x) + abs(home[a].y - home[b].y) + abs(home[a].z - home[b].z);
}
void add_edge(int u,int v,int w)
{
    e[m].u = u , e[m].v = v,e[m].w = w;
    m ++;
}
int main()
{
    while(scanf("%d%d%d%d",&n,&X,&Y,&Z) != EOF && n){
        m = 0;
        for(int i = 1;i <= n;i ++){
            scanf("%d%d%d",&home[i].x,&home[i].y,&home[i].z);
            add_edge(0,i,home[i].z * X);
        }
        for(int i = 1;i <= n;i ++){
            int num , u = i , v , w;
            scanf("%d",&num);
            for(int j = 0;j < num;j ++){
                scanf("%d",&v);
                if(v == i) continue;
                w = dis(u,v) * Y;
                if(home[v].z > home[u].z) w += Z;
                add_edge(u,v,w);
            }
        }
        int ans = Directed_MST(0,n + 1,m);
        printf("%d\n",ans);
    }
    return 0;
}