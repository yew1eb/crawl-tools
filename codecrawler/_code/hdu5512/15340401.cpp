#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int n, a, b;
    for(int cas=1; cas<=T; ++cas) {
        scanf("%d%d%d", &n, &a, &b);
        int x = __gcd(a, b);
        printf("Case #%d: ", cas);
        int k =(n/x)&1;
        puts(k?"Yuwgna":"Iaka");
    }
    return 0;
}
