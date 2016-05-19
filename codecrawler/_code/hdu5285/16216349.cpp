#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 111111
int T;
int vis[N];
int v[N];
int d[N];
vector<int>g[N];
int flag;
int n,m;
int cnt1,cnt2;
void dfs(int u,int val){
    d[u]=val;
    if(val==1) cnt1++;
    else cnt2++;
    //printf("%d %d\n",u,val);
    int k = g[u].size();
    for(int i=0;i<k;i++){
        int vv = g[u][i];
        if(!v[vv]){
            v[vv]=1;
            dfs(vv,val^1);
        }
        else{
            if(d[u]==d[vv]){
                flag = 0;
                return ;
            }
        }
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        memset(d,-1,sizeof(d));
        memset(vis,0,sizeof(vis));
        memset(v,0,sizeof(v));
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
            vis[x]=1;
            vis[y]=1;
        }
         if(n==1||n==0) {
            printf("Poor wyh\n");
            continue;
        }
        flag =1;
        int ans = 0;
         int ans1=0;
        int ans2=0;
        for(int i=1;i<=n;i++){
            if(vis[i]&&!v[i]){
                cnt1=0;
                cnt2=0;
                v[i]=1;
                dfs(i,1);
                ans1+=max(cnt1,cnt2);
                ans2+=min(cnt1,cnt2);

            }
            if(!vis[i]){
                ans++;
            }
        }

        // printf("----%d %d\n",ans1,ans2);

        if(flag){
            if(max(ans1,ans2)+ans==n){
                printf("%d 1\n",n-1);
            }
            else{
                printf("%d %d\n",max(ans1,ans2)+ans,min(ans1,ans2));
            }
        }
        else
            puts("Poor wyh");
    }
}