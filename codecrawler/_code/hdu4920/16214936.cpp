#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 805;
int a[N][N], b[N][N], ans[N][N];
void  Multi(int n)
{
    int  i, j, k, L, *p2;
    int  tmp[N], con;
    for(i = 0; i < n; ++i)
    {
        memset(tmp, 0, sizeof(tmp));
        for(k = 0, L = (n & ~15); k < L; ++k)
        {
            con = a[i][k];
            for(j = 0, p2 = b[k]; j < n; ++j, ++p2)
                tmp[j] += con * (*p2);
            if((k & 15) == 15)
            {
                for(j = 0; j < n; ++j) tmp[j] %= 3;
            }
        }

        for( ; k < n; ++k)
        {
            con = a[i][k];
            for(j = 0, p2 = b[k]; j < n; ++j, ++p2)
                tmp[j] += con * (*p2);
        }
        for(j = 0; j < n; ++j)
            ans[i][j] = tmp[j] % 3;
    }
}
int main()
{
    int n, i, j, k;
    while(~scanf("%d",&n))
    {
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j] %= 3;
            }
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%d",&b[i][j]);
                b[i][j] %= 3;
            }
        Multi(n);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n-1; j++)
                printf("%d ", ans[i][j]);
            printf("%d\n", ans[i][n-1]);
        }
    }
    return 0;
}