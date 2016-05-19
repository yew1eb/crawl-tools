#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 100010
typedef long long LL;
int N, K, A[MAXD], q[MAXD];
void cin(int &x)
{
    char ch;
    while(ch = getchar(), ch < '0' || ch > '9');
    x = ch - '0';
    while(ch = getchar(), ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + ch - '0';    
}
void init()
{
    int i;
    A[0] = 0;
    for(i = 1; i <= N; i ++) cin(A[i]), A[i] += A[i - 1];    
}
void solve()
{
    int i, j, x, y, z, front, rear;
    double ans = 0;
    front = rear = 0;
    q[rear ++] = 0;
    for(i = K; i <= N; i ++)
    {
        while(front < rear - 1)
        {
            x = q[front], y = q[front + 1];
            if((LL)(A[i] - A[x]) * (i - y) > (LL)(A[i] - A[y]) * (i - x)) break;
            ++ front;
        }
        ans = std::max(ans, (double)(A[i] - A[q[front]]) / (i - q[front]));
        q[rear] = i - K + 1;
        while(front < rear - 1)
        {
            x = q[rear - 2], y = q[rear - 1], z = q[rear];
            if((LL)(A[z] - A[y]) * (y - x) > (LL)(A[y] - A[x]) * (z - y)) break;
            -- rear, q[rear] = q[rear + 1];
        }
        ++ rear;
    }
    printf("%.2f\n", ans);
}
int main()
{
    while(scanf("%d%d", &N, &K) == 2)
    {
        init();
        solve();
    }
    return 0;    
}