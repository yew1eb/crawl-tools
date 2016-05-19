#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 510
#define NN 1010
#define M 3000100
using namespace std;
int n,b[N][N];

int head[NN],cnt,scc,top,Index;
int dfn[NN],low[NN],instack[NN],sstack[NN],belong[NN];
struct Edge{
    int v,next;
}edge[M];

void addedge(int u,int v){
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void init(){
    memset(head,-1,sizeof(head));
    memset(instack,0,sizeof(instack));
    memset(dfn,0,sizeof(dfn));
    cnt=Index=top=scc=0;
}

void tarjan(int u){
    dfn[u]=low[u]=++Index;
    sstack[++top]=u;
    instack[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        scc++;
        while(1){
            int tmp=sstack[top--];
            instack[tmp]=0;
            belong[tmp]=scc;
            if(tmp==u)break;
        }
    }
}

int main(){
    int i,j,k;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&b[i][j]);
        int tem=n;
        bool ok=1;
        for(k=0;k<31;k++){
            init();
            for(i=0;i<n;i++)
                for(j=i+1;j<n;j++){
                    if(i%2==1 && j%2==1){
                        if(b[i][j] & (1<<k)){
                            addedge(i,j+tem);
                            addedge(j,i+tem);
                        }
                        else{
                            addedge(i+tem,i);
                            addedge(j+tem,j);
                        }
                    }
                    else if(i%2==0 && j%2==0){
                        if(b[i][j] & (1<<k)){
                            addedge(i,i+tem);
                            addedge(j,j+tem);
                        }
                        else{
                            addedge(i+tem,j);
                            addedge(j+tem,i);
                        }
                    }
                    else{
                        if(b[i][j] & (1<<k)){
                            addedge(i,j+tem);
                            addedge(i+tem,j);
                            addedge(j,i+tem);
                            addedge(j+tem,i);
                        }
                        else{
                            addedge(i,j);
                            addedge(i+tem,j+tem);
                            addedge(j,i);
                            addedge(j+tem,i+tem);
                        }
                    }
                }
            for(i=0;i<tem*2;i++)
                if(!dfn[i])
                    tarjan(i);
            bool flag=1;
            for(i=0;i<tem;i++)
                if(belong[i]==belong[i+tem]){
                    flag=0;
                    break;
                }
            if(flag==0){
                ok=0;break;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
