#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define N 1005
#define INF 1<<30
#include<cmath>
using namespace std;
int dis[N][N],dp[N][N];
struct node{
    int t,s;
}a[N];
int cal(int i,int j){
    int tmp1=a[i].s;
    int tmp2=a[j].s;
    if(tmp1>tmp2)
    swap(tmp1,tmp2);
    return abs(a[i].t-a[j].t)*400+min(tmp2-tmp1,tmp1-tmp2+360);
}
int main()
{
    int  ans;
    int n,i,j,k,T;
    a[1].t=a[1].s=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=n*10;
        n++;
        for(i=2;i<=n;i++){
            scanf("%d%d",&a[i].t,&a[i].s);
        }
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                dis[j][i]=dis[i][j]=cal(i,j);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
            dp[i][j]=INF;
        }
        dp[2][1]=dp[1][2]=dis[1][2];
        for(i=1;i<=n;i++){
            for(k=1;k<i;k++){
                dp[i+1][i]=dp[i][i+1]=min(dp[i][i+1],dp[i][k]+dis[k][i+1]);
            }
            for(j=i+2;j<=n;j++){
                dp[j][i]=dp[i][j]=dp[i][j-1]+dis[j-1][j];
            }
        }
        ans+=dp[n-1][n]+dis[n-1][n];
        printf("%d\n",ans);
    }
    return 0;
}
