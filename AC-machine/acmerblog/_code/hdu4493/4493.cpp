#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int n,i,m;
    double temp,sum;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        for(i=0;i<12;i++)
        {
             scanf("%lf",&temp);
            sum+=temp;
        }
        sum=sum/12.0;
        int m=(int)(sum*100);
        int sum0=(int)(sum*1000);
        if(sum0%10>=5)
        m+=1;
        printf("$%d",m/100);
        m=m%100;
        if(m%100==0)
        {
             printf("\n");
        }
        else if(m%10==0)
        {
            printf(".%d\n",m/10);
        }
        else
        {
            if(m<10)
            printf(".0%d\n",m);
            else
            printf(".%d\n",m);
        }
    }
    return 0;
}
