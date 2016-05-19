#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int map[121][121];
int link[121];
int vis[121];
int n,m;
int find(int k){
    for(int i=1;i<=n;i++)
        if(!vis[i]&&map[k][i]){
            vis[i]=1;
            if(link[i]==-1||find(link[i])){
                link[i]=k;
                return 1;
            }
        }
        return 0;
}
int hug(){//æå¤§å¹éæ°
    int ans=0;    
    memset(vis,0,sizeof(vis));
    memset(link,-1,sizeof(link));
    for(int i=1;i<=n;i++){
        if(find(i))
            ans++;
    }
    return ans;
}
int main(){
    int u,v,t,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            map[u][v]=1;
        }
        ans=n-hug();
        printf("%d\n",ans);
    }
    return 0;
}
