#include <cstdio>
#include <cstring>
const int MAXN = 1005;
int left[3][MAXN][MAXN], right[3][MAXN][MAXN], top[3][MAXN][MAXN];
char a[MAXN][MAXN];

inline int min(const int &x, const int &y)
{
    return x < y ? x : y;
}

inline int max(const int &x, const int &y)
{
    return x > y ? x : y;
}

int main()
{
    int t;
    int n, m;
    scanf("%d", &t);
    memset(a, 0, sizeof(a));
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%s", a[i]+1);
        }
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        memset(top, 0, sizeof(top));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(a[i][j] == 'B')
                {
                    top[0][i][j] = 0;
                    top[1][i][j] = top[1][i-1][j] + 1;
                    left[0][i][j] = 0;
                    left[1][i][j] = left[1][i][j-1] + 1;
                }
                else
                {
                    top[0][i][j] = top[0][i-1][j] + 1;
                    top[1][i][j] = 0;
                    left[0][i][j] = left[0][i][j-1] + 1;
                    left[1][i][j] = 0;
                }
                if(a[i][j] == a[i-1][j])
                {
                    top[2][i][j] = 1;
                }
                else
                {
                    top[2][i][j] = top[2][i-1][j] + 1;
                }
                if(a[i][j] == a[i][j-1])
                {
                    left[2][i][j] = 1;
                }
                else
                {
                    left[2][i][j] = left[2][i][j-1] + 1;
                }
            }
            for(int j=m;j>=1;--j)
            {
                if(a[i][j] == 'B')
                {
                    right[0][i][j] = 0;
                    right[1][i][j] = right[1][i][j+1] + 1;
                }
                else
                {
                    right[0][i][j] = right[0][i][j+1] + 1;
                    right[1][i][j] = 0;
                }
                if(a[i][j] == a[i][j+1])
                {
                    right[2][i][j] = 1;
                }
                else
                {
                    right[2][i][j] = right[2][i][j+1] + 1;
                }
            }
        }
        int ans = 4;
        int maxLeft[3], maxRight[3];
        for(int j=1;j<=m;++j)
        {
            for(int i=1;i<=n;++i)
            {
                for(int k=0;k<3;++k)
                {
                    if(top[k][i][j] == 1)
                    {
                        maxLeft[k] = left[k][i][j];
                        maxRight[k] = right[k][i][j];
                    }
                    else
                    {
                        maxLeft[k] = min(maxLeft[k], left[k][i][j]);
                        maxRight[k] = min(maxRight[k], right[k][i][j]);
                    }
                    ans = max(ans, (maxRight[k] + maxLeft[k] - 1) * 2 + top[k][i][j] * 2);
                }
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}