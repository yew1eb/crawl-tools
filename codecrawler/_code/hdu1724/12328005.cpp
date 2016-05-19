#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int a,b,i,j,n,s,t;
    double re,ans,ant;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d",&a,&b,&s,&t);
        ant=acos(t/(float)a);
        ans=acos(s/(float)a);
        re=a*b*((sin(2*ant)-sin(2*ans))/2-(ant-ans));
        printf("%.3f\n",re);
    }
    //system("pause");   
}