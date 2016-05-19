#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 55;
int row[15];
int col[15];
int dp[1<<12][15];

int minn(int x,int y){
    if (x<y) return x;
    else return y;
}

int dist(int x,int y){
    return abs(row[x]-row[y])+abs(col[x]-col[y]);
}

int main(){
    int n,m;
    while (cin>>n>>m){
        memset(dp,INF,sizeof(dp));
        int data;
        int cnt = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                scanf("%d",&data);
                if (data||(i==0&&j==0)){
                    row[cnt] = i;
                    col[cnt] = j;
                    cnt++;
                }
            }

        dp[0][0] = 0;
        int SMAX = (1<<cnt);
        for (int i=0;i<SMAX;i++){
            for (int j=0;j<cnt;j++)
            if (dp[i][j]<INF){
                for(int k=0;k<cnt;k++)
                if ((i&(1<<k))==0){
                    dp[i|1<<k][k] = minn(dp[i|1<<k][k],dp[i][j]+dist(j,k));
                }
            }
        }

        printf("%d\n",dp[SMAX-1][0]);

    }

    return 0;
}