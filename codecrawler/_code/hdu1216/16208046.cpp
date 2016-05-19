#include <cstdio>
#include <cstring>
#define MAXN 35010 
using namespace std;

int ans[3100];
bool vis[MAXN];

void init() {

    memset(vis, false, sizeof(vis));

    int cnt = 1;
    for(int i=1; i<=MAXN; ++i) {
        int tmp = i+1;
        if(!vis[tmp]) {
            ans[cnt++] = tmp;
            int idx = 0;
            for(int j=tmp+1; j<=MAXN; ++j) {
                if(!vis[j]){
                    ++idx;
                    if(idx == tmp) {
                        vis[j] = true;
                        idx = 0;
                    }
                }
            }
        }
    }
}
int main(void) {

    int n;
    init();
    /*çº¯æè¡¨åå®¹
    FILE * fp = fopen("out.txt", "w");
    fprintf(fp, "{ ");
    for(int i=1; i<=3050; ++i)
        fprintf(fp, "%d, ", ans[i]);
    fprintf(fp, " }");
    */
    while(scanf("%d", &n), n)
        printf("%d\n", ans[n]);
    return 0;
}