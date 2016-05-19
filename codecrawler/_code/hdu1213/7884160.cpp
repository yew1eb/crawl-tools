#include <stdio.h>
#define M 1001
int p[M];
int find(int x){return p[x] == x ? x : p[x]=find(p[x]); }

int main()
{
    int T, n, m, i, x, y, count;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d", &n, &m);
        for (i=1; i<=n; i++)p[i] = i;
        for (i=1; i<=m; i++){
            scanf("%d%d", &x, &y);
            x = find(x);y = find(y);
            if(x == y) continue;
            p[x] = y;
        }
        count = 0;
        for (i=1; i<=n; i++){
            x = find(i);
            if(x == i)
                count++;    
        }      
        printf("%d\n",count);
    }
    return 0;
}