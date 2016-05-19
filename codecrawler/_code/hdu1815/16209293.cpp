#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN = 1005;
const int VN   = MAXN*2;
const int EN   = 1200000;

int n, hateNum, likeNum;
int d[VN], sLen;

struct Node{
    int x, y;
}barn[MAXN], hate[VN], like[VN], s1, s2;

struct Edge{
    int v, next;
};

struct Graph{
    int size, head[VN];
    Edge E[EN];
    void init(){
        size=0; 
        memset(head, -1, sizeof(head)); 
    }
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
        low[u] = DFN[u] = ++idx;
        sta[top++] = u;
        instack[u] = true;

        for(int e=g.head[u]; e!=-1; e=g.E[e].next){
            v = g.E[e].v;
            if(DFN[v] == -1){
                tarjan(g, v);
                low[u] = min(low[u], low[v]);
            }else if(instack[v]){
                low[u] = min(low[u], DFN[v]);
            }
        }

        if(DFN[u] == low[u]){
            ++bcnt;
            do{
                v = sta[--top];
                instack[v] = false;
                belong[v]  = bcnt;
            }while(u != v);
        }
    }
    void scc(const Graph& g, const int n){
        bcnt = idx = top = 0;
        memset(DFN, -1, sizeof(DFN));
        memset(instack, 0, sizeof(instack));
        for(int i=0; i<n; ++i)
            if(DFN[i] == -1)
                tarjan(g, i);
    }
private:
    int idx, top, bcnt;
    int DFN[VN], low[VN], belong[VN], sta[VN];
    bool instack[VN];
}sat;

inline int dist(const Node& a, const Node& b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}



void buildGraph(int maxLen){
    g.init();
   
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j)if(i!=j){
            int l1=d[i], l2=d[i+n];
            int r1=d[j], r2=d[j+n];
            if(l1 + r1 > maxLen){
                g.addEdge(i, j+n);
                g.addEdge(j, i+n);
            }    
            if(l1 + r2 + sLen > maxLen){
                g.addEdge(i, j);
                g.addEdge(j+n, i+n);
            }
            if(l2 + r1 + sLen > maxLen){
                g.addEdge(i+n, j+n);
                g.addEdge(j, i);
            }
            if(l2 + r2 > maxLen){
                g.addEdge(i+n, j);
                g.addEdge(j+n, i);
            }
        }
  
    for(int i=0; i<hateNum; ++i){
        int a=hate[i].x, b=hate[i].y;
        g.addEdge(a, b+n);
        g.addEdge(a+n, b);
        g.addEdge(b, a+n);
        g.addEdge(b+n, a);
    }
    for(int i=0; i<likeNum; ++i){
        int a=like[i].x, b=like[i].y;
        g.addEdge(a, b);
        g.addEdge(a+n, b+n);
        g.addEdge(b, a);
        g.addEdge(b+n, a+n);
    } 
}


int main(){
    
    while(~scanf("%d%d%d", &n, &hateNum, &likeNum)){
        
        scanf("%d%d%d%d", &s1.x,&s1.y,&s2.x,&s2.y);
        sLen = dist(s1, s2);
    
        for(int i=0; i<n; ++i){
            scanf("%d%d", &barn[i].x, &barn[i].y);
            d[i] = dist(barn[i], s1);
            d[i+n] = dist(barn[i], s2);
        }

        for(int i=0; i<hateNum; ++i){
            scanf("%d%d", &hate[i].x, &hate[i].y);    
            --hate[i].x;
            --hate[i].y;
        }
    
        for(int i=0; i<likeNum; ++i){
            scanf("%d%d", &like[i].x, &like[i].y);
            --like[i].x;
            --like[i].y;
        }

        int l=0, r=8000000, mid, ans=-1;
        while(l <= r){
            mid = (l+r)>>1;
            buildGraph(mid);
            if(sat.check(g, n)){
                ans = mid;  
                r = mid-1;
            } else
                l = mid+1;
        }
        printf("%d\n", ans);

    }
    return 0;
}