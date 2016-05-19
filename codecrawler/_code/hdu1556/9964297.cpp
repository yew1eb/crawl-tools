#include <stdio.h>
#include <string.h>
#define MAXN  100000 + 5
int bit[MAXN];

int main()
{
    int n, i, a, b;
    while(scanf("%d",&n), n )
    {
        memset(bit, 0, sizeof bit );
        for(i=0; i<n; ++i) {
            scanf("%d%d",&a,&b);
            bit[a]++;
            bit[b+1]--;
        }
        int tot = 0;
        for(i=1; i<=n; ++i) {
            tot += bit[i];
            printf("%d%c",tot," \n"[i==n]);
        }
    }
    return 0;
}
