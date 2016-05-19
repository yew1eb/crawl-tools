#include<stdio.h>

double dp[1001][101];

int initDP(int w)
{
    int i;
    for(i = 0; i < 100; i ++)
    {
        dp[w][i] = 0;
    }
    return 0;
}

int init()
{
    int i, j, k;
    initDP(0);
    dp[0][0] = 1;
    for(i = 1; i <= 1000; i ++)
    {
        initDP(i);
        for(j = 0; j <= 9; j ++)
        {
            for(k = 0; k < 100; k ++)
            {
                dp[i][(k + j) % 100] += dp[i - 1][k] / 10;
            }
        }
    }
    return 0;
}

int get(int big1, int big2, int small, int x)
{
    if(big1 != big2)
    {
        if(x != big1 && x != big2 && x != small)
            return 1;
        if(big1 != 0 && big2 != 0)
        {
            if(x == big1 || x == big2)
                return -3;
            if(x == small)
                return -2;
        }
        if(big1 == 0 || big2 == 0)
        {
            if(x == big1 || x == big2)
                return -4;
        }
    }
    else
    {
        if(x != big1 && x != big2 && x != small)
            return -1;
        if(big1 != 0)
        {
            if(x == big1)
                return 3;
            if(x == small)
                return 2;
        }
        if(big1 == 0)
        {
            if(x == 0)
                return 4;
        }
    }
    return -1;
}

int main()
{
    int i, j, n;
    double result;
    init();
    while(scanf("%d", &n) != EOF && n != 0)
    {

        for(i = 0; i <= 9; i ++)
        {
            result = 0;
            for(j = 0; j < 100; j ++)
            {
                result += get(j % 10, j / 10, (j % 10 + j / 10) % 10, i) * dp[n][j];
            }
            if(i != 0)
                printf(" ");
            printf("%.2lf", result);
        }
        printf("\n");
    }
    return 0;
}