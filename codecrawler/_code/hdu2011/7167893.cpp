#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, m;
    int i, j;
    scanf("%d",&m);
    int x;
    double sum;
    int sign;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        sign=-1;
        sum = 0;
        for(j=1;j<=x;j++)
           {
               sign*=-1;
               sum=sum+sign*1.0/j;
               //printf("%d %d %d %f\n",i,j,sign,sum);
           }
        printf("%.2lf\n",sum);
    }
  //  system("pause");
    return 0;
}
