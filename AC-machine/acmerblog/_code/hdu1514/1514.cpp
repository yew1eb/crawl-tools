#include<stdio.h>
#include<string.h>
int num[45][5],n;
int x[5],dp[45][45][45][45];
int dfs(int market,int cnt)
{
 int sum,i,bit,Max=0;
 if(dp[x[1]][x[2]][x[3]][x[4]]!=-1)
  return dp[x[1]][x[2]][x[3]][x[4]];
 for(i=1;i<=4;i++)
 {
  sum=0;
  x[i]++;
  if(x[i]<=n){
   bit=(1<<num[x[i]][i]);
   if(market&bit)
    sum=dfs(market&(~bit),cnt-1)+1;
   else if(cnt<4)
    sum=dfs(market|bit,cnt+1); 
  }
  if(sum>Max)Max=sum;
  x[i]--;
 }
 dp[x[1]][x[2]][x[3]][x[4]]=Max;
 return Max;
}
int main()
{
 int i,j;
 while(scanf("%d",&n),n)
 {
  for(i=1;i<=n;i++)
   for(j=1;j<=4;j++)
    scanf("%d",&num[i][j]);
  x[1]=x[2]=x[3]=x[4]=0;
  memset(dp,-1,sizeof(dp));
  printf("%d\n",dfs(0,0));
 }
 return 0;
}