#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%I64d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;
const int maxn = 5e4+5;
const double INF = 1e20;
int n,k;
LL p[maxn],sum[maxn],sq[maxn];
int main() {
    int _;RD(_);while(_--){
        RD2(n,k);
        p[0] = sum[0] = sq[0] = 0;
        for(int i = 1;i <= n;++i)
            RD(p[i]);
        double ans = INF;
        k = n - k;
        if(k == 0 || k == 1){
            puts("0");
            continue;
        }
        sort(p+1,p+n+1);
        for(int i = 1;i <= n;++i)
            sum[i] = p[i] + sum[i-1],sq[i] = p[i]*p[i] + sq[i-1];
        for(int i = k;i <= n;++i)
            ans = min(ans,(double)(sq[i] - sq[i - k])*(double)k - (double)(sum[i] - sum[i-k])*(double)(sum[i] - sum[i-k]));
        printf("%.10lf\n",ans/(double)k);
    }
    return 0;
}
