#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50005;
const int M = 5;
//Nä»£è¡¨è¿ç¨æ°ï¼Mä»£è¡¨èµæº
int all[N][M] ,req[N][M] ,res[M];
int vis[N];

int n,m;
bool judge(int i) {
    for(int j = 0; j < m; j++) {
        if(req[i][j] > res[j]) {
            return false;
        }
    }
    return true;
}
int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d",&all[j][i]);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d",&req[j][i]);
            }
        }
        for(int i = 0; i < m; i++) {
            scanf("%d",&res[i]);
        }
        int sum = 0 ,cnt;
        memset(vis,0,sizeof(vis));
        while(true) {
            cnt = 0;
            for(int i = n-1; i >= 0; i--) {
                if(!vis[i] && judge(i)) {
                    vis[i] = true;
                    for(int j = 0; j < m; j++) {
                        res[j] += all[i][j];
                    }
                    cnt++;
                }
            }
            sum += cnt;
            if(sum == n || cnt == 0) {
                break;
            }
        }
        if(sum == n) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}