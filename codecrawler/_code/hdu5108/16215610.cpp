#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n,i,ans,cnt;
    
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        ans=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)//æ¯æ¬¡å»é¤è´¨å æ° 
            {
                while(n%i==0)
                    n/=i;    
                cnt=i;//ä¿å­æå¤§çè´¨å æ° 
            }    
        }
        if(n>1)//è¥ä¸æ¯1ï¼åå©ä½nä¸ºè´¨æ° ï¼å¦åè¢«å®å¨åè§£ï¼é¤ 
            cnt=n;
        printf("%d\n",ans/cnt);
    }     
    return 0;
}    