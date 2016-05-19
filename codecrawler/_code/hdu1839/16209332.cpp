#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 0x7fffffff;
const int VN  =  10005;
const int EN  =  50005;

struct Edge{int v,next,cap,time;}E[EN*2];

int n, m, t;
int size;
int head[VN];
int cap[EN];
int d[VN];
int Time[VN];
int limit;
bool inq[VN];

void init(){
    size=0;
    memset(head, -1, sizeof(head));
}
void addEdge(int u,int v,int c,int d){
    E[size].v=v;
    E[size].cap=c;
    E[size].time=d;
    E[size].next = head[u];
    head[u] = size++;
}
int Dijkstra(int src){
    memset(inq, 0, sizeof(inq));
    for(int i=1; i<=n; ++i)d[i]=INF;
    d[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = false;
        for(int e=head[u]; e!=-1; e=E[e].next)if(E[e].cap>=limit){
            int tmp = d[u]+E[e].time;
            if(d[E[e].v] > tmp){
                d[E[e].v] = tmp;
                if(!inq[E[e].v]){
                    inq[E[e].v] = true;
                    q.push(E[e].v);
                }
            }
        }
    }
    return d[n];
}

int main(){
    int T, u, v, c, d;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&t);
        init();
        for(int i=0; i<m; ++i){
            scanf("%d%d%d%d",&u,&v,&c,&d);
            cap[i]=c;
            addEdge(u,v,c,d);
            addEdge(v,u,c,d);
        }
        sort(cap, cap+m,greater<int>());
        // äºåæ±è§£
        int left=0, right=m-1, mid;
        while(left<right){
            mid = (left+right)>>1;
            limit = cap[mid];
            int tmp=Dijkstra(1);
            if(tmp==INF || tmp>t){
                left = mid+1;
            }
            else{
                right=mid;
            }
        }
        printf("%d\n", cap[left]);
    }
    return 0;
}