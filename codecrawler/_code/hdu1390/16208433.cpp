#include<stdio.h>
int d=0,n=0;
int main()
{
    while(scanf("%d",&d)!=EOF)
    {
        while(d--)
        {
           scanf("%d",&n);
           int ind=0;
           while(n>0)
           {
               if(n%2==1)
               {
                   printf("%d",ind);
                   ind++;
                   n/=2;
                   break;
               }
               ind++;
               n/=2;
           }
           while(n>0)
           {
               if(n%2==1) printf(" %d",ind);
               ind++;
               n/=2;
           }
           printf("\n");
        }
    }
    return(0);
}
