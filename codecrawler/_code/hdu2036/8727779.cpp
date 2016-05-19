#include<stdio.h>
int main( void )
{
    int n,i;
    int x[100],y[100];
    while(scanf("%d",&n)!=EOF,n)
    {
        double sum=0.0;
       for( i=0 ; i<n ; i++ )
       {
           scanf("%d%d",x+i,y+i);
       }
       for( i=0 ; i<n-1 ; i++ )
       {
          sum+=x[i]*y[i+1]-x[i+1]*y[i] ;
       }
       sum+=x[i]*y[0]-x[0]*y[i];
       printf("%.1lf\n",sum/2);
    }
    return 0;

}