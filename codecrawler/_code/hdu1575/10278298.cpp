#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int LL;
const int N = 10;
const int mod = 9973;
int n, k;
struct mtx
{
    LL x[N+1][N+1];
    mtx()
    {
        memset(x, 0, sizeof x );
    }
};
mtx operator *(const mtx &a, const mtx &b)
{
    mtx c;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            for(int k=0; k<n; ++k)
                c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % mod;
        }
    }
    return c;
}

mtx operator ^(mtx a, int b)
{
    mtx ret;
    for(int i=0; i<n; ++i)ret.x[i][i] = 1;
    for(; b; b>>=1)
    {
        if(b&1) ret = ret * a;
        a = a * a;
    }
    return ret;
}

int main()
{
    int t;
    mtx A;
    int i, j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
             scanf("%d",&A.x[i][j]);

        A = A ^ k;
        int ans = 0;
        for(i=0; i<n; ++i)
            ans += A.x[i][i];
        printf("%d\n",ans % mod);
    }
    return 0;
}


















