#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100+10;
int dp[MAX*MAX][15];//è¡¨ç¤ºè¡¨ç¤ºåiæ®µå©ä½jæ®µè½éçæå°æ¶é´
int s[MAX*MAX][2];

int main(){
    int L,N;
    while(cin>>L>>N){
        for(int i=1;i<=L;++i)cin>>s[i][0];
        for(int i=1;i<=L;++i)cin>>s[i][1];
        s[0][0]=s[L][0],s[0][1]=s[L][1];
        for(int i=L+1;i<=L*N;++i)s[i][0]=s[i%L][0],s[i][1]=s[i%L][1];
        for(int i=1;i<15;++i)dp[0][i]=INF;
        for(int i=1;i<=L*N;++i){
            for(int j=0;j<15;++j){
                if(j == 0)dp[i][j]=dp[i-1][5]+s[i][1];
                else if(j<10)dp[i][j]=min(dp[i-1][j-1]+s[i][0],dp[i-1][j+5]+s[i][1]);
                else if(j>10)dp[i][j]=dp[i-1][j-1]+s[i][0];
                if(j == 10)dp[i][j]=min(dp[i-1][j-1]+s[i][0],dp[i-1][14]+s[i][0]);
            } 
        }
        int sum=INF;
        for(int i=0;i<15;++i){
            sum=min(sum,dp[L*N][i]);
        }
        cout<<sum<<endl;
    } 
    return 0;
} 