#include <stdio.h>

int main()
{
    double a;
    while(~scanf("%lf",&a),a)
    {
        double b = 0,i;
        for(i = 1;b<a;i++)
        {
            b+=1/(i+1);
        }
        printf("%.0lf card(s)\n",i-1);
    }
    return 0;
}
