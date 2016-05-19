#include <stdio.h>
#include <string.h>
#define N 1000
int f[N+1];
int volume[N], value[N];
int n, v;
int main() {
    int T, i, j;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&v);
        for(i=0; i<n; i++) scanf("%d",&value[i]);
        for(i=0; i<n; i++) scanf("%d",&volume[i]);
        memset(f,0,sizeof(f));
        for(i=0; i<n; i++)
            for(j=v; j>=volume[i]; j--) {
                if(f[j] <f[ j-volume[i] ] + value[i])
                    f[j] = f[ j-volume[i] ] + value[i];
            }
        printf("%d\n",f[v]);
    }
    return 0;
}
