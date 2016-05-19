#include <cstdio>
int mon(int x)
{
    if(x == 1)
        return 31;
    else if(x == 2)
        return 28;
    else if(x == 3)
        return 31;
    else if(x == 4)
        return 30;
    else if(x == 5)
        return 31;
    else if(x == 6)
        return 30;
    else if(x == 7)
        return 31;
    else if(x == 8)
        return 31;
    else if(x == 9)
        return 30;
}
int main()
{
    int t;
    int m, d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&d);
        if(m == 10 && d == 21)
        {
            printf("It's today!!\n");
            continue;
        }
        if(m>10 ||(m==10&&d>21))
        {
            printf("What a pity, it has passed!\n");
            continue;
        }
        int sum = 0;
        for(int i = m; i < 10; i++)
        {
            sum+=mon(i);
        }
        printf("%d\n",sum-d+21);
    }
    return 0;
}