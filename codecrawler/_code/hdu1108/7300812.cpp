#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    int r;
    if(a<b){r=a;a=b;b=r;}
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
      int a, b;
      while(scanf("%d%d",&a,&b)!=EOF)
      {   printf("%d\n",a*b/gcd(a,b) );
      }
      //system("pause");
      return 0;
}
