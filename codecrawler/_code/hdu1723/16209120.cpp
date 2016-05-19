#include<iostream>
#include<cstring>
using namespace std;
int dp[100],n,m;
int main()
{
    while(cin>>n>>m){
        if(!n&&!m) break;
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        for(int i=n;i>0;i--){
            for(int j=i-1;j>0;j--){
                if(i-j<=m) dp[j]+=dp[i];
             }
        }
        cout<<dp[1]<<endl;
    }
}