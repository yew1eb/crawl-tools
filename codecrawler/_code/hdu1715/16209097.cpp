#include<iostream>
#include<stdio.h>
#include<string.h>
#define maxe 1004
using namespace std;
int a[1005][1005];

int main()
{
    int t;
    scanf("%d",&t);
    int i,j;
    memset(a,0,sizeof(a));
    a[1][1]=1;
    a[2][1]=1;
    int s;
    int plus=0;
    for(i=1;i<=997;i++)
    {
       for(j=1;j<=maxe;j++)
       {
          s=a[i+1][j]+a[i][j]+plus;
          a[i+2][j]=s%10;
          plus=s/10;
          //if(plus==0 && s==0)break;ä¹æä»¥å»ææ¯å ä¸ºå­å¨è¿ç§æåµèä¸è½è·³åºçæåµï¼
          //ä¾å¦10+10=20ï¼å¦ææç§è¿ç§ç®æ³å°± 
       }
    }
    while(t--)
    {
       int p;
       scanf("%d",&p);
       for(i=maxe;i>=1;i--) if(a[p][i])break;
       for(;i>=1;i--)
          printf("%d",a[p][i]);
       printf("\n");
    }
    
    system("pause");
    return 0;
}
