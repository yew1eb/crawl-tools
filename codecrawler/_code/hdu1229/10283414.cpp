#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, k, i;
    while(scanf("%d%d%d",&a,&b,&k))
    {
        if(a==0 && b==0) break;
        c = a + b;
        bool flag = true;
        for(i=1; i<=k; ++i)
        {
            if(a % 10 != b % 10) {
                flag = false; break;
            }
            a /= 10;
            b /= 10;
        }
        if(!flag) printf("%d\n",c);
        else printf("-1\n");
    }
    return 0;
}
