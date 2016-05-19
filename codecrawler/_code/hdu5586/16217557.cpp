#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n;
long long a[maxn], b[maxn], c[maxn], sum, k;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        k = sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = (a[i] * 1890 + 143) % 10007;
            c[i] = b[i] - a[i];
            sum += a[i];
        }
        long long u = 0;
        for (int i = 1; i <= n; i++)
        {
            if (u + c[i] > 0) u = u + c[i]; else u = 0;
            if (u > k) k = u;
        }
        printf("%I64d\n", sum + k);
    }
    return 0;
}