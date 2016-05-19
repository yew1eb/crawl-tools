#include <stdio.h>
int main ()
{
int n,i,a[100];
a[0]=1;a[1]=2;
for (i=2;i<44;i++)
   a[i]=a[i-1]+a[i-2]+1;
while (scanf("%d",&n)!=EOF)
{
   if (n==0) return 0;
   i=0;
   while (a[i]<=n)
    i++;
   printf ("%d\n",--i);
}
return 0;
}