#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100+10;
char a[MAX],b[MAX];
int dp[MAX][MAX],per[MAX][MAX];

void Printf(int i,int j){
    if(i+j == 0)return;
    if(per[i][j] == 1)Printf(i-1,j),printf("%c",a[i]);
    else if(per[i][j] == 2)Printf(i-1,j-1),printf("%c",a[i]);
    else Printf(i,j-1),printf("%c",b[j]);
}

int main(){
    while(cin>>a+1>>b+1){
        int maxl=0,la=strlen(a+1),lb=strlen(b+1);
        memset(dp,0,sizeof dp);
        memset(per,0,sizeof per);
        for(int i=1;i<=la;++i)per[i][0]=1;
        for(int i=1;i<=lb;++i)per[0][i]=3;
        for(int i=1;a[i] != '\0';++i){
            for(int j=1;b[j] != '\0';++j){
                if(a[i] == b[j])dp[i][j]=dp[i-1][j-1]+1,per[i][j]=2;
                else if(dp[i-1][j]>dp[i][j-1])dp[i][j]=dp[i-1][j],per[i][j]=1;
                else dp[i][j]=dp[i][j-1],per[i][j]=3;
            }
        }
        Printf(la,lb);
        printf("\n"); 
    }
    return 0;
}