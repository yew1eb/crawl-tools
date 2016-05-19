#include<stdio.h>
#include<string.h.>
#define MAX 100001
int pie[MAX][12];
int dp[MAX][12];
int n;
int main()
{
    int i,j,time,location,maxtime,mid,left,right;
    while(scanf("%d",&n)!=EOF&&n){
        memset(pie,0,sizeof(pie));
        memset(dp,0,sizeof(dp));
        maxtime=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&location,&time);
            pie[time][location+1]++;
            if(time>maxtime)
                maxtime=time;
        }
        for(i=1;i<=11;i++)
            dp[maxtime][i]=pie[maxtime][i];
        for(i=maxtime-1;i>=0;i--){
            for(j=1;j<=11;j++){
                left=dp[i+1][j-1]+pie[i][j];
                mid=dp[i+1][j]+pie[i][j];
                right=dp[i+1][j+1]+pie[i][j];
                dp[i][j]=(left>mid)?left:mid;
                dp[i][j]=(dp[i][j]>right)?dp[i][j]:right;
            }
        }
        printf("%d\n",dp[0][6]);
    }
    return 0;
}