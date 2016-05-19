#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define inf 1<<20
#define N 1005
using namespace std;
char s1[N],s2[N];
int dp[N][10][10];
int main(){
    while(scanf("%s%s",s1,s2)!=EOF){
        int l=strlen(s1);
        for(int i=0;i<=l;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) dp[i][j][k]=inf;
        dp[0][0][0]=0;
        for(int i=0;i<l;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<10;k++){
                    int t=(s2[i]-s1[i]-j+20)%10;
                    for(int a=0;a<=t;a++)
                        for(int b=0;b<=a;b++)
                            dp[i+1][(k+a)%10][b]=min(dp[i+1][(k+a)%10][b],dp[i][j][k]+t);
                    t=(10-t)%10;
                    for(int a=0;a<=t;a++)
                        for(int b=0;b<=a;b++)
                            dp[i+1][(k-a+10)%10][(10-b)%10]=min(dp[i+1][(k-a+10)%10][(10-b)%10],dp[i][j][k]+t);
                }
        printf("%d\n",dp[l][0][0]);
    }
    return 0;
}
