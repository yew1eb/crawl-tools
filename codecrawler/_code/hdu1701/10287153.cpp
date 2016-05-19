#include<stdio.h>
int main()
{
    double     p,q,a,b;
    int t,i,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf",&p,&q);
        for(i=1;;i++)
        {
            a=p*i/100;
            b=q*i/100;
            x=int(a);
            y=int(b);
            if(x<a&&x+1==y)break;
            }
            printf("%d\n",i);
        }
        return 0;
    }