#include<cstdio>        //EK()ç®æ³ãæ¶é´å¤æåº¦ï¼VE^2ï¼
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 205;
const int INF = (1<<30)-1;
int g[maxn][maxn];
int flow[maxn],pre[maxn];
bool vis[maxn];
int n,m;
int bfs(){
    memset(pre,-1,sizeof(pre));
    memset(vis,false,sizeof(vis));
    queue<int > q;
    vis[1] = true;
    for(int i=1;i<=n;i++)   flow[i]=INF;
    q.push(1);
    while(!q.empty()){
        int now = q.front();  q.pop();
        if(now==n)  break;
        for(int i=1;i<=n;i++){                //å¯»æ¾å¢å¹¿è·¯æå°æµé
            if(!vis[i]&&g[now][i]>0){
                vis[i] = true;
                flow[i] = min(flow[now],g[now][i]);
                pre[i] = now;
                q.push(i);
            }
        }
    }
    if(!vis[n]|| n==1)                         //æ¾ä¸å°å®æ´çå¢å¹¿è·¯oræºç¹æ±ç¹éå
         return -1;
    else
         return flow[n];
}
int EK(){
    int temp,d,res,maxflow;
    maxflow = 0;
    while((d=bfs())!=-1){
         maxflow += d;
         temp=n;
         while(temp!=1){
             res = pre[temp];
             g[res][temp]-=d;               //æ­£åè¾¹
             g[temp][res]+=d;               //ååè¾¹
             temp = res;
         }
    }
    return maxflow;
}
int main(){
    int T,ca=1,m;
    int start,end,capacity;
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&start,&end,&capacity);
            g[start][end]+=capacity;
        }
        printf("%d\n",EK());
    }
    return 0;
}
