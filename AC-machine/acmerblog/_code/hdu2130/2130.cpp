#include <stdio.h>
int main ()
{
__int64 a,b,c,n;
while (scanf("%I64d %I64d %I64d",&a,&b,&c)!=EOF)
{
   if (a==-1 && b==-1 && c==-1) return 0;
   n=a*(a+1)*b*(b+1)*c*(c+1)/8;
   printf ("%I64d\n",n);
}
return 0;
}
用int也行：
#include <stdio.h>
int main ()
{
int a,b,c,n;
while (scanf("%d %d %d",&a,&b,&c)!=EOF)
{
   if (a==-1 && b==-1 && c==-1) return 0;
   n=0.125*a*(a+1)*b*(b+1)*c*(c+1);
   printf ("%d\n",n);
}
return 0;
}