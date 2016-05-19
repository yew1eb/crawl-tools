#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

__int64 gcd(__int64 a, __int64 b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

__int64 fac[100010];

int main()
{
    int t;
    __int64 a, b, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        __int64 x = gcd(a, b);
        if(x == 1 && c > 1)
        {
            printf("-1\n");
            continue;
        }
        else if(c == 1)
        {
            printf("%I64d\n", x);
            continue;
        }
        else
        {
            __int64 sum = 1;
            __int64 cnt = 0;
            __int64 temp = sqrt((double)x + 1.0);
            for(__int64 i = 1; i <= temp; i++)
            {
                    if(x % i == 0)
                    {
                        fac[cnt++] = i;
                        fac[cnt++] = x / i;
                    }
            }
            sort(fac,fac + cnt);
            if(cnt < c)
            {
                printf("-1\n");
                continue;
            }
            printf("%I64d\n", fac[cnt - c]);
        }
    }
    return 0;
}