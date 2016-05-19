#include <stdio.h>
double a[100],b[100];
double sum1,sum2;
int main()
{
    int n,i,p;
    while(scanf("%d",&n)!=EOF)
    {
        sum1=0;sum2=0;
        for(i=0;i<n;i++)
        scanf("%lf%lf",&a[i],&b[i]);
        for(i=0;i<n;i++)
        {            
            if(b[i]==-1)
            continue;
            else 
            {
                sum2+=a[i];
                p=(int) (b[i]/10);
                if(p<6) sum1+=0;
                if(p==6) sum1+=a[i];
                if(p==7) sum1+=(2*a[i]);
                if(p==8) sum1+=(3*a[i]);
                if(p==9) sum1+=(4*a[i]);
            }            
        }
        if(sum2==0)
        printf("-1\n");
        else 
        printf("%.2lf\n",sum1/sum2);
    }
    return 0;
}