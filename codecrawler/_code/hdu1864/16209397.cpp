#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

double total;
int t,n,m,len;
double A,B,C,money[50],q,dp[50];  //money[i]è¡¨ç¤ºæ»´iä¸ªåç¥¨å±å¯æ¥éçé±æ°ï¼dp[i]è¡¨ç¤ºæ¥éiä¸ªåç¥¨å¯è·å¾çæå¤é±æ°ã
char ch ,c;

double max(double a,double b)
{
    return a>b?a:b;
}

int main()
{
    int i,j,k;
    while(scanf("%lf %d",&total,&t))
    {
        len=0;
        memset(money,0,sizeof(money));
        memset(dp,0,sizeof(dp));
        if(t==0) break;
        for(i=1;i<=t;i++)
        {
            int flag=1;
            A=0;B=0;C=0;
           scanf("%d",&n);
           for(j=0;j<n;j++)
           {
               scanf(" %c:%lf",&ch,&q);
               if(ch!='A' && ch!='B' && ch!='C' || q>600)   //ç±é¢æå¾
               {
                   flag=0;
                   break;
               }
               if(ch=='A') A+=q;
               else if(ch=='B') B+=q;
               else if(ch=='C') C+=q;
           }
           if(flag && A+B+C<=1000 && A<=600 && B<=600 &&C<=600)    //åç©åï¼ä¸¤ä¸ªA ç®ä¸ä¸ªãã
                  money[len++]=A+B+C;
        }
        for(i=0;i<=len;i++)
        {
            for(j=len;j>=1;j--)
            {
                if(j==1 || dp[j-1]>0 && dp[j-1]+money[i]<=total)
                   dp[j]=max(dp[j],dp[j-1]+money[i]);
            }
        }

        int sum=0;
        for(i=1;i<=len;i++)
        {
            if(dp[sum]<dp[i])
                sum=i;
        }
        printf("%.2lf\n",dp[sum]);
    }
    return 0;
}