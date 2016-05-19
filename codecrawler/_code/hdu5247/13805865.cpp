#include <bits/stdc++.h>
using namespace std;

int a[10005], ans[1005], mark[2005];

int main()
{
    int n, m, k;
    int cas = 1;
    while(~scanf("%d%d", &n, &m))
    {
        memset(ans, 0, sizeof ans );
        for(int i=0; i<n; ++i)
        {
            scanf("%d", a + i);
            int ma, mi;
            ma = mi = 1000;
            memset(mark, 0, sizeof mark );
            for(int j=0; j<=i && j<1000; ++j) {
                k = a[i-j] - a[i] + 1000;
                if(k<0 || k >2000 || mark[k]) break;
                mark[k] = 1;    
                if(ma < k) ma = k;
                if(mi > k) mi = k;
                if(ma - mi == j) ans[j+1]++;
            }
        }

        printf("Case #%d:\n", cas++);
        while(m--){
            scanf("%d", &k);
            printf("%d\n", ans[k]);
        }
    }
    return 0;
}
