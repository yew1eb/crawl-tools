#include<iostream>
#include<cstdio>
using namespace std;
__int64 dp[55] = {0, 1, 2, 3};

void fun()
{
    for(int i = 4; i <= 50; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
}

int main()
{
    int n;
    fun();
    while(scanf("%d", &n) != EOF)
        printf("%I64d\n", dp[n]);
    return 0;
}