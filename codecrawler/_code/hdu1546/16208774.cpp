#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;

const int INF = 0x7fffffff;
const int VN  = 1005;

struct Edge{int v,next,w;}E[VN*VN];
struct Idiom{
    char beg[5], end[5];
}arr[VN];

int n,size;
int head[VN];
int d[VN];
int cost[VN];

void init(){
    size=0;
    memset(head, -1, sizeof(head));
    while(!q.empty())q.pop();
}
void addEdge(int u,int v,int w){
    E[size].v=v, E[size].w=w;
    E[size].next = head[u];
    head[u] = size++;
}

void Dijkstra(int src){
    for(int i=1; i<=n; ++i) d[i] = INF;
    d[src] = 0;
    q.push(make_pair(d[src],src));
    while(!q.empty()){
        pii x = q.top(); q.pop();
        int u = x.second;
        if(d[u] != x.first) continue;
        for(int e=head[u]; e!=-1; e=E[e].next){
            int tmp = d[u] + E[e].w;
            if(d[E[e].v] > tmp){
                d[E[e].v] = tmp;
                q.push(make_pair(tmp, E[e].v));
            }
        }
    }
}

int main(){
    int w;
    char str[100];
    while(scanf("%d",&n)&&n){
        init();
        for(int i=1; i<=n; ++i){
            scanf("%d %s",&cost[i],str);
            for(int j=0; j<5; ++j) 
                arr[i].beg[j]=str[j];
            int len = strlen(str);
            for(int j=len-4,k=0; j<len; ++j,++k) 
                arr[i].end[k]=str[j];
            arr[i].end[4] = arr[i].beg[4] = 0;
        }
        for(int i=1; i<n; ++i){
            for(int j=1; j<=n; ++j){
                if(strcmp(arr[i].end, arr[j].beg)==0)
                    addEdge(i,j,cost[i]); 
            }
        }
        Dijkstra(1);
        if(d[n]!=INF) printf("%d\n", d[n]);
        else  puts("-1");
    }
    return 0;
}
