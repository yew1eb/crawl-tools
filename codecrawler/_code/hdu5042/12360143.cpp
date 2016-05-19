//program A

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

struct info
{
  int l,r0,r1,w;
};

bool operator <(info a,info b)
{
  return (a.w==b.w)?(a.l<b.l):(a.w<b.w);
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

void output(long long x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[20];
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

int Log[100001];
int dp[17][100000];

int gcd(int a,int b)
{
  return b?gcd(b,a%b):a;
}

int query(int l,int r)
{
  int p=Log[r-l+1];
  return gcd(dp[p][l],dp[p][r-(1<<p)+1]);
}

int main()
{
  for(int i=1,j=0;i<=100000;i++)
    {
      if(i==(1<<(j+1)))
        j++;
      Log[i]=j;
    }
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get(),q=get();
      for(int i=0;i<n;i++)
        dp[0][i]=get();
      for(int i=1;i<17;i++)
        for(int j=0;j+(1<<i)<=n;j++)
          dp[i][j]=gcd(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
      printf("Case #%d:\n",test);
      int total=0;
      static info a[1700000];
      for(int i=0;i<n;i++)
        {
          int p=n-1,s=query(i,p);
          while(s!=dp[0][i])
            {
              int l=i,r=p-1;
              while(l<r)
                {
                  int mid=(l+r+1)/2;
                  if(query(i,mid)==s)
                    r=mid-1;
                  else
                    l=mid;
                }
              a[total++]=(info){i,l+1,p,s};
              p=l;
              s=query(i,p);
            }
          a[total++]=(info){i,i,p,s};
        }
      sort(a,a+total);
      static int start[1700000],data[1700000];
      static long long sum[1700000];
      int m=0;
      for(int i=0;i<total;i++)
        if(!i||a[i].w!=a[i-1].w)
          {
            data[m]=a[i].w;
            start[m++]=i;
            sum[i]=0;
          }
        else
          sum[i]=sum[i-1]+(a[i-1].r1-a[i-1].r0+1);
      start[m]=total;
      while(q--)
        {
          char c;
          while(c=getchar(),c!='R'&&c!='S');
          if(c=='R')
            {
              int l=get()-1,r=get()-1,w=query(l,r);
              w=lower_bound(data,data+m,w)-data;
              output(w+1);
              putchar(' ');
              int L=start[w],R=start[w+1]-1;
              while(L<R)
                {
                  int mid=(L+R)/2;
                  if(l>a[mid].l)
                    L=mid+1;
                  else
                    R=mid;
                }
              output(sum[L]+r-a[L].r0+1);
              putchar('\n');
            }
          else
            {
              long long w=get()-1,k2=get()-1;
              if(w>=m)
                {
                  printf("-1\n");
                  continue;
                }
              int L=start[w],R=start[w+1]-1;
              while(L<R)
                {
                  int mid=(L+R+1)/2;
                  if(sum[mid]>k2)
                    R=mid-1;
                  else
                    L=mid;
                }
              k2-=sum[L];
              if(a[L].r0+k2>a[L].r1)
                {
                  printf("-1\n");
                  continue;
                }
              output(a[L].l+1);
              putchar(' ');
              output(a[L].r0+k2+1);
              putchar('\n');
            }
        }
    }
  return 0;
}