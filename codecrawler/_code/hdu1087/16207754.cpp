#include<stdio.h>
#define N 1001
int dp[N];
int value[N];
int n,max;
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF&&n){
        for(i=0;i<n;i++){
            scanf("%d",&value[i]);
        }
        dp[0]=max=value[0];
        for(i=1;i<n;i++){
            dp[i]=value[i];
            for(j=0;j<i;j++){
                if(value[i]>value[j]){
                    if(dp[i]<dp[j]+value[i])
                        dp[i]=dp[j]+value[i];
                }
            }
            if(dp[i]>max)
                max=dp[i];
        }
        printf("%d\n",max);
    }
    return 0;
}