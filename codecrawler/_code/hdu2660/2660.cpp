#include <stdio.h>
#include <string.h>
struct node {
    int v,w;

} a[21];
#define INF 0xfffffff
int f[1005][21];
int n, k,w;
void dp() {
    int i,j, p;
    int max;
    memset(f,0,sizeof(f));
    for(i=0; i<n; i++) {
        for(j=w; j>=a[i].w; j--) {
            for(p=1; p<=k; p++) {
                max = f[j][p];
                if(max<f[j-a[i].w][p-1]+a[i].v) max = f[j-a[i].w][p-1]+a[i].v;
                f[j][p] = max;
            }
        }

    }
    max =-INF;
    for(i=0; i<w; i++) if(max<f[i][k]) max = f[i][k];
    printf("%d\n",max);
}
int main() {
    int T,i;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        for(i=0; i<n; i++) scanf("%d%d",&a[i].v,&a[i].w);
        scanf("%d",&w);
        dp();
    }
    return 0;
}