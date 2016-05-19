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

const int MAX=40+10;
int dp[MAX][MAX];
bool mark[MAX][MAX];

int main(){
    int n,m,x1,y1,x2,y2;
    while(cin>>n>>m){
        memset(mark,false,sizeof mark);
        cin>>x1>>y1>>x2>>y2;
        dp[0][1]=1;
        mark[y1+1][x1+1]=mark[y2+1][x2+1]=true;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                if(mark[i][j] && mark[i-1][j])dp[i][j]-=dp[i-1][j];
                if(mark[i][j] && mark[i][j-1])dp[i][j]-=dp[i][j-1];
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}