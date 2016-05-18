/* Created Time: Saturday, November 09, 2013 PM10:39:09 CST */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1010;
double x[N],y[N],d[N];
int main() {
    int cas,n;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for (int i = 0; i < n; i ++)
            scanf("%lf%lf",&x[i],&y[i]);
        sort(y,y+n);
        sort(x,x+n);
        int tot = 0;
        for (int i = 2; i < n; i ++)
            d[tot++] = x[i]-x[i-2];
        d[tot++] = x[1]-x[0];
        d[tot++] = x[n-1]-x[n-2];
        sort(d,d+n);
        double ans = 0;
        for (int i = 0; i < n; i ++)
            ans += y[i]*d[i];
        printf("%.1f\n",ans/2);
    }
    return 0;
}