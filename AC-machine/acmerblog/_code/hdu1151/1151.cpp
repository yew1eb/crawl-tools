#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
int n,m;
int g[maxn][maxn];
int match[maxn];
bool vis[maxn];
bool dfs(int cur){

    for(int i=1;i<=n;i++){
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
    for(int i=1;i<=n;i++)  match[i]=-1;
    int res=0;
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i))
        res++;
    }
    return res;
}
int main(){
    int t,x,y;
    scanf("%d",&t);
    while(t--){
        memset(g,0,sizeof(g));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
           scanf("%d%d",&x,&y);
           g[x][y]=1;
        }
        printf("%d\n",n-hungary());
    }
    return 0;

}