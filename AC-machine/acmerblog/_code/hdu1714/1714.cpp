#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,j,flag,t;
    double a,b,c,d,x,y,s;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        x=sqrt(1/(a*a*d*d+c*c*b*b))*a*c*b;
        y=d*x/c;
        s=(a*b/2)*acos(x/a);
        printf("%.2f\n",s);

         
    }
    return 0;
}