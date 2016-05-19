#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 100000000007 
using namespace std;
int t;
double p[10],dp[100][20],a[20];
int main()
{
    cin>>t;
    while(t--){
        for(int i=1;i<=6;i++) cin>>p[i];
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1;i<=6;i++) dp[i][1]=p[i];
        for(int i=2;i<=10;i++){
            for(int j=0;j<61;j++){
                for(int k=1;k<=6;k++)
                  if(j-k>=0) dp[j][i]+=dp[j-k][i-1]*p[k];
            }
        }
        for(int i=10;i>0;i--)     a[0]+=dp[5][i];  printf("5: %.1lf%%\n",a[0]*100);
        for(int i=10;i>0;i--)      a[1]+=dp[12][i]; printf("12: %.1lf%%\n",a[1]*100);
        for(int i=10;i>0;i--)     a[2]+=dp[22][i]; printf("22: %.1lf%%\n",a[2]*100);    
        for(int i=10;i>0;i--)    a[3]+=dp[29][i]; printf("29: %.1lf%%\n",a[3]*100);
        for(int i=10;i>0;i--)       a[4]+=dp[33][i]; printf("33: %.1lf%%\n",a[4]*100);
        for(int i=10;i>0;i--)    a[5]+=dp[38][i]; printf("38: %.1lf%%\n",a[5]*100);
        for(int i=10;i>0;i--)    a[6]+=dp[42][i]; printf("42: %.1lf%%\n",a[6]*100);
        for(int i=10;i>0;i--)    a[7]+=dp[46][i]; printf("46: %.1lf%%\n",a[7]*100);
        for(int i=10;i>0;i--)    a[8]+=dp[50][i]; printf("50: %.1lf%%\n",a[8]*100);
        for(int i=10;i>0;i--)    a[9]+=dp[55][i]; printf("55: %.1lf%%\n",a[9]*100);
        if(t) cout<<endl;
    }
}