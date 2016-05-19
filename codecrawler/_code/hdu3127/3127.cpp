#include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cstring>
 using namespace std;
 
 const int maxn=1024;
 int dp[maxn][maxn];
 
 struct node
 {
     int  x, y, val;
 }f[maxn];
 
 int main()
 {
     int  T, n, X, Y;
     cin >> T;
     while(T--)
     {
         cin >> n >>X >> Y;
         for(int i=0; i<n; i++)
             scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].val);
         memset(dp,0,sizeof(dp));
         for(int i=0; i<=X; i++)
             for(int j=0; j<=Y; j++)
                for(int k=0; k<n; k++)
                {
                    if(i-f[k].x>=0&&j-f[k].y>=0)
                        dp[i][j]=max(dp[i][j],max(dp[i-f[k].x][j]+dp[f[k].x][j-f[k].y],dp[i-f[k].x][f[k].y]+dp[i][j-f[k].y])+f[k].val);
                    if(i-f[k].y>=0&&j-f[k].x>=0)
                          dp[i][j]=max(dp[i][j],max(dp[i-f[k].y][j]+dp[f[k].y][j-f[k].x],dp[i-f[k].y][f[k].x]+dp[i][j-f[k].x])+f[k].val);
                }
         cout << dp[X][Y] << endl;
     }
     return 0;
 }