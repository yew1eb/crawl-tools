#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 5060
int dp[2][maxn];
char s1[maxn],s2[maxn];
int main()
{
    int n,m,i,j,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s1+1);
        for(i=1;i<=n;i++){
            s2[i]=s1[n+1-i];
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                x=i%2;
                y=1-x;
                if(s1[i]==s2[j]){
                    dp[x][j]=dp[y][j-1]+1;
                }
                else{
                    dp[x][j]=max(dp[x][j-1],dp[y][j]);
                }
            }
        }
        printf("%d\n",n-dp[n%2][n]);
    }
    return 0;
}