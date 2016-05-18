#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long int64;

const int MAXN = 10010;
const int VN = MAXN*2;
const int EN = VN*3;
int n, m;
int pat[MAXN];
int alice[MAXN][2];

struct Edge{
    int v, next;
};

class Graph{
public: 
    void init(){
        size = 0;
        memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v){
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
public:
    int head[VN];
    Edge E[EN];
private:
    int size;
}g;

class Two_Sat{
public: 
    bool check(const Graph&g, const int n){
        scc(g, n); 
        for(int i=0; i<n; ++i)
            if(belong[2*i] == belong[2*i+1])
                return false;
        return true;
    }
private:
    void tarjan(const Graph&g, const int u){
        int v;
        DFN[u] = low[u] = ++idx;
        sta[top++] = u;
        inStack[u] = true;

        for(int e=g.head[u]; e!=-1; e=g.E[e].next){
            v = g.E[e].v;
            if(DFN[v] == -1){
                tarjan(g, v);
                low[u] = min(low[u], low[v]);
            }else if(inStack[v]){
                low[u] = min(low[u], DFN[v]);
            }
        }
        if(DFN[u] == low[u]){
            ++bcnt;
            do{
                v = sta[--top];
                inStack[v] = false;
                belong[v] = bcnt;
            }while(u != v);
        }
    }
    void scc(const Graph& g, int n){
        top = idx = bcnt = 0;
        memset(DFN, -1, sizeof(DFN));
        memset(inStack, 0, sizeof(inStack));
        for(int i=0; i<2*n; ++i)
            if(DFN[i] == -1)
                tarjan(g, i);
    }

private:
    int top, idx, bcnt;
    int sta[VN];
    int DFN[VN];
    int low[VN];
    int belong[VN];
    bool inStack[VN];

}sat;


int main(){

    int nCase;
    int cas=1;
    int a, b, c;
    scanf("%d", &nCase);

    while(nCase--){
    
        g.init();
        scanf("%d%d", &n,&m);
        for(int i=0; i<n; ++i){
            scanf("%d", &pat[i]);
            pat[i]--;
            alice[i][0] = pat[i];
            alice[i][1] = (pat[i]+1)%3;
        }
        for(int i=0; i<m; ++i){
            scanf("%d%d%d", &a,&b,&c);
            --a, --b;
            if(c){ // a,b不同
                if(alice[a][0]==alice[b][0])
                    g.addEdge(a*2, b*2+1), g.addEdge(b*2, a*2+1);
                if(alice[a][0]==alice[b][1])
                    g.addEdge(a*2, b*2), g.addEdge(b*2+1, a*2+1);
                if(alice[a][1]==alice[b][0])
                    g.addEdge(a*2+1, b*2+1), g.addEdge(b*2, a*2);
                if(alice[a][1]==alice[b][1])
                    g.addEdge(a*2+1, b*2), g.addEdge(b*2+1, a*2);

            }else{ // a, b相同 
                if(alice[a][0]!=alice[b][0])
                    g.addEdge(a*2, b*2+1), g.addEdge(b*2, a*2+1);
                if(alice[a][0]!=alice[b][1])
                    g.addEdge(a*2, b*2), g.addEdge(b*2+1, a*2+1);
                if(alice[a][1]!=alice[b][0])
                    g.addEdge(a*2+1, b*2+1), g.addEdge(b*2, a*2);
                if(alice[a][1]!=alice[b][1])
                    g.addEdge(a*2+1, b*2), g.addEdge(b*2+1, a*2);

            }
        }
        printf("Case #%d: ", cas++);
        if(sat.check(g, n)) puts("yes");
        else puts("no");
    
    }

    return 0;
}