#include <stdio.h>

int b[20] = {0,31,28,31,30,31,30,31,31,30,31,30,31,0};
int Y = 1, M = 1, D = 1;
int leap(int y)
{
    if(y%400 == 0 || (y%4 == 0 && y%100!=0))
        return 1;
    return 0;
}

int main()
{
    int y,m,d,i;
    while(~scanf("%d%d%d",&y,&m,&d))
    {
        if(leap(y))
            b[2] = 29;
        else
            b[2] = 28;
        if(d > b[m] || d < 1 || m < 1 || m > 12 || y <1 || y>10000)
        {
            printf("illegal\n");
            continue;
        }
        int sum = 0;
        sum+=d;
        for(i = 0; i<m; i++)
            sum+=b[i];
        sum%=7;
        for(i = 1; i<y; i++)
        {
            sum+=365;
            if(leap(i))
                sum++;
            sum%=7;
        }
        int  dx = sum%7;
        if(dx==0)
            printf("Sunday\n");
        else if(dx == 1)
            printf("Monday\n");
        else if(dx == 2)
            printf("Tuesday\n");
        else if(dx == 3)
            printf("Wednesday\n");
        else if(dx == 4)
            printf("Thursday\n");
        else if(dx == 5)
            printf("Friday\n");
        else if(dx == 6)
            printf("Saturday\n");
    }
    return 0;
}
