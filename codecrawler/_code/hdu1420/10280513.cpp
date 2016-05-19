#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long LL;
LL pow(LL a, LL b, LL c)
{
    LL ret = 1;
    for(; b; b>>=1) {
        if(b&1) ret = (ret * a) % c;
        a = (a * a) % c;
    }
    return ret;
}
int main()
{
    int t;
    LL a, b, c;
    scanf("%d",&t);
    while(t--) {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        printf("%I64d\n", pow(a,b,c));
    }
    return 0;
}
