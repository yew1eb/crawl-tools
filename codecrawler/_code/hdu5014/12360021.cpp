//program H

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

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
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
}

long long sum;
int ans[100000];

void construct(int n)
{
  sum=0;
  for(int i=19;i>=0&&n>=0;i--)
    if(n&(1<<i))
      {
        int s=(2<<i)-1;
        for(int j=s-n;j<=n;j++)
          {
            ans[j]=s-j;
            sum+=s;
          }
        n=s-n-1;
      }
  if(!n)
    ans[0]=0;
}

int main()
{
  int n;
  while(cin>>n)
    {
      construct(n);
      cout<<sum<<endl;
      for(int i=0;i<=n;i++)
        {
          output(ans[get()]);
          putchar((i==n)?'\n':' ');
        }
    }
  return 0;
}