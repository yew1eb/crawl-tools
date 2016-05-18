#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100010;
double a[maxn], sum[maxn];
int n, k;
int q[maxn], head, tail;

void DP()
{
    head = tail = 0;
    double ans = -1;
    for (int i = k; i <= n; ++i) {
        int j = i - k;
        /*维护下凸*/
        while (tail - head >= 2) {
            double x1 = j - q[tail-1];
            double y1 = sum[j] - sum[q[tail-1]];
            double x2 = q[tail-1] - q[tail-2];
            double y2 = sum[q[tail-1]] - sum[q[tail-2]];
            if (x1 * y2 - y1 * x2 >= 0) {
                tail--;
            } else {
                break;
            }
        }
        q[tail++] = j;
        /*寻找最优解并删除无用元素*/
        while (tail - head >= 2) {
            double x1 = i - q[head];
            double y1 = sum[i] - sum[q[head]];
            double x2 = i - q[head+1];
            double y2 = sum[i] - sum[q[head+1]];
            if (x1 * y2 - y1 * x2 >= 0) {
                head++;
            } else {
                break;
            }
        }
        double tmp = (sum[i] - sum[q[head]]) / (i - q[head]);
        ans = max(ans, tmp);
    }
    printf("%.2lf\n", ans);
}

/*读入优化，否则超时*/
inline int GetInt(){
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    int num = 0;
    while (ch >= '0' && ch <= '9'){
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}

int main()
{
    while (scanf("%d%d", &n, &k) != EOF) {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = GetInt();
            sum[i] = sum[i-1] + a[i];
        }
        DP(); 
    }
    return 0;
}