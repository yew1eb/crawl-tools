#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x7fffffff
#define eps 1e-8
#define pb push_back
#define pf printf
#define sf scanf
#define REP0(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define maxn 205
int sink,source,edgeNum;
int head[maxn],pre[maxn],vis[maxn];
double dis[maxn];
struct node{
    int to,next,cap;
    double cost;
}edge[21000];
int min(int a,int b){   return a<b?a:b; }
int init(){
    edgeNum =0;
    memset(head,-1,sizeof head);
    return 0;
}
int addEdge(int from,int to,int cap,double cost){
    edge[edgeNum].to = to; edge[edgeNum].cap = cap;
    edge[edgeNum].cost = cost;
    edge[edgeNum].next = head[from];
    head[from] = edgeNum++;
    edge[edgeNum].to = from; edge[edgeNum].cap = 0;
    edge[edgeNum].cost = -cost;
    edge[edgeNum].next = head[to];
    head[to] = edgeNum++;
    return 0;
}
bool spfa(){
    queue<int> que;
    memset(pre,-1,sizeof pre);
    memset(vis,0,sizeof vis);
    REP0(i,sink+1) dis[i] = INF;
    vis[source] = true; dis[source] = 0;
    que.push(source);
    while(!que.empty()){
        int now = que.front(); que.pop();
        for(int j=head[now];j!=-1;j=edge[j].next){
           int to = edge[j].to,cap=edge[j].cap;
           double cost=edge[j].cost;
           //pf("%d %d--\n",j,now);
            if(cap>0&&dis[to]>dis[now]+cost){
                dis[to] = dis[now] + cost;
                pre[to] = j;
                if(!vis[to]){
                    que.push(to);
                    vis[to] = 1;
                }
            }
        }
        vis[now] =0;
    }
    //pf("---");
    return pre[sink] != -1;
}
double MFMC(int& flow){
    flow = 0;
    int minFlow;
    double minCost=0;
    while(spfa()){
        minFlow = INF;
        for(int i=pre[sink];i!=-1;){
            int to = edge[i^1].to;
            //pf("%d\n",i);
            minFlow = min(minFlow,edge[i].cap);
            i= pre[to];
        }
        flow += minFlow;
        //pf("%d\n",minFlow);
        for(int i=pre[sink];i!=-1;){
            int to = edge[i^1].to;
            edge[i].cap -= minFlow;
            edge[i^1].cap += minFlow;
            i = pre[to];
        }
        minCost += dis[sink];
        //cout << dis[sink]<<endl;
        //pf("%d-\n",minCost);
    }
    return minCost;
}
double data[12][1005];
int main(){
    //freopen("end.in","r",stdin);
    int n,m;
    int t; cin >> t; int p=0;
    while(t--){
        double ans =0;
        sf("%d%d",&n,&m);
        REP1(i,n){
            REP0(j,m){
                sf("%lf",&data[i][j]);
            }
        }
        int cnt =0;
        while(cnt*n<m){
            init();
            source =0;  sink = n*2 +1;
            REP1(i,n) addEdge(0,i,1,0);
            REP1(i,n) addEdge(i+n,sink,1,0);
            REP1(i,n){
                REP(j,0,min((cnt+1)*n,m)-cnt*n){
                    double cost;
                    cost = data[i][j+n*cnt];
                    //cout << i << " " << j+n +1<< " " << cost << endl;
                    addEdge(i,j+n+1,1,-cost);
                }
            }
            int num;
            ans += MFMC(num);
            //cout << ans << endl;
            cnt++;
        }
        p++;
        pf("Case #%d: ",p);
        pf("%0.5lf\n",-ans);
    }
    return 0;
}