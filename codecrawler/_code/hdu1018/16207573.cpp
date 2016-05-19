#include"stdio.h"
#include"math.h"
int main()
{
    int n;
    double temp;
    int T;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        temp=0.5*log10(2*3.1415927*n)+n*log10(n/2.718281828459);
        printf("%d\n",(int)temp+1);
    }
    return 0;
}