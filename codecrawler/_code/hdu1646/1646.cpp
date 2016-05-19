#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAXN = 110;
const double esp = 1e-8;
int sign(double x){ return x<-esp?-1:(x>esp);}
int n, m, Max;
int S, N, T;

struct Edge{
    int u, v, nxt;
    double f;
}edge[50101];
struct Edge_Info{
    int a,b,c;
    void input(){
        scanf("%d%d%d",&a,&b,&c);
    }
}edge_info[550];
bool vis[MAXN];
int h[MAXN], vh[MAXN];
int head[MAXN], idx;

void AddEdge(int a,int b,double f){
    edge[idx].u = a, edge[idx].v = b, edge[idx].f = f;
    edge[idx].nxt = head[a], head[a] = idx++;
    edge[idx].u = b, edge[idx].v = a, edge[idx].f = 0;
    edge[idx].nxt = head[b], head[b] = idx++;
}
double CreateGraph(double MaxW){
    memset( head, -1, sizeof(head));
    idx = 0;
    double tmp_val = 0;
    for(int i = 1; i <= m; i++){
        int a = edge_info[i].a, b = edge_info[i].b, c = edge_info[i].c;
        if( sign(c - MaxW) < 0 )
            tmp_val += c-MaxW;
        else AddEdge(a,b,c-MaxW),AddEdge(b,a,c-MaxW);
    }
    return tmp_val;
}
double dfs(int u,double flow){
    if(u == T) return flow;
    int tmp = h[u]+1; double sum = flow;
    for(int i = head[u]; ~i; i = edge[i].nxt){
        if( sign(edge[i].f) > 0 && (h[ edge[i].v ]+1 == h[u])){
            double p = dfs( edge[i].v, min(sum,edge[i].f));
            edge[i].f -= p, edge[i^1].f += p, sum -= p;
            if( sign(sum)==0 || h[S]==N ) return flow-sum;
        }
    }
    for(int i = head[u]; ~i; i = edge[i].nxt ){
        if( sign(edge[i].f) > 0 ) tmp = min(tmp,h[ edge[i].v ] );
    }
    if( --vh[ h[u] ] == 0 ) h[S] = N;
    else ++vh[ h[u]=tmp+1 ];
    return flow-sum;
}
double sap(){
    double maxflow = 0;
    memset(h,0,sizeof(h));
    memset(vh,0,sizeof(vh));
    vh[0] = N;
    while( h[S] < N ) maxflow += dfs( S,inf );
    return maxflow;
}
double Search( double l, double r ){
    while( r-l > 1e-5 ){
        double mid = (r+l)/2.0;
        double maxflow = CreateGraph( mid );
        maxflow += sap();
        if( sign(maxflow) < 0 ) r = mid;
        else l = mid;
    }
    return l;
}
void DFS(int u){
    vis[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt){
        if( sign(edge[i].f) > 0 && !vis[ edge[i].v ] )
            DFS( edge[i].v );
    }
}

vector<int> res;
int mp[MAXN][MAXN];

void solve(){
    S = 1, T = n, N = n;
    double limit = Search( 0, Max );
    double maxflow = CreateGraph( limit );
    maxflow += sap();
    res.clear();
    memset(vis,0,sizeof(vis));
    DFS(S);
    for(int i = 1; i <= m; i++){
        mp[ edge_info[i].a ][ edge_info[i].b ] = i;
        mp[ edge_info[i].b ][ edge_info[i].a ] = i;
        if( sign(edge_info[i].c-limit) < 0 )
            res.push_back(i);
    }
    for(int i = 0; i < idx; i += 2 ){ // 10000
        int u = edge[i].u, v = edge[i].v;
        if( vis[u] && !vis[v] && sign( edge[i].f ) == 0 ){ //500
            res.push_back(  mp[u][v] );
        }
    }
    sort( res.begin(), res.end() );
    int num = res.size();
    printf("%d\n", num );
    for(int i = 0; i < num; i++)
        printf( i==0? "%d":" %d", res[i] );
    printf("\n");
}
int main(){
    int Case = 1;
    while( scanf("%d%d",&n,&m) != EOF) {
        Max = 0;
        for(int i = 1; i <= m; i++){
            edge_info[i].input();
            Max = max( Max, edge_info[i].c );
        }
        solve();
        if( Case++ > 1 ) puts("");
    }
    return 0;
}