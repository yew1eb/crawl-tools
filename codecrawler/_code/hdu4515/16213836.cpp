#include <stdio.h>
int day[2][13]  = {0,31,28,31,30,31,30,31,31,30,31,30,31,0,31,29,31,30,31,30,31,31,30,31,30,31};

int judge(int y)
{
    if (y%4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int t, n;
    scanf("%d",&t);
    while (t--)
    {
        int sy = 2013, sm = 3, sd = 24;
        scanf("%d",&n);
        sd += n;
        while (1)
        {
            int y = judge(sy);
            if(sd > day[y][sm])
            {
                sd -= day[y][sm];
                sm += 1;
                if(sm > 12)
                {
                    sm = 1;
                    sy += 1;
                }
            }
            else
                break;
        }
        printf("%4d/%02d/%02d ",sy,sm,sd);
        sy = 2013, sm = 3, sd = 24;
        sd -= n;
        while (1)
        {
            if(sd < 1)
            {
                sm -= 1;
                if(sm < 1)
                {
                    sm = 12;
                    sy -= 1;
                }
                int y = judge(sy);
                sd += day[y][sm];
            }
            else
                break;
        }
        printf("%4d/%02d/%02d\n",sy,sm,sd);
    }
}