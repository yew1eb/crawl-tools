// File Name: hdu1208.cpp
// Author: rudolf
// Created Time: 2013å¹´04æ25æ¥ ææå 19æ¶06å19ç§

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<stdio.h>
using namespace std;
const int  maxn=50;
char mapp[maxn][maxn];
__int64 dp[maxn][maxn];
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        getchar();
        for(int i=0;i<n;i++)
            gets(mapp[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(mapp[i][j]-'0')
                {
                    if(i+mapp[i][j]-'0'<=n)
                        dp[i+mapp[i][j]-'0'][j]+=dp[i][j];
                    if(j+mapp[i][j]-'0'<=n)
                        dp[i][j+mapp[i][j]-'0']+=dp[i][j];
                }
            }
        printf("%I64d\n",dp[n-1][n-1]);
    }    
return 0;
}