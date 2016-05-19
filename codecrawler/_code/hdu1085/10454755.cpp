#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int f[8000 + 10], g[8000 + 10];
    int i, j, n1, n2, n5;
    while(scanf("%d%d%d",&n1, &n2, &n5), n1 + n2 + n5)
    {
        memset(f, 0, sizeof f );
        memset(g, 0, sizeof g );
        for(i=0; i<=n1; ++i)
        {
            f[i] = 1;
            for(j=0; j<=n2; ++j)
                g[i + j*2] = f[i];
        }

        for(i=0; i<=n1 + n2*2; ++i)
        {
            f[i] = g[i];
            g[i] = 0;
        }

        for(i=0; i<=n1 + n2*2; ++i)
        {
            for(j=0; j<=n5; ++j)
                g[i + j*5] = f[i];
        }
        for(i=0; ; ++i)
                if(!g[i])
                    break;
        printf("%d\n",i);
    }
    return 0;
}
