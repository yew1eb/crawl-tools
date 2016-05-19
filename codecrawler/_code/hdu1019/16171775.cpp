#include<iostream>
using namespace std;
int gcd(long long  x,long long y)
{
    int a;
    if(x<y)  a=x,x=y,y=a;
    while (y!=0)
    {
          a=x%y;
          x=y;
          y=a;
    }
    return x;
}
int main()
{
    int t;
    int n;
    long long temp,end;
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d",&n);
          end=1;
          for (int i=0;i<n;i++)
          {
              scanf("%I64d",&temp);
              end=(end*temp)/gcd(end,temp);
          }
          printf("%I64d\n",end);
    }
    return 0;
}
