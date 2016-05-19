#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
int n,m,k;
int g[maxn][maxn];
int match[maxn];
bool vis[maxn];
bool dfs(int cur){
     for(int i=1;i<=m;i++){
         if(g[cur][i]==1&&!vis[i]){
             vis[i]=true;
             int t=match[i];
             if(t==-1||dfs(t)){
                match[i] = cur;
                return true;
             }
         }

     }
     return false;
}
int hungary(){
    for(int i=1;i<=m;i++)   match[i]=-1;
    int res=0;
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
          if(dfs(i))  res++;
    }
    return res;
}
int main(){
    int id,x,y,num;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++){
            scanf("%d",&num);
            for(int j=1;j<=num;j++){
                scanf("%d",&x);
                g[x][i]=1;
            }
        }
        printf("%d\n",hungary());
    }
    return 0;
}
