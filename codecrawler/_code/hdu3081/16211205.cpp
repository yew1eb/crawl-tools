#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 500;
const int maxm = 50000;
const int INF=0x7fffffff;
int idx,n,m,p;
int cur[maxn], pre[maxn];
int dis[maxn], gap[maxn];
int aug[maxn], head[maxn];
int f[maxn];
int hashh[maxn][maxn];
struct Node
{
    int u, v, w;
    int next;
}edge[maxm];
struct peo
{
    int x;
    int y;
}peo[maxm];
void init()
{
    int i;
    for(i=1;i<=n;i++)
    f[i]=i;
}
int find(int x)
{
    int r=x;
    while(f[r]!=r)
    r=f[r];
    f[x]=r;
    return f[x];
}
void Union(int x,int y)
{
    int xx,yy;
    xx=find(x);
    yy=find(y);
    if(xx!=yy)
    f[xx]=yy;
}
void addEdge(int u, int v, int w)
{
    edge[idx].u = u;
    edge[idx].v = v;
    edge[idx].w = w;
    edge[idx].next = head[u];
    head[u] = idx++;
    edge[idx].u = v;
    edge[idx].v = u;
    edge[idx].w = 0;
    edge[idx].next = head[v];
    head[v] = idx++;
}
void build(int mid)
{
    int i,j,st,ed,a,b;
    idx = 0;
    memset(head, -1, sizeof(head));
    st=0;
    ed=2*n+1;
    for(i=1;i<=n;i++)
    {
        addEdge(st,i,mid);  //æºç¹åå¥³å­©å»ºè¾¹
        addEdge(i+n,ed,mid); //ç·å­©åæ±ç¹å»ºè¾¹
    }
    memset(hashh,0,sizeof(hashh));
    for(i=0;i<m;i++)
    {
        a=peo[i].x;
        b=peo[i].y;
        for(j=1;j<=n;j++)
        {
            if(f[a]==f[j]&&!hashh[j][b])  //å¥³å­©çæååèªå·±åç·å­©è¿è¾¹
            {  
                hashh[j][b]=1;
                addEdge(j,b+n,1);
            }
        }
    }
}
int SAP(int s, int e, int n)  //è¿ä¸ªæ¨¡æ¿å¨ç½ä¸æç
{
    int max_flow = 0, v, u = s;
    int id, mindis;
    aug[s] = INF;
    pre[s] = -1;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n; // æè§å¾è¿ä¸å¥è¦ä¸è¦é½è¡ï¼å ä¸ºdis[e]å§ç»ä¸º0
    for (int i = 0; i <= n; ++i)  // åå§åå½åå¼§ä¸ºç¬¬ä¸æ¡å¼§
    cur[i] = head[i];
    while (dis[s] < n)
    {
        bool flag = false;
        if (u == e)
        {
            max_flow += aug[e];
            for (v = pre[e]; v != -1; v = pre[v]) // è·¯å¾åæº¯æ´æ°æ®çç½ç»
            {
                id = cur[v];
                edge[id].w -= aug[e];
                edge[id^1].w += aug[e];
                aug[v] -= aug[e]; // ä¿®æ¹å¯å¢å¹¿éï¼ä»¥åä¼ç¨å°
                if (edge[id].w == 0) u = v; // ä¸åéå°æºç¹ï¼ä»åéå°å®¹éä¸º0çå¼§çå¼§å°¾
            }
        }
        for (id = cur[u]; id != -1; id = edge[id].next)
        {   // ä»å½åå¼§å¼å§æ¥æ¾åè®¸å¼§
            v = edge[id].v;
            if (edge[id].w > 0 && dis[u] == dis[v] + 1) // æ¾å°åè®¸å¼§
            {
                flag = true;
                pre[v] = u;
                cur[u] = id;
                aug[v] = min(aug[u], edge[id].w);
                u = v;
                break;
            }
        }
        if (flag == false)
        {
            if (--gap[dis[u]] == 0) break; /* gapä¼åï¼å±æ¬¡æ åºç°æ­å±åç»æç®æ³ */
            mindis = n;
            cur[u] = head[u];
            for (id = head[u]; id != -1; id = edge[id].next)
            {
                v = edge[id].v;
                if (edge[id].w > 0 && dis[v] < mindis)
                {
                    mindis = dis[v];
                    cur[u] = id; // ä¿®æ¹æ å·çåæ¶ä¿®æ¹å½åå¼§
                }
            }
            dis[u] = mindis + 1;
            gap[dis[u]]++;
            if (u != s) u = pre[u]; // åæº¯ç»§ç»­å¯»æ¾åè®¸å¼§
        }
    }
    return max_flow;
}
int main()
{
    int i,t,ans;
    int a,b;
    int low,high,mid;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(i=0;i<m;i++)
        scanf("%d%d",&peo[i].x,&peo[i].y);
        init();
        while(p--)
        {
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        for(i=1;i<=n;i++)
        f[i]=find(i);
        low=0;
        high=n;  //æå¤nè½®
        ans=0;
        while(low<=high)   //äºåæ±è§£
        {
            mid=(low+high)/2;
            build(mid);
            if(SAP(0,2*n+1,2*n+2)==n*mid)  //å¯ä»¥è¿è¡midè½®
            {
                low=mid+1;
                ans=mid;
            }
            else
            high=mid-1;
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
