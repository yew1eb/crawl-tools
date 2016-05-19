#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define clr(x)memset(x,0,sizeof(x))
const int maxn = 1001;
__int64 c[maxn][maxn],d[maxn],s[maxn][maxn];

void cc(__int64 m)
{
    int i,j;
    for (i=1; i<=m; i++)
    {
        c[i][0] = 1;
        for (j=1; j<i; j++)
            c[i][j] = c[i-1][j-1]+c[i-1][j];
        c[i][i] = 1;
    }
}
int main()
{
    int n, m;
    int i, j, k;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        cc(m);
        for (i=0; i<n; i++)
        {
            scanf("%d",&s[i][0]);
            for (j=1; j<=s[i][0]; j++)
                scanf("%d",&s[i][j]);
        }
        clr(d);
        for (i=1; i<=s[0][0]; i++)
        {
            if (s[0][i] > m)
                continue;
            d[s[0][i]] = c[m][s[0][i]];
        }
        for (i=1; i<n; i++)
        {
            if (!s[i][0])
                continue;
            for (j=m; j>=0 ; j--)
            {
                if (d[j])
                    for (k=1; k<=s[i][0] && j+s[i][k]<=m; k++)
                    {
                        if (s[i][k] > 0)
                            d[s[i][k]+j] += d[j]*c[m-j][s[i][k]];
                    }
            }
        }
        printf("%I64d\n",d[m]);
    }
    return 0;
}