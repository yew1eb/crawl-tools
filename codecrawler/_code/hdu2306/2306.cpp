#include<stdio.h>
#include<math.h>
int main()
{
    int n ;
    int x1,x2,x3,y1,y2,y3 ;
    while(scanf("%d",&n)!=EOF)
     {
         if(n==0)
              break ;
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
         double sum=0 ;
         for(int i=2;i<n;i++)
          {
              scanf("%d%d",&x3,&y3);
              sum=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
              printf("%.1lf\n",sum) ;
              x2=x3 ;
              y2=y3 ;
          }
        printf("%.1lf\n",sum/2.0) ;
     }
     return 0 ;
}