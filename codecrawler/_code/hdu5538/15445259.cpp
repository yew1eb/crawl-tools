#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 100;
int mtx[maxn][maxn];
int n, m, T;

int main()
{
#ifdef LOCAL
    freopen("in.h","r", stdin);
    freopen("out.h", "w", stdout);
#endif // LOCAL
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        memset(mtx, 0, sizeof mtx );
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
            scanf("%d", &mtx[i][j]);
        int ans = 0;
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
            if(mtx[i][j] > 0) ans++;
            if(mtx[i][j] > mtx[i+1][j]) ans += mtx[i][j] - mtx[i+1][j];
            if(mtx[i][j] > mtx[i-1][j]) ans += mtx[i][j] - mtx[i-1][j];
            if(mtx[i][j] > mtx[i][j+1]) ans += mtx[i][j] - mtx[i][j+1];
            if(mtx[i][j] > mtx[i][j-1]) ans += mtx[i][j] - mtx[i][j-1];
        }
        printf("%d\n", ans);
    }
    return 0;
}
