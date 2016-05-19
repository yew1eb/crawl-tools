#include <iostream>   
#include <string>   
#include <cstring>   
#include <algorithm>   
#include <cstdio>   
#include <cctype>   
#include <queue>   
#include <stdlib.h>   
#include <cstdlib>   
#include <math.h>   
#include <set>   
#include <vector>   
#define inf 10000000000000000 
#define eps 1e-8   
#define N 2502
#define M 10500
#define ll __int64   
using namespace std;  

//M为边数 N为点数 点标从1-n   
struct Edge{  
    ll from, to, cap, nex;  
}edge[M*10];//注意这个一定要够大 不然会re 还有反向弧  
  
ll head[N], edgenum;  
void addedge(ll u, ll v, ll cap){  
    Edge E = { u, v, cap, head[u]};  
    edge[ edgenum ] = E;  
    head[u] = edgenum ++;  
  
    Edge E2= { v, u, 0,   head[v]};  
    edge[ edgenum ] = E2;  
    head[v] = edgenum ++;  
}  
ll sign[N], s, t;  
bool BFS(ll from, ll to){  
    memset(sign, -1, sizeof(sign));  
    sign[from] = 0;  
  
    queue<ll>q;  
    q.push(from);  
    while( !q.empty() ){  
        int u = q.front(); q.pop();  
        for(ll i = head[u]; i!=-1; i = edge[i].nex)  
        {  
            ll v = edge[i].to;  
            if(sign[v]==-1 && edge[i].cap)  
            {  
                sign[v] = sign[u] + 1, q.push(v);  
                if(sign[to] != -1)return true;  
            }  
        }  
    }  
    return false;  
}  
ll Stack[M*4], top, cur[M*4];  
ll dinic(){  
  
    ll ans = 0;  
    while( BFS(s, t) )  
    {  
        memcpy(cur, head, sizeof(head));  
        ll u = s;      top = 0;  
        while(1)  
        {  
            if(u == t)  
            {  
                ll flow = inf, loc;//loc 表示 Stack 中 cap 最小的边  
                for(ll i = 0; i < top; i++)  
                    if(flow > edge[ Stack[i] ].cap)  
                    {  
                        flow = edge[Stack[i]].cap;  
                        loc = i;  
                    }  
  
                    for(ll i = 0; i < top; i++)  
                    {  
                        edge[ Stack[i] ].cap -= flow;  
                        edge[Stack[i]^1].cap += flow;  
                    }  
                    ans += flow;  
                    top = loc;  
                    u = edge[Stack[top]].from;  
            }  
            for(ll i = cur[u]; i!=-1; cur[u] = i = edge[i].nex)//cur[u] 表示u所在能增广的边的下标  
                if(edge[i].cap && (sign[u] + 1 == sign[ edge[i].to ]))break;  
            if(cur[u] != -1)  
            {  
                Stack[top++] = cur[u];  
                u = edge[ cur[u] ].to;  
            }  
            else  
            {  
                if( top == 0 )break;  
                sign[u] = -1;  
                u = edge[ Stack[--top] ].from;  
            }  
        }  
    }  
    return ans;  
}  

vector<ll>G[N];
ll n, cnt;
void init(){
	memset(head, -1, sizeof(head)); edgenum = 0;
	cnt = 1;
	for(ll i = 0; i <= n; i++)G[i].clear();
}
ll from, to;
int main(){
	ll T, Cas = 1, i, j, k, m, a, b, u, v;scanf("%I64d",&T);
	from = 0; to = 2501;
	s = 0, t = to;
	while(T--){
			scanf("%I64d",&n);
			init();
			ll sum = 0;
			for(i = 1; i <= n; i++){
				scanf("%I64d",&m);
				G[i].push_back(100000);
				for(j = 1; j <= m; j++)
				{
					scanf("%I64d %I64d %I64d",&a,&b,&k);
					G[i].push_back(cnt++);
					sum += b;
					addedge(from, G[i][j], b);
					addedge(G[i][j], to, a);
					while(k--){
						scanf("%I64d %I64d",&u,&v);
						addedge(G[i][j], G[u][v], inf);
					}
				}
			}
			printf("Case #%I64d: %I64d\n", Cas++, sum - dinic());		
	}
	return 0;
}