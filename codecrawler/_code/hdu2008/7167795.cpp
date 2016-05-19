#include<stdio.h>
int main()
{
    int a, b, c;
    int n, i;
    double x;
    while(scanf("%d",&n)!=EOF &&n!=0)
    {
        a =b =c =0;
        for(i=1;i<=n;i++)
        {
           scanf("%lf",&x);
           if(x<0) a++;
            else if(x==0) b++;
            else  c++;
        }
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
