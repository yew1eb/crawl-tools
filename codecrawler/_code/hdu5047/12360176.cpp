//program F

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>

using namespace std;

struct number
{
  long long x[3];
  void set(long long n)
    {
      x[0]=n%1000000000;
      x[1]=n/1000000000;
      x[2]=0;
    }
  void output()
    {
      int p=2;
      while(!x[p])
        p--;
      cout<<x[p];
      for(int i=p-1;i>=0;i--)
        for(int j=100000000;j>=1;j/=10)
          putchar((x[i]/j)%10+48);
      putchar('\n');
    }
};

number operator +(number a,number b)
{
  number c;
  for(int i=0,g=0;i<3;i++)
    {
      c.x[i]=a.x[i]+b.x[i]+g;
      g=c.x[i]/1000000000;
      c.x[i]%=1000000000;
    }
  return c;
}

number operator -(number a,number b)
{
  number c;
  for(int i=0,g=0;i<3;i++)
    {
      c.x[i]=a.x[i]-b.x[i]+g;
      if(c.x[i]<0)
        {
          c.x[i]+=1000000000;
          a.x[i+1]--;
        }
    }
  return c;
}

number operator *(number a,number b)
{
  number c;
  c.x[0]=c.x[1]=c.x[2]=0;
  for(int i=0;i<3;i++)
    for(int j=0;i+j<3;j++)
      c.x[i+j]+=a.x[i]*b.x[j];
  for(int i=0;i<2;i++)
    {
      c.x[i+1]+=c.x[i]/1000000000;
      c.x[i]%=1000000000;
    }
  return c;
}

long long get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  long long x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      long long n=get();
      number N,a,b,c;
      N.set(n);
      a.set(8);
      b.set(7);
      c.set(1);
      number ans=N*N*a-b*N+c;
      printf("Case #%d: ",test);
      ans.output();
    }
  return 0;
}