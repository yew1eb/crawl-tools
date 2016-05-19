#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
const int N = 100000;
int main()
{
    int K;
    while (scanf("%d", &K)==1) {
        if (K<=2)
        {
            if (K==1) puts("1\n1");
            if (K==2) puts("2\n1 1");
            continue;
        }
        bool f = 1;
        for (int x=0;f && x<=1e5;x++) {
            for (int y=0;x+y<=1e5&&x+y+x*y<=K&&y<=sqrt(K+0.5);y++)
            {
                int t = K - x - y - x * y;
                if (t % (x+y+1)==0) {
                    int z = t / (x + y + 1);
                    if (z < 0 || x+y+z>min(N, K)) continue;
                    assert(x+y+z+x*y+y*z+x*z==K);
                   
                    int n = x + y + z;
                    printf("%d\n", n);
                    for (int i=1;i<=n;i++) {
                        int c;
                        if (i<=x) c=1;
                        else {
                            if (i<=x+y) c = 2;
                            else c = 3;
                        }
                        printf("%d%c", c, i==n ? 10 : ' ' );
                    }
                    f =false;
                    break;
                }
            }
        }
        assert(!f);
    }
}