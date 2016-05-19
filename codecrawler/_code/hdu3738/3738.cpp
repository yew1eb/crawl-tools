#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 100010
int n;
__int64  a[N], x, y, z;
int q[N], ed;
__int64 min(__int64 a,__int64 b )
{
 return a<b?a:b;   
}
void solve() {
    __int64 res = a[0] * x + a[n - 1] * y;
    for (int i = 0; i < n; ++i) {
        res += a[i] * z;
        if(i) {
            if (a[i - 1] > a[i])
                res += (a[i - 1] - a[i]) * y;
            else
                res += (a[i] - a[i - 1]) * x;
        }
    }
    ed = 0;
    q[ed++] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[q[ed - 1]] >= a[i]) q[ed++] = i;
        else {
            while (ed > 1 && a[q[ed - 1]] < a[i]) {
                --ed;
               /* t是解雇工人的数目 ，
                  tmp---是留着这个工人省钱还是解雇这个工人省的钱 ？？ 
               */
                __int64 tmp, t = min(a[i], a[q[ed - 1]]) - a[q[ed]];

                if ((tmp = (x + y - (i - q[ed - 1] - 1) * z) * t) > 0) {

                    res -= tmp;
                     //printf("\n........\nq[ed]=%d l=%d r=%d tmp=%d\n",q[ed],q[ed - 1],i,tmp);
                }
            }
            if (a[q[ed - 1]] <= a[i]) --ed;
            q[ed++] = i;

        }
    }
    printf("%I64d\n", res);
}
int main() {
    freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
    int cas;
    scanf("%d", &cas);
    while (cas--) {
    scanf("%d", &n);
    scanf("%I64d%I64d%I64d", &x, &y, &z);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
        solve();
    }
    return 0;
}