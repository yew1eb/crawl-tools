#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 105
#define ss(x) (x)*(x)
#define INF 2000000000.0
struct tt {
    double x, y;
} a[N];

double map[N][N];
double d[N];
int used[N];
int n;


double prim() {
    int i, j, k;
    double  min, ans = 0.0;
    memset(used,0,sizeof(used));
    used[0]  = 1;
    for(i=0; i<n;  i++)
        d[i] = map[0][i];
    for(i=1; i<n; i++) {
        min = INF;
        for(j=0; j<n; j++)
            if(!used[j]&&min>d[j])
                min = d[k=j];
        if(min==INF) break;
        ans += min;
        used[k] = 1;
        for(j=0; j<n; j++)
            if(!used[j]&&d[j]>map[k][j])
                d[j] = map[k][j];
    }
    return ans;
}
double dist(int i, int j) {
    return (double)sqrt( ss(a[i].x-a[j].x) + ss(a[i].y-a[j].y));
}
int main() {
    int i, j;
    while(~scanf("%d",&n)) {
        for(i=0; i<n; i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(i=0; i<n; i++)
            for(j=i; j<n; j++)
                map[j][i] = map[i][j] = dist(i,j);
        printf("%.2lf\n", prim() );
    }
    return 0;
}



