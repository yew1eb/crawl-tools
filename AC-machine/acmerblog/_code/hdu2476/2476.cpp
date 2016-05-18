//============================================================================
// Name        : HDU.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=110;
int dp[MAXN][MAXN];
char str1[MAXN],str2[MAXN];
int ans[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s%s",str1,str2)==2)
    {
        int n=strlen(str1);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                dp[i][j]=j-i+1;
        //先直接DP求出从空白串变成str2
        for(int i=n-2;i>=0;i--)
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++)
                    if(str2[i]==str2[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
            }
        for(int i=0;i<n;i++)
        {
            ans[i]=dp[0][i];
            if(str1[i]==str2[i])
            {
                if(i==0)ans[i]=0;
                else ans[i]=ans[i-1];
            }
            for(int j=0;j<i;j++)
                ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
        }
        printf("%d\n",ans[n-1]);
    }
    return 0;
}