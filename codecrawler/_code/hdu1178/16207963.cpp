#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double n,a,m,b;
    while(scanf("%lf",&n)!=EOF&&n!=0)
    {
        b=log10(n*1.0/6)+log10((n+1)*1.0)+log10((n+2)*1.0);
        a=b-(int)(b);
        m=pow(double(10),a);
        printf("%.2lfE%d\n",m,(int)(b));
    }
    return 0;
}