#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000") //不需要申请系统栈
const int N = 40010;
const int M = 25;

int _pow[M];
int tot,head[N],ver[2*N],R[2*N],first[N],dir[N];
int dp[2*N][M];  //这个数组记得开到2*N，因为遍历后序列长度为2*n-1
bool vis[N];
struct edge
{
    int u,v,w,next;
}e[2*N];

inline void add(int u ,int v ,int w ,int &k)
{
    e[k].u = u; e[k].v = v; e[k].w = w; 
    e[k].next = head[u]; head[u] = k++;
    u = u^v; v = u^v; u = u^v;
    e[k].u = u; e[k].v = v; e[k].w = w; 
    e[k].next = head[u]; head[u] = k++;
}

void dfs(int u ,int dep)
{
    vis[u] = true; ver[++tot] = u; first[u] = tot; R[tot] = dep;
    for(int k=head[u]; k!=-1; k=e[k].next)
        if( !vis[e[k].v] )
        {
            int v = e[k].v , w = e[k].w;
            dir[v] = dir[u] + w;
            dfs(v,dep+1);
            ver[++tot] = u; R[tot] = dep;
        }
}

void ST(int len)
{
    int K = (int)(log((double)len) / log(2.0));
    for(int i=1; i<=len; i++) dp[i][0] = i;
    for(int j=1; j<=K; j++)
        for(int i=1; i+_pow[j]-1<=len; i++)
        {
            int a = dp[i][j-1] , b = dp[i+_pow[j-1]][j-1];
            if(R[a] < R[b]) dp[i][j] = a;
            else            dp[i][j] = b;
        }
}

int RMQ(int x ,int y)
{
    int K = (int)(log((double)(y-x+1)) / log(2.0));
    int a = dp[x][K] , b = dp[y-_pow[K]+1][K];
    if(R[a] < R[b]) return a;
    else            return b;
}

int LCA(int u ,int v)
{
    int x = first[u] , y = first[v];
    if(x > y) swap(x,y);
    int res = RMQ(x,y);
    return ver[res];
}

int main()
{
    for(int i=0; i<M; i++) _pow[i] = (1<<i);
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int n,q,num = 0;
        scanf("%d%d",&n,&q);
        memset(head,-1,sizeof(head));
        memset(vis,false,sizeof(vis));
        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w,num);
        }
        tot = 0; dir[1] = 0;
        dfs(1,1);
        /*
        printf("节点 "); for(int i=1; i<=2*n-1; i++) printf("%d ",ver[i]); cout << endl;
        printf("深度 "); for(int i=1; i<=2*n-1; i++) printf("%d ",R[i]);   cout << endl;
        printf("首位 "); for(int i=0; i<n; i++) printf("%d ",first[i]);    cout << endl;
        printf("距离 "); for(int i=0; i<n; i++) printf("%d ",dir[i]);      cout << endl;
        */
        ST(2*n-1);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int lca = LCA(u,v);
//            printf("lca = %d\n",lca);
            printf("%d\n",dir[u] + dir[v] - 2*dir[lca]);
        }
    }
    return 0;
}