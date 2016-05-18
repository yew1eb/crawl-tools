#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long d[66] = {0,1,3};
long long a[66];
int main()
{
    int i, j, n;
    d[64] = 18433;
    for (i=1; i<=63; i++)
        a[i] = (1LL<<i)-1;
    for (i=2; i<=63; i++)
    {
        d[i] = 2*d[1]+a[i-1];
        for (j=2; j<i; j++)
            d[i] = min(d[i],2*d[j]+a[i-j]);
    }
    while (scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",d[n]);
    }
    return 0;
}