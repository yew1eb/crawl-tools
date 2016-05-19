#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 205
bool vis[N];
int a[N];
int n, s, e;
int flag, ans;
struct node {
    int x, step;
};
void bfs() {
    queue<node> q;
    node now, tmp;
    now.x =s;
    now.step = 0;
    q.push(now);
    vis[s]=true;
    while(!q.empty()) {
        now = q.front();
        q.pop();
        vis[now.x]= true;
        if(now.x==e) {
            flag = 1;
            ans = now.step;
            return ;
        }
        tmp = now;
        tmp.x = now.x -a[now.x];
        tmp.step = now.step+1;
        if(tmp.x>0&&!vis[tmp.x]) q.push(tmp);

        tmp = now;
        tmp.x = now.x + a[now.x];
        tmp.step = now.step + 1;
        if(tmp.x<=n&&!vis[tmp.x]) q.push(tmp);
    }
}
int main() {
    int i;
    while(~scanf("%d",&n),n) {
        scanf("%d%d",&s,&e);
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        ans = 0;
        flag = 0;
        memset(vis,false,sizeof(vis));
        bfs();
        if(flag) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
