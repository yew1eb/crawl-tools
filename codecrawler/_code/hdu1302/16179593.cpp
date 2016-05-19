#include<stdio.h>
int main()
{
    double H,U,D,F,sum;
    int i;
    double d;
    while(scanf("%lf",&H)!=EOF&&H)
    {
        int p;
        scanf("%lf%lf%lf",&U,&D,&F);
        d=U*(F/100.0);
        sum=0;
        for(i=0;;i++)
        {
            sum=sum+U-D;
            if(sum>=H)
            {
                p=1;
                break;
            }
            if(sum<0)
            {
                p=0;
                break;
            }
            U=U-d;
        }
        p?printf("success on day %d\n",i):printf("failure on day %d\n",i+1);
    }
    return 0;
}