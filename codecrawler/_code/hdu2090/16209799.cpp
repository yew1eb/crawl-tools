#include <stdio.h>
int main()
{
    char s[100];
    double n,price,sum=0.0;
    while(scanf("%s%lf%lf",s,&n,&price)!=EOF)
    {
            sum+=n*price;
            
    }
    printf("%.1lf\n",sum);
    return 0;
}