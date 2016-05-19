#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<math.h>
#include<queue>
using namespace std;
#define sf scanf
#define pf printf
#define INF 1<<29
#define clr(x) memset(x,0,sizeof(x))
#define Clr(x) memset(x,-1,sizeof(x));
#define maxn 505
int map[maxn][maxn];
int vis[maxn];
int link[maxn];
int k,n,m;
int dfs(int x){
    for(int i=1;i<=m;i++){//æ³¨æè¿éæ¯m
        if(!vis[i]&&map[x][i]){
            vis[i]=1;
            if(!link[i]||dfs(link[i])){
                link[i]=x;
                return true;
            }
        }
    }
    return false;
}
void init(){
    clr(map);
    clr(link);
}
int main(){
    int girl,boy,ans=0;
    while(EOF!=sf("%d%d%d",&k,&n,&m)&&k){
        init();
        for(int i=1;i<=k;i++){
            sf("%d%d",&girl,&boy);
            map[girl][boy]=1;
        }
        ans=0;
        for(int i=1;i<=n;i++){//æ³¨æè¿éæ¯n
            clr(vis);
            if(dfs(i)) ans++;
        }
        pf("%d\n",ans);
    }
    return 0;
}