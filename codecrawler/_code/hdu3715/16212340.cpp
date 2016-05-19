#include<iostream>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<vector>
#define MP make_pair
#define SQ(x) ((x)*(x))
using namespace std;


const int INF  = 0x3f3f3f3f;
const int MAXN = 10010;
const int VN = MAXN*2;
const int EN = VN*4;

int n, m, s;
int a[MAXN], b[MAXN], c[MAXN];

struct Graph{
    int size, head[VN];
    struct{int v, next; }E[EN];
    void init(){size=0; memset(head, -1, sizeof(head)); };
    void addEdge(int u, int v){
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
}g;

class Two_Sat{
public:
    bool check(const Graph& g, const int n){
        scc(g, 2*n);
        for(int i=0; i<n; ++i)
            if(belong[i] == belong[i+n])
                return false;
        return true;
    }
private:
    void tarjan(const Graph& g, const int u){
        int v;
        dfn[u] = low[u] = ++idx;
        sta[top++] = u;
        instack[u] = true;

        for(int e=g.head[u]; e!=-1; e=g.E[e].next){
            v = g.E[e].v;
            if(dfn[v] == -1){
                tarjan(g, v);
                low[u] = min(low[u], low[v]);
            }else if(instack[v]){
                low[u] = min(low[u], dfn[v]);   
            }
        }

        if(dfn[u] == low[u]){
            ++bcnt;
            do{
                v = sta[--top];
                instack[v] = false;
                belong[v] = bcnt;
            }while(u != v);
        }
    }
    
    void scc(const Graph& g, const int n){
        idx = top = bcnt = 0;
        memset(dfn, -1, sizeof(dfn));
        memset(instack, 0, sizeof(instack));
        for(int i=0; i<n; ++i){
            if(dfn[i] == -1)
                tarjan(g, i);
        }
    }

private:
    int idx, top, bcnt;
    int dfn[VN], low[VN], sta[VN], belong[VN];
    bool instack[VN];
}sat;


void buildGraph(int dep){
    g.init();
    for(int i=0; i<dep; ++i){
        int x=a[i], y=b[i];
        if(c[i]==0){
            g.addEdge(x, y+m);
            g.addEdge(y, x+m);
        }else if(c[i] == 1){
            g.addEdge(x, y);
            g.addEdge(x+m, y+m);
            g.addEdge(y, x);
            g.addEdge(y+m, x+m);
        }else if(c[i] == 2){
            g.addEdge(x+m, y);
            g.addEdge(y+m, x);
        }
    }
    
}
int main(){

    int nCase;
    scanf("%d", &nCase);

    while(nCase--){
    
        scanf("%d%d", &n, &m);
        
        for(int i=0; i<m; ++i){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        
        int l=0, r=m+1, mid, ans;
        while(l < r){
            mid = (l + r) >> 1;
            buildGraph(mid);
            if(sat.check(g, m)){
                l = mid+1;
                ans = mid;
            } else r = mid;
        }
        printf("%d\n", ans);
    }

    return 0;
}