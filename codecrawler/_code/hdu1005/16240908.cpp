#include <stdio.h>
int main ()
{    
    int f[51];
    int a, b, n,i,T; 
    while(scanf("%d%d%d",&a,&b,&n),a||b||n)
    {
          f[1]=f[2]=1;
          for (i=3;i<51;i++)
          {
             f[i]=(a*f[i-1]+b*f[i-2])%7;
              if (f[i]==1&&f[i-1]==1)  
              {
                  break;
              }
          }          
          T=i-2;
          f[0]=f[T];
          printf ("%d\n", f[n%T]);
    }   
    return 0;
} 