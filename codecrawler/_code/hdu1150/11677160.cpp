#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
int n,m,k;
int g[maxn][maxn];
int match[maxn];
bool vis[maxn];
bool dfs(int cur){
     for(int i=1;i<m;i++){
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
    for(int i=1;i<m;i++)   match[i]=-1;
    int res=0;
    for(int i=1;i<n;i++){
        memset(vis,false,sizeof(vis));
          if(dfs(i))  res++;
    }
    return res;
}
int main(){
    int id,x,y;
    while(scanf("%d",&n)!=EOF,n){
        scanf("%d%d",&m,&k);
        memset(g,0,sizeof(g));
        for(int i=0;i<k;i++){
            scanf("%d%d%d",&id,&x,&y);
            if(x&&y)
            g[x][y]=1;
        }
        printf("%d\n",hungary());
    }
    return 0;
}
