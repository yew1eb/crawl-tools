/*
å®çï¼
1ãæå¤§ç¹æç¬ç«é = sum - æå°ç¹æè¦çéã
2ãæå°ç¹æè¦çé = æå°å² = æå¤§æµ
å®ç°ï¼dinicç®æ³
*/

#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

const int nMax = 2505;
const int INF = 0x7fffffff;
int queue[nMax];//å»ºç«å±æ¬¡å¾æ¶ä½¿ç¨å°çéå
int dis[nMax];//åèç¹å¨å±æ¬¡å¾ä¸­å¯¹åºçå±æ¬¡æ°
struct Edge
        //é»æ¥è¡¨ï¼åæ¬ï¼è¾¹çèµ·ç¹ãè¾¹çæå¼ãèµ·ç¹ç¸åçä¸ä¸æ¡è¾¹
{
    int v, w, next;
    Edge() {}
    Edge(int v, int w, int next):v(v), w(w), next(next) {}
} adj[8 * nMax];
int V[nMax];//V[u]è¡¨ç¤ºèµ·ç¹ä¸ºuçç¬¬ä¸æ¡è¾¹ï¼ä¸Edgeç»åä½¿ç¨ï¼ä»èå®ç°é»æ¥è¡¨çææ
int cnt;
int s, t;

int min(int a, int b)
{
    return a < b ? a : b;
}

void add(int u, int v, int w)//åé»æ¥è¡¨ä¸­æ·»å  u - > v ç»æ
{
    adj[cnt] = Edge(v, w, V[u]);
    V[u] = cnt ++;
    adj[cnt] = Edge(u, 0, V[v]);
    V[v] = cnt ++;
}

int bfs()//å»ºå±æ¬¡å¾
{
    int front, rear;
    int v;
    memset(dis, 0, sizeof(dis));
    front = rear = 0;
    dis[s] = 1;
    queue[front ++] = s;
    while(rear < front)
    {
        int u = queue[rear ++];
        for(int i = V[u]; i != -1; i = adj[i].next)//ä¸uç¸è¿çè¾¹
            if(adj[i].w && dis[v = adj[i].v] == 0)//å¯éè¡å¹¶ä¸ v ä¹é´æ²¡æè¢«è®¿é®è¿
            {
                dis[v] = dis[u] + 1;
                if(v == t) return 1;
                queue[front ++] = v;
            }
    }
    return 0;
}

int dfs(int u, int limit = INF)//è¿åä»uåºåå°tï¼å¢å¹¿è·¯ç»çæå°è¾¹
{
    if(u == t) return limit;
    int count = 0;
    for(int i = V[u]; i != -1; i = adj[i].next)//ä¸u ç¸è¿çè¾¹
    {
        int v = adj[i].v;
        if((dis[v] == dis[u] + 1) && adj[i].w)//æ ¹æ®å±æ¬¡çå³ç³»ï¼æ¾å°çè·¯å¾å°±ä¸ºæç­è·¯å¾
        {
            int z = dfs(v, min(limit - count, adj[i].w));
            if(z > 0)//å¢å¹¿è·¯ç»çæå°è¾¹ä¸ä¸º0ï¼å³vå°tå¯éè¡
            {
                count += z;
                adj[i].w -= z;
                adj[i ^ 1].w += z;//æ¹ä¸ºadj[i + 1] += z  ï¼ ä¼è¶æ¶ï¼
            }
            else
                dis[v] = -1;//ææç­åäºå é¤ä¸vç¸å³çææè¾¹
        }
    }
    return count;
}

int dinic()
{
    int ans = 0;
    while(bfs())//ç´å°æç´¢ä¸å°å¢å¹¿è·¯ç»ä¸ºæ­¢
        ans += dfs(s);
    return ans;
}
void init()
{
    cnt = 0;
    memset(V, -1, sizeof(V));
}
int main()
{
    int m, n;
    int sum;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        init();
        int x;
        sum = 0;
        s = 0;
        t = m * n + 1;
        for(int i = 1; i <= m; ++ i)
            for(int j = 1; j <= n; ++ j)
            {
                scanf("%d", &x);
                sum += x;
                if((i + j) & 1)
                {
                    add(s, (i - 1) * n + j, x);
                    //ä¸
                    if(i > 1) add((i - 1) * n + j, (i - 2) * n + j, INF);
                    //ä¸
                    if(i < m) add((i - 1) * n + j, i * n + j, INF);
                    //å·¦
                    if(j > 1) add((i - 1) * n + j, (i -1) * n + j - 1, INF);
                    //å³
                    if(j < n) add((i - 1) * n + j, (i - 1) * n + j + 1, INF);
                }
                else
                    add((i - 1) * n + j, t, x);
            }
            printf("%d\n",sum - dinic());
    }
    return 0;
}
