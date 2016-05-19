#include<iostream>
#include<algorithm>
using namespace std;
struct num
{
 int x,y;
 int s;
}dp[20001];
int cmp(num a,num b)
{return a.s>b.s;}
int main()
{
 //freopen("1.txt","r",stdin);
 int m,n,i,j;
 int a,b,c,d;
 while(scanf("%d%d",&m,&n)!=EOF)
 {
        for(i=0;i<m;i++)
  {scanf("%d%d",&dp[i].x,&dp[i].y);dp[i].s=0;}
  for(i=0;i<n;i++)
  {
   scanf("%d%d%d%d",&a,&b,&c,&d);
   for(j=0;j<m;j++)
   {
    if(dp[j].x>=a&&dp[j].x<=c&&dp[j].y>=b&&dp[j].y<=d)
      if(dp[j].s==0)
         dp[j].s+=(c-a+d-b)*2;
   }
  }
  sort(dp,dp+m,cmp);
  for(i=0;i<m;i++)
   printf("%d\n",dp[i].s);
 }
 return 0;
}
