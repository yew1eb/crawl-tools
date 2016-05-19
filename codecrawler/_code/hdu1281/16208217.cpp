#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
int n,m,k;
int g[maxn][maxn];
int x[maxn],y[maxn];
int match[maxn];
bool vis[maxn];
bool dfs(int cur){
     for(int i=1;i<=m;i++){
         if(g[cur][i]&&!vis[i]){
            vis[i]=true;
            int t=match[i];
            if(t==-1||dfs(t)){
               match[i]=cur;
               return true;
            }
         }
     }
     return false;
}
int hungary(){
    for(int i=1;i<=m;i++) match[i]=-1;
    int res=0;
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i))
        res++;
    }
    return res;
}
int main(){
    int ca=1;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        memset(g,0,sizeof(g));
        for(int i=0;i<k;i++){
             scanf("%d%d",&x[i],&y[i]);
             g[x[i]][y[i]]=1;
        }

        int sum=hungary(),res=0;
        for(int i=0;i<k;i++){
            g[x[i]][y[i]]=0;
            int t=hungary();

            if(t<sum)
            res++;
            g[x[i]][y[i]]=1;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",ca++,res,sum);
    }
    return 0;

}
