#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
int g[maxn][maxn];
int match[maxn];
bool vis[maxn];
int mid,n,x;
bool dfs(int cur){
     for(int i=1;i<=n;i++){
         if((!vis[i])&&(g[cur][i]<=x+mid)&&(g[cur][i]>=x)){
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
bool hungary(){
     for(int i=1;i<=n;i++)  match[i]=-1;
     for(int i=1;i<=n;i++) {
         memset(vis,false,sizeof(vis));
         if(!dfs(i)) return false;
     }
     return true;
}
int main(){
    int t,l,r; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        l=100; r=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
             scanf("%d",&g[i][j]);
             if(g[i][j]>r) r=g[i][j];
             if(g[i][j]<l) l=g[i][j];
        }
        int  max=r-l,min=0;

        while(1){
            mid = (min+max)/2;
            bool can=false;
            for(x=l;x+mid<=r;x++){
                if(hungary()){
                   can=true;
                   break;
                }
            }
            if(can)  max=mid;
            if(min+2>=max) break;
            if(!can)  min=mid;

        }

        printf("%d\n",max);
    }
    return 0;
}

