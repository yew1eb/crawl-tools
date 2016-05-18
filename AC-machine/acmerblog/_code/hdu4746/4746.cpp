#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define M 500005
#define N 19

//返回n中有多少个x因子
int cal(int n, int x)
{
    int res = 0;
    do
    {
        ++res;
        n /= x;
    }
    while (n % x == 0);
    return res;
}

//备注：分块加速求解需要求前缀和
//F[i][j]: 表示素因子个数<=j条件下的莫比乌斯前缀和：μ(1)+μ(2)+...+μ(i)
int F[M][N];
int num[M];		//num[i]: i中含有多少个素因子
int h[M];		//h[i]: -1表示存在平方因子，否则表示有多少种素因子

//莫比乌斯函数的定义
int mob(int n)
{
    if (h[n] == -1) return 0;	//存在平方因子时，μ(n)=0
    if (h[n] & 1) return -1;	//奇数个不同素数之积，μ(n)=-1
    return 1;					//偶数个不同素数之积，μ(n)=1
}

int main()
{
    int t, n, m, p, i, j;
    //筛法算出num[]以及h[]
    for (i = 2; i < M; i++)
    {
        if (num[i]) continue;
        for (j = i; j < M; j+=i)
        {
            int tp = cal(j, i);
            num[j] += tp;
            if (tp > 1)  	//j中含有多个i，必然存在平方因子
            {
                h[j] = -1;
            }
            else if (h[j] >= 0)
            {
                ++h[j];
            }
        }
    }
    //枚举i作为公因子，对B(j)的贡献值为：mob(j/i)
    for (i = 1; i < M; i++)
    {
        for (j = i; j < M; j+=i)
        {
            F[j][num[i]] += mob(j/i);
        }
    }
    //为了表示素因子数<=j的意义，求j的前缀和
    for (i = 1; i < M; i++)
    {
        for (j = 1; j < N; j++)
        {
            F[i][j] += F[i][j-1];
        }
    }
    //为了分组加速求解，求i的前缀和
    for (i = 1; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            F[i][j] += F[i-1][j];
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &p);
        LL ans = 0;
        if (p >= N)
        {
            ans = (LL)n*m;
        }
        else
        {
            if (n > m)
            {
                n ^= m;
                m ^= n;
                n ^= m;
            }
            for (i = 1; i <= n; i = j + 1)
            {
                j = min(n/(n/i), m/(m/i));
                ans += ((LL)F[j][p]-F[i-1][p])*(n/i)*(m/i);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
