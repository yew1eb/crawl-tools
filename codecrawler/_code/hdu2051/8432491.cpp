#include <stdio.h>

int a[10000];
int main()
{
int x, n;
while(~scanf("%d",&x))
{
n = 0;
while(x)
{
 a[++n] = x % 2;
 x/=2;
}
while(n>0)printf("%d",a[n--]);
printf("\n");
}
return 0;
}