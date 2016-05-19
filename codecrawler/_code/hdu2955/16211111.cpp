#include<stdio.h>
#include<string.h>
double dp[10000];
int mm[1000];   //é±
double pp[1000];// æ¦ç
double max(double a, double b)
{
    return a>b? a:b;
}
int main()
{
    int cas,n,i,j,sum;
    double p;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%lf %d",&p,&n);
        for(i=0,sum=0; i<n; i++)
        {
            scanf("%d %lf",&mm[i],&pp[i]);
            sum += mm[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(i=0; i<n; i++)
            for(j=sum; j>=mm[i]; j--)
                dp[j] = max(dp[j],dp[j-mm[i]] * (1-pp[i]));
          for(i=sum; i>=0; i--)
          {
              if(dp[i]>=(1-p))
              {
                  printf("%d\n",i);
                  break;
              }
          }
    }
    return 0;
}