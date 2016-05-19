#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int mod = 1000000007;
const int MAXN = 1000000;
long long f[MAXN + 10];
long long po(long long n,long long m)
{
    long long ans = 1;
    while(m)
    {
        if(m & 1) ans = ans * n % mod;
        m = m >> 1;
        n = n * n % mod;
    }
    return ans;
}
int main()
{
//    freopen("in.txt","r",stdin);
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        f[i] = ((f[i - 1] * (4 * i - 2) % mod) * po(i + 1 ,mod - 2)) % mod;
    }
    int t;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d:\n",i);
        printf("%I64d\n",f[n]);
    }
    return 0;
}
