#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[25][25][25];
int search(int a,int b,int c)
{
    //printf("****\n");
    if(a<=0||b<=0||c<=0)
        return 1;
    if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    else if(a>20||b>20||c>20)
    {
        dp[a][b][c]=search(20,20,20);
        return dp[a][b][c];
    }
    else if(a<b&&b<c&&c<=20)
    {
        dp[a][b][c]=search(a,b,c-1)+search(a,b-1,c-1)-search(a,b-1,c);
        return  dp[a][b][c];
    }
    else
    {
        dp[a][b][c]=search(a-1,b,c)+search(a-1,b-1,c)
        +search(a-1,b,c-1)-search(a-1,b-1,c-1);
        return dp[a][b][c];
    }

}
int main()
{
    int a,b,c,ans;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=20;i++)
        for(int j=0;j<=20;j++)
        {
            dp[0][i][j]=1;
            dp[i][0][j]=1;
            dp[i][j][0]=1;
         }
    
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
      if(a==-1&&b==-1&&c==-1) 
          break;
      if(a<=0||b<=0||c<=0)
          ans=1;
      else if(a>20||b>20||c>20)
          ans=search(20,20,20);
      else
           ans=search(a,b,c);
      printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
    }
    system("pause");
    return 0;
}