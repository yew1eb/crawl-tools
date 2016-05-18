#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111;
int f[N], point[N] , pre[N], go[N][N];
void putans(int u) {
    if(u == -1) return;
    putans(pre[u]);
    printf("%d->",u);
}
int main() {
    int T , n , cas = 1;
    scanf("%d",&T);
    while(T--) {
        if(cas > 1) puts("");
        printf("CASE %d#\n",cas++);
        scanf("%d",&n);
        n += 1;
        for(int i=1;i<n;i++) scanf("%d",&point[i]);
        point[n] = 0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
            go[i][j] = 0;
        }
        for(int i=1;i<=n;i++) f[i] = 0 , pre[i] = -1;
        int m;
        scanf("%d",&m);
        while(m--) {
            int u , v;
            scanf("%d%d",&u,&v);
            go[u][v] = 1;
        }
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(go[i][j] && f[i]+point[i] > f[j]) {
                f[j] = f[i] + point[i];
                pre[j] = i;
            }
        }
        printf("points : %d\n",f[n]);
        printf("circuit : 1->");
        putans(pre[n]);
        printf("1\n");
    }
    return 0;
}