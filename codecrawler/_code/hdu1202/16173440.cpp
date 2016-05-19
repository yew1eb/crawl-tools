#include <stdio.h>

int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        double n,m,sum1 = 0,sum2 = 0;
        while(t--)
        {
            scanf("%lf%lf",&n,&m);
            if(m == -1)
            continue;
            sum1+=n;
            if(m>=90) m = 4;
            else if(m>=80) m = 3;
            else if(m>=70) m = 2;
            else if(m>=60) m = 1;
            else if(m<60) m = 0;
            sum2+=m*n;
        }
        if(sum1 <=0 || sum2 <=0)
        {
            printf("-1\n");
            continue;
        }
        printf("%.2lf\n",sum2/sum1);
    }

    return 0;
}
