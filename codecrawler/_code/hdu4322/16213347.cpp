#include <cstring>
#include <cstdio>
const int maxn = 100;
const int maxm = maxn * maxn * 2;
const int inf = 1000000000;

int n, m, k;
int b[maxn], sumB;
int c[maxn][maxn];
int src, des;

struct Edge{
    int u, v, w, f, nxt;
}edge[maxm];
int edgeNum, head[maxn];

inline void initEdge(){
    edgeNum = 0;
    memset(head, - 1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w, int f){
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].f = f;
    edge[edgeNum].nxt = head[u];
    head[u] = edgeNum ++;
}

inline void addEdge(int u, int v, int w, int f){
    addEdgeSub(u,v,w,f);
    addEdgeSub(v,u,-w,0);
}

void buildGraph(){
    initEdge();
    src = 0;
    des = n + m + 1;
    for(int i = 0; i < n; i ++){
        addEdge(src, i + 1, 0, 1);
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(c[i][j]){
                addEdge(j + 1, i + n + 1,0,1);//
            }
        }
        addEdge(i + n + 1, des, k, b[i] / k);
        if(b[i] % k > 1){
            addEdge(i + n + 1, des, b[i] % k, 1);
        }
    }
}

int dis[maxn];
int queue[maxn];
bool vis[maxn];
int back[maxn];

bool bfs(){
    int front = 0, rear = 1;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    queue[0] = src;
    dis[src] = 0;
    vis[src] = true;
    back[src] = -1;
    bool flag = false;
    while(front != rear){
        int u = queue[front];
        for(int i = head[u]; i != -1; i = edge[i].nxt){
            int v = edge[i].v;
            int w = edge[i].w;
            if(edge[i].f){
                if(dis[v] < dis[u] + w){
                    dis[v] = dis[u] + w;
                    back[v] = i;
                    if(!vis[v]){
                        vis[v] = true;
                        queue[rear] = v;
                        if(++ rear >= maxn){
                            rear = 0;
                        }
                    }
                }
            }
        }
        vis[u] = false;
        if(++ front >=  maxn){
            front = 0;
        }
    }
    return dis[des] != -1;
}

int getFlow(){
    int tmp = des;
    int Min = inf;
    while(back[tmp] != -1){
        if(edge[back[tmp]].f < Min){
            Min = edge[back[tmp]].f;
        }
        tmp = edge[back[tmp]].u;
    }
    tmp = des;
    while(back[tmp] != -1){
        edge[back[tmp]].f -= Min;
        edge[back[tmp] ^ 1].f += Min;
        tmp = edge[back[tmp]].u;
    }
    return Min;
}

bool judge(){
    int cost = 0, flow = 0;
    while(bfs()){
        cost += dis[des];
        flow += getFlow();
    }
    return n - flow >= sumB - cost;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int ca = 1; ca <= T; ca ++){
        scanf("%d%d%d",&n,&m,&k);
        sumB = 0;
        for(int i = 0; i < m; i ++){
            scanf("%d",&b [i]);
            sumB += b[i];
        }
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                scanf("%d",&c[i][j]);
            }
        }
        buildGraph();
        printf("Case #%d: ",ca);
        if(judge())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
