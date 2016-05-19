/******************************************************
 * File Name:   5087.cpp
 * Author:      kojimai
 * Create Time: 2014å¹´11æ01æ¥ ææå­ 22æ¶41å42ç§
******************************************************/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define FFF 1005
int a[FFF],dp[FFF],dp2[FFF];
int getans(int i,int j)//ä»¥jä¸ºæ«å°¾çéå¢å­åºåçæå¤§é¿åº¦æ´æ°æ°é¿åº¦
{
    if(a[i] < a[j])
        return 0;
    else if(a[i] == a[j])//ç¸ç­æ¶ææé¿åº¦ç¸å
        return dp[j];
    else//æ¯a[j]å¤§æ¶ææçæ°é¿åº¦+1
         return dp[j] + 1;
}
int getans2(int i,int j)//ä»¥jä¸ºæ«å°¾çéå¢å­åºåçæ¬¡å¤§é¿åº¦æ´æ°æ°é¿åº¦
{
    if(a[i] < a[j])
        return 0;
    else if(a[i] == a[j])
        return dp2[j];
    else
        return dp2[j] + 1;
}
int main()
{
    int keng;
    scanf("%d",&keng);
    while(keng--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        dp[0] = 1;
        int one = 1,second = 0;//oneå½åæ±å¾çæå¤§é¿åº¦,secondä¸ºæ¬¡å¤§é¿åº¦
        for(int i = 1;i < n;i++)
        {
            dp[i] = 1;
            //cout<<" i = "<<i<<endl;
            for(int j = 0;j < i;j++)
            {
                int tmp = getans(i,j);
            //    cout<<" tmp1  = "<<tmp;
                if(tmp > dp[i])
                {
                    dp2[i] = dp[i];
                    dp[i] = tmp;
                }
                else if(tmp > dp2[i])
                    dp2[i] = tmp;
                tmp = getans2(i,j);
            //    cout<<" tmp2 = "<<tmp<<endl;
                if(tmp > dp2[i])
                    dp2[i] = tmp;
            }
            //cout<<" dp = "<<dp[i]<<" "<<dp2[i]<<endl;
            if(one < dp[i])
            {
                second = one;
                one = dp[i];
            }
            else if(second < dp[i])
            {
                second = dp[i];
            }
            if(second < dp2[i])
                second = dp2[i];
        }
        cout<<second<<endl;
    }
    return 0;
}
