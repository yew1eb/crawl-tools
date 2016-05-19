#include<stdio.h>
int main()
{
  double n;
  while(scanf("%lf",&n)!=EOF)
  {
     while(n>18) n/=18;
     printf(n<=9?"Stan wins.\n":"Ollie wins.\n");
  }
  return 0;
}