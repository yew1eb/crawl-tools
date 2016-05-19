#include <stdio.h>
#include <math.h>

double f(int x,int y,int m,int n)
{
    return sqrt(x*x + y*y + m*m + n*n - 2*m*x - 2*n*y);
}

int main()
{
    double a,b,c,d,t,x,y;
    double min,m;

    scanf("%lf",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        min = 100000;
        for(x = 0; x<=100; x++)//ç¨x,yå¾ªç¯æ¾åºæå°çåæ°
        {
            for(y = 0; y<=100; y++)
            {
                m =  f(x,y,a,b) + f(x,y,c,d);
                if(min > m)
                    min = m;
            }
        }
        printf("%.1lf\n",min);
    }

    return 0;
}


