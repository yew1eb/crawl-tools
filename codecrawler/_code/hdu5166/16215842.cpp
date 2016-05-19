#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[1005];

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        int m = n + 2, a, b, flag = 1;
        while(n--) {
            scanf("%d", &a);
            vis[a] = 1;
        }
        for(int i=1; i<=m; i++) {
            if(!vis[i] && flag == 1) {
                a = i; flag = 2;
            }
            else if(!vis[i] && flag == 2) {
                b = i; break;
            }   
        }
        printf("%d %d\n", a, b);
    }
    return 0;
} 