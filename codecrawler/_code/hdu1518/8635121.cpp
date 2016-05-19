#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#define N 21
using namespace std;
int ave, n;
bool flag;
bool vis[N];
int a[N];

void dfs( int sum, int k, int cnt) {
    if(flag) return;
    if(cnt==3) {
        flag = true;
        return;
    }
    for(int i=k+1; i<=n; i++)
        if(!vis[i]&&!flag&&sum+a[i]<=ave) {
            vis[i] = 1;
            if(sum+a[i]==ave) dfs(0,0,cnt+1);
            else if(sum+a[i]<ave) dfs(sum+a[i],i,cnt);
            vis[i] = 0;
            if(sum==0) break;
            while(a[i]==a[i+1]) i++;
        }
}

int main() {
    int T, i, s;
    scanf("%d",&T);
    while(T--) {
        s = 0;
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(i=1; i<=n; i++) {
            scanf("%d",a+i);
            s +=a[i];
        }
        sort(a+1,a+n+1,greater<int>());
        flag  = false;
        if(s%4==0) {
            ave = s/4;
            dfs(0,0,0);
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
