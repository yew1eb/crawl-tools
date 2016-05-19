#include <string.h>   
#include <cstdio>
#include <vector>   
#define N 1010
#define inf 10000000
using namespace std;
inline int Min(int a,int b){return a>b?b:a;}
vector<int>G[N];
int dis[N][N],bian[N][N];
int n,m,f[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void Union(int u,int v){
    int fa=find(u),fb=find(v);
    f[fa]=fb;
}

struct node{
    int u,v,d;
}edge[N];//å²è¾¹ä¸ä¼è¶è¿næ¡
int edgenum;
void PUT(int u,int v,int d){
    node E={u,v,d};
    edge[edgenum++]=E;
}
int pre[N],low[N],dfs_clock;
bool su;
int dfs(int u,int fa){//æ¯è¿éå¾,dfs(u, )ç®çæ¯å¯»æ¾uçåä»£æè½è¿åçï¼ææ©çç¥åï¼çpreå¼
    if(su)return 0;
    int lowu=pre[u]= ++ dfs_clock;
    int child=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!pre[v])
        {
            child++;
            int lowv=dfs(v,u);
            lowu = Min(lowu, lowv);
            if(lowv > pre[u]&&bian[u][v]==1){PUT(u,v,dis[u][v]);if(dis[u][v]<=1)return 0;}
        }
        else if(pre[v] < pre[u] && v!=fa)
            lowu = Min(lowu, pre[v]);
    }
    return low[u]=lowu;
}
void findcut(){
    memset(pre,0,sizeof(pre));
    dfs_clock=0;
    dfs(1,-1);//dfs(æ æ ¹ï¼æ æ ¹çç¶äº²æ¯-1) 
}
int main(){
    int i,u,v,d;
    while(scanf("%d %d",&n,&m),n)
    {
        memset(bian,0,sizeof(bian));
        for(i=1;i<=n;i++)
        {
            G[i].clear();
            f[i]=i;
            for(int j=1;j<=n;j++)
                dis[i][j]=inf;
        }

        while(m--)
        {
            scanf("%d %d %d",&u,&v,&d);
            if(dis[u][v]==inf)
            {
            G[u].push_back(v);       G[v].push_back(u);
            Union(u,v);
            }
            dis[u][v]=dis[v][u]=Min(dis[u][v],d);
            bian[u][v]++;            bian[v][u]++;
        }
     
        bool fa=false;    find(1);
        for(i=1;i<=n;i++)if(find(i)!=f[1]){fa=true;break;}
        if(fa){printf("0\n");continue;}

        su=false;
        edgenum=0;
        findcut();

        if(edgenum)
        {
            int ans=inf;
            for(i=0;i<edgenum;i++)ans=Min(ans,edge[i].d);
            if(ans==inf)ans=-1;
            else if(ans==0)ans=1;
            printf("%d\n",ans);
        }
        else printf("-1\n");
    }
    return 0;
}
/* 
3 3 
1 2 7 
2 3 4 
3 1 4 
 
3 2 
1 2 7 
2 3 4 
 
3 4 
1 2 7 
2 1 7 
2 3 4 
3 2 4 
 
4 3 
1 2 1  
1 2 3 
3 4 4 
 
4 4 
1 2 1  
1 2 3 
3 4 4 
2 4 6 
 
4 5 
1 2 1  
1 2 3 
3 4 4 
2 4 6 
1 3 0 
 
4 5 
4 3 0 
3 4 4 
2 4 6 
2 3 0 
1 3 0 
 
2 1 
1 2 0 
 
4 2 
1 2 3 
1 3 5 
 
4 5 
1 2 3 
2 3 4 
1 3 5 
4 3 7 
4 3 6 
 
4 4 
1 2 3 
2 3 4 
1 3 5 
4 3 6 
 
4 4 
1 2 4 
1 3 5 
4 3 6 
3 4 7 
 
6 7 
1 2 1 
1 3 2 
2 3 3 
3 4 4 
4 6 5 
4 5 6 
5 6 7 
 
5 6 
1 2 3 
1 3 4 
2 3 5 
3 4 7 
3 5 8 
5 4 9 
 
8 9 
1 8 1 
5 1 2 
1 7 3 
1 4 4 
1 2 5 
4 3 6 
3 2 7 
5 6 8 
6 7 9 
 
6 6 
1 4 1 
1 2 4 
2 5 4 
5 6 4 
3 6 4 
4 3 2 
 
6 5 
1 2 4 
2 5 4 
5 6 4 
3 6 4 
4 3 2 
 
8 10 
1 8 1 
5 1 2 
1 7 3 
1 4 4 
1 2 5 
4 3 6 
3 2 7 
5 6 8 
6 7 9 
8 1 2 
 
3 3 
1 2 7 
1 3 1 
1 3 4 
 
0 0 
*/ 