#include <stdio.h>
int main ()
{
int n,c;
double sum;
while (scanf("%d",&n)!=EOF)
{
   if (n==0)break;
   sum=1.0/6*n*(n+2)*(n+1);
   c=0;
   while (sum>=10)
   {
    c++;
    sum/=10;
   }
   printf ("%.02lfE%d\n",sum,c);
}
return 0;
}