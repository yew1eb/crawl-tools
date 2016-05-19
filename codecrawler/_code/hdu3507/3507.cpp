#include <stdio.h>
#include <string.h>
#define MAX 510000
#define int64 long long


struct point{

    int64 x,y,c;
}pot[MAX];
int n,m,arr[MAX];
int64 sum[MAX],dp[MAX];
int qu[MAX],head,tail;


int CheckIt(int x,int y,int z) {

    point p0 = pot[x],p1 = pot[y],p2 = pot[z];
    return (p0.x -p1.x) * (p0.y - p2.y) - (p0.y - p1.y) * (p0.x - p2.x) <= 0;
}
int NotBest(int x,int y,int k) {

    point p0 = pot[x],p1 = pot[y];
    return p0.y - k * p0.x > p1.y - k * p1.x;
}
int64 Solve_DP() {

    head = tail = 0;
    qu[tail] = 0;
    pot[0].x = pot[0].y = 0;


    for (int i = 1; i <= n; ++i) {

        pot[i].x = sum[i-1];
        pot[i].y = dp[i-1] + sum[i-1] * sum[i-1];
        while (head <= tail - 1 &&
                CheckIt(qu[tail-1],qu[tail],i)) tail--;


        qu[++tail] = i;
        while (head + 1 <= tail &&
                NotBest(qu[head],qu[head+1],2 * sum[i])) head++;
        int k = qu[head];
        dp[i] = pot[k].y - 2 * sum[i] * pot[k].x + sum[i] * sum[i] + m;
    }


    return dp[n];
}
int64 Solve_DP2() {

    for (int64 mmin,i = 1; i <= n; ++i) {

        mmin = -1;
        for (int j = qu[i-1]; j < i; ++j)
            if (mmin == -1 ||
                    dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) < mmin) {

                mmin = dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]);
                qu[i] = j;
            }


        dp[i] = mmin + m;
    }
    return dp[n];
}


int main()
{
    int i,j,k;


    while (scanf("%d%d",&n,&m) != EOF) {

        for (i = 1; i <= n; ++i)
            scanf("%d",&arr[i]),sum[i] = arr[i] + sum[i-1];


        int64 ans = Solve_DP2();
        printf("%lld\n",ans);
    }
}