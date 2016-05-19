#include <stdio.h>
int f(int a,int b)
{                       //æ±æå¤§å¬çº¦æ°
    int temp,r;
    if (a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    r=a%b;
  while(r)
  {
      a=b;
      b=r;
      r=a%b;
  }
  return b;
}
int main ()
{
    int t;
    int n,i,a,b;
    int j,sum;
    int k;
    scanf ("%d",&t);
    for (i=1;i<=t;i++)
    {
        k=0;
        scanf ("%d%d%d",&n,&a,&b);
        sum=f(a,b);
        for (j=sum;j<=n;j+=sum)     //jæ¯æ¬¡å çæ¯aåbçæå¤§å¬çº¦æ°
            k++;
        k-=2;
    if (k%2==0)
        printf ("Case #%d: Iaka\n",i);
    else
        printf ("Case #%d: Yuwgna\n",i);
    }
    return 0;
}



