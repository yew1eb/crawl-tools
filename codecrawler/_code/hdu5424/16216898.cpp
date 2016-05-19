#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int ma[1005][1005];
int vis[1005];
int n;
int d[1005];
#define INF 1000000
int bfs(int u){
    memset(vis,0,sizeof(vis));
    queue<int> que;
    que.push(u);
    vis[u] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = 1;i <= n;i++){
            if(!vis[i] && ma[u][i] == 1){
                que.push(i);
                vis[i] = 1;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
             return 0;
        }
    }
    return 1;
}
int dfs(int u,int st){
    vis[u] = 1;
    if(st == n) return 1;
    for(int i = 1;i <= n;i++){
        if(!vis[i] && ma[u][i] == 1){
            if(dfs(i,st+1)){
                return 1;
            }
            else{
                vis[i] = 0;
            }
        }
    }
    return 0;
}
int main(){
    while(cin >> n){
        memset(ma,0,sizeof(ma));
        memset(d,0,sizeof(d));
        for(int i =  0;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x != y){
                if(!ma[x][y]){
                    ma[x][y] = 1;
                    ma[y][x] = 1;
                    d[x]++;
                    d[y]++;
                }

            }
        }
        if(!bfs(1)){
            printf("NO\n");
        }
        else{
            memset(vis,0,sizeof(vis));
            int ma = INF;
            int k = 0;
            for(int i  =1;i <= n;i++){
                if(d[i] < ma){
                    ma = d[i];
                    k = i;
                }
            }
            if(dfs(k,1)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}