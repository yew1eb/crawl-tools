//program G

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
  putchar('\n');
}

int main()
{
  int n,m;
  while(cin>>n>>m)
    {
      double p[16],h[16][16];
      for(int i=0;i<n;i++)
        cin>>p[i];
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          cin>>h[i][j];
      double reach[16][17];
      for(int i=0;i<n;i++)
        {
          reach[i][0]=1;
          for(int j=1;j<m;j++)
            reach[i][j]=reach[i][j-1]*p[i];
          reach[i][m]=0;
        }
      double ans=0;
      for(int p=0;p<n;p++)
        for(int q=0;q<m;q++)
          {
            ans+=reach[p][q]*h[p][q];
            if(!q)
              continue;
            static double dp[17][17][17];
            memset(dp,0,sizeof(dp));
            dp[0][0][0]=1;
            for(int i=0;i<n;i++)
              for(int j=0;j<=i;j++)
                for(int k=0;k<=j;k++)
                  if(i==p)
                    dp[i+1][j+1][k+1]+=dp[i][j][k];
                  else
                    {
                      double a=1-reach[i][q-1],b=reach[i][q-1]-reach[i][q],c=reach[i][q];
                      dp[i+1][j][k]+=a*dp[i][j][k];
                      dp[i+1][j+1][k]+=b*dp[i][j][k];
                      dp[i+1][j+1][k+1]+=c*dp[i][j][k];
                    }
            for(int i=1;i<=n;i++)
              for(int j=0;j<=i;j++)
                ans+=reach[p][q]*dp[n][i][j]*j/i*h[p][q];
          }
      printf("%0.10lf\n",ans);
    }
  return 0;
}