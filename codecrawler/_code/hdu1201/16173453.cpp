#include <stdio.h>

int leap(int y)
{
    if(y%400 == 0 || (y%4 == 0 && y%100!=0))
        return 1;
    return 0;
}

int main()
{
    int y,m,d,i,n;
    scanf("%d",&n);
    while(n--)
    {
        int sum = 0;
        scanf("%d-%d-%d",&y,&m,&d);
        if(m == 2 && d == 29)
        {
            printf("-1\n");
            continue;
        }
        sum = 365*18;
        if(leap(y) && m<3)
            sum++;
        if(leap(y+18) && m>=3)
            sum++;
        for(i = y+1; i<y+18; i++)
            if(leap(i))
                sum++;
        printf("%d\n",sum);
    }

    return 0;
}
