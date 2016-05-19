#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 11000
#define eps (1e-8)
#define INF 1000000000
#define abs(x) ((x) > 0? (x): -(x))
#define sqr(x) ((x) * (x))
#define two(x) (1 << (x))

typedef long long LL;

int n, sum[MAXN], num[MAXN], tn[MAXN];
priority_queue<int> heap;

void init()
{
    for (int i = 1; i * 2 <= n * (n - 1); ++i) scanf("%d", &sum[i]);
}

void work()
{
    for (num[1] = 1; num[1] * 2 <= sum[1]; ++num[1])
    {
        memset(tn, 0, sizeof(tn));
        while (!heap.empty()) heap.pop();
        for (int i = 1; i * 2 <= n * (n - 1); ++i) 
        {
            heap.push(-sum[i]);
            ++tn[sum[i]];
        }
        bool flag = true;
        for (int i = 2; i <= n && flag; ++i)
        {
            while (tn[-heap.top()] == 0) heap.pop();
            num[i] = -heap.top() - num[1];
            --tn[-heap.top()];
            heap.pop();
            for (int j = 2; j < i && flag; ++j)
            {
                int x = num[j] + num[i];
                if (x > 10000 || tn[x] == 0) flag = false;
                else --tn[x];
            }
        }
        if (flag)
        {
            for (int i = 1; i < n; ++i) printf("%d ", num[i]);
            printf("%d\n", num[n]);
            break;
        }
    }
}

int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        init();
        work();
    }
    return 0;
}
