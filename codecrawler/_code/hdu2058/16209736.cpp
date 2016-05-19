#include <string.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,n,m,t;
   while(scanf("%d%d",&n,&m), m && n)
   {
           m*=2;
           for(i=(int)sqrt((double)m);i>=2;i--)
           {
                 if(m%i==0)
                 {
                         t=m/i+1-i;
                         if (t>=2 && t%2==0)
                         {
                              t>>=1;
                              if(t+i-1<=n)
                                  printf("[%d,%d]\n",t,t+i-1);
                          }
                 }
           }
           m>>=1;
           if(n>=m) printf("[%d,%d]\n",m,m);
           printf("\n");
    }
   return 0;
}


