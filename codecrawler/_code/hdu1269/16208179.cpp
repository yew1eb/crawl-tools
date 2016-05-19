/*2012-12-06 20:16:08    Accepted    1269    46MS    1484K    1339 B    C++*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define maxn 10010

int n;
vector<int> g[maxn];

int Bcnt; /// å¼ºè¿éåéçä¸ªæ°ï¼
int Top; /// æ é¡¶ï¼
int Index; /// æ¶é´æ³ï¼
int low[maxn], dfn[maxn];
int belong[maxn], stack[maxn];
bool instack[maxn];

void Init_tarjan(){
    Bcnt= Top= Index= 0;
    for(int i=1; i<=n; ++i) low[i]= dfn[i]= 0;
}
void Tarjan(int u){
    stack[Top++]= u;
    instack[u]= 1;
    low[u]= dfn[u]= ++Index;
    for(int i=0; i<g[u].size(); ++i){
        int v= g[u][i];
        if( !dfn[v] ){
            Tarjan(v);
            low[u]= min( low[v], low[u] );
        }
        else if( instack[v] )
            low[u]= min( low[u], dfn[v] );
    }
    if( low[u]==dfn[u] ){
        ++Bcnt;
        int v;
        do{
            v= stack[--Top];
            instack[v]= 0;
            belong[v]= Bcnt;
        }while( u!=v );
    }
}

int main()
{
    int m;
    while( cin>>n>>m, n+m ){
        for(int i=1; i<=n; ++i) g[i].clear();
        while(m--){
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        Init_tarjan();
        for(int i=1; i<=n; ++i){
            if( !dfn[i] )
                Tarjan(1);
        }

        puts( Bcnt==1 ? "Yes" : "No" );
    }
}
