#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define Len 50000

bool a[Len];
int b[Len];
int k;
void Isprime()
{
     int i,j;
     a[2]=true;
     k=1;
     b[0]=2;
     for(i=3;i<Len;i++)
     {
                       if(i&1)
                       a[i]=true;
                       else
                       false;
     }
     for(i=3;i<Len;i++)
     {
                       if(a[i])
                       {
                               b[k]=i;
                               k++;
                               for(j=i+i;j<Len;j+=i)
                                                    a[j]=false;
                       }
     }
}
int main()
{
    Isprime();
    int x,n,i,j,sum,m=1,t;
    scanf("%d",&n);
    while(n--)
    {
              j=0;
              sum=1;
              scanf("%d",&x);
              for(i=0;i<k;i++)
              {
                    t=0;
                    if(x<b[i])
                    break;
                    while(x%b[i]==0 )
                    {
                           x=x/b[i]; 
                           t++;        
                    }
                    sum *= (t*2+1);
                    j++;
              }
              printf("Scenario #%d:\n",m);
              m++;
              if(x>1)  // 可能 存在 一个 素数 X . 
              sum*=3;
              printf("%d\n\n",(sum+1)/2);
    }
    return 0;
}