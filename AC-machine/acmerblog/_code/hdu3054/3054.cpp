#include<stdio.h>
#include<math.h>

int fac[22]={0,1,1};
double f=(sqrt(5.0)+1.0)/2.0;
int main()
{
    double bit;
    int n;
    for(int i=3;i<=20;i++)  fac[i]=fac[i-1]+fac[i-2];
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=20)
        {
            printf("%d\n",fac[n]);
            continue;
        }
        bit=-0.5*log(5.0)/log(10.0)+((double)n)*log(f)/log(10.0);
        bit=bit-floor(bit);
        bit=pow(10.0,bit);
        while(bit<1000)
        {
            bit=bit*10.0;
        }
        printf("%d\n",(int)bit);
    }
    return 0;
}