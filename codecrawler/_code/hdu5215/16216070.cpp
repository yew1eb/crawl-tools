#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;
#define INF 0x2fffffff
#define LL long long
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
#pragma comment(linker, "/STACK:102400000,102400000") 
int n,m;
struct node{
    int from,to,next;
};
node es[600010];
int head[100005];
int cnt = 0;
void add(int from,int to){
    es[cnt].from = from,es[cnt].to = to;
    es[cnt].next = head[from];
    head[from] = cnt++;
}
int color[100005];
int tag[100005];
int pre[100005];
int flag1,flag2;
void dfs(int u){
    for(int v = head[u]; v!=-1;v = es[v].next){
        node& g = es[v];
        if(g.to == pre[u]) continue;
        if(!color[g.to]){
            color[g.to] = 3 - color[g.from];
            pre[g.to] = g.from;
            dfs(g.to);
            if(flag1&&flag2){
                break;
            }
        }
        else{
            if(color[g.to] == color[g.from]){
                flag1 = 1;
                int q = g.from;
                while(pre[q] != g.to){
                    if(tag[q]) {
                        flag2 = 1;
                        break;;
                    } 
                    tag[q] = 1;
                    q = pre[q];
                    if(q == -1) break;
                }
            }
            else{
                flag2 = 1;
            }
        }
    }           

}
int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        cnt = 0;
        for(int i = 0;i < m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y),add(y,x);
        }
        memset(color,0,sizeof(color));
        memset(tag,0,sizeof(tag));
        memset(pre,-1,sizeof(pre));
        flag1 = 0;
        flag2 = 0;
        for(int i = 1;i <= n;i++){
            if(!color[i]){
                color[i] = 1;
                dfs(i);
                if(flag1 && flag2){
                    break;
                }
            }
        }
        if(flag1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        if(flag2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
