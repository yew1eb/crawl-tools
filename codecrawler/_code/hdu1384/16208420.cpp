#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

template<int N,int M>
struct Graph
{
    int top;
    struct Vertex{
        int head;
    }V[N];
    struct Edge{
        int v,next;
        int w;
    }E[M];
    void init(){
        memset(V,-1,sizeof(V));
        top = 0;
    }
    void add_edge(int u,int v,int w){
        E[top].v = v;
        E[top].w = w;
        E[top].next = V[u].head;
        V[u].head = top++;
    }
};

Graph<50005,150005> g;

const int N = 5e4 + 5;

int d[N],inqCnt[N];

bool inq[N];

bool spfa(int s,int n)
{
    memset(inqCnt,0,sizeof(inqCnt));
    memset(inq,false,sizeof(inq));
    memset(d,-63,sizeof(d));
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    d[s] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        for(int i=g.V[u].head;~i;i=g.E[i].next)
        {
            int v = g.E[i].v;
            int w = g.E[i].w;
            if(d[u] + w > d[v])
            {
                d[v] = d[u] + w;
                if(!inq[v])
                {
                    Q.push(v);
                    inq[v] = true;
                    if(++inqCnt[v] > n)
                        return true;
                }
            }
        }
        Q.pop();
        inq[u] = false;
    }
    return false;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        g.init();
        int L = 50005 , R = 0;
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ++a , ++b;
            L = min(L,a);
            R = max(R,b);
            g.add_edge(a-1,b,c);
        }
        for(int i=L;i<=R;i++)
        {
            g.add_edge(i-1,i,0);
            g.add_edge(i,i-1,-1);
        }
        spfa(L-1,R-L+2);
        printf("%d\n",d[R]);
    }
    return 0;
}
