#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 150005;
int n, W, H, a[maxn], f[maxn][2];
long long sum, ans;

int main()
{
    while (~scanf("%d%d%d", &n, &W, &H))
    {
        f[0][0] = f[0][1] = sum = 0;
        for (int i = 1; i <= W + n + W; i++)
        {
            if (W < i && i <= n + W) scanf("%d", &a[i]); else a[i] = 0;
            sum += a[i];
            f[i][0] = f[i - 1][0];        f[i][1] = f[i - 1][1];
            if (a[i] < H) f[i][0] +=H - a[i]; else f[i][1]+= a[i] - H;
        }
        if ((long long)W*H > sum) printf("-1\n");
        else
        {
            ans = 0x7FFFFFFF;
            for (int i = W; i <= n + W + W; i++)
                ans = min(ans, (long long)max(f[i][0] - f[i - W][0], f[i][1] - f[i - W][1]));
            cout << ans << endl;
        }
    }
}