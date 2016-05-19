#define X 1010
#include<iostream>
using namespace std;
double p0[X][X],p1[X][X],p2[X][X];
double dp[X][X];
int main(){
    int i,j,n,m;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%lf%lf%lf",&p0[i][j],&p1[i][j],&p2[i][j]);
        for(i=n;i>0;i--)
            for(j=m;j>0;j--){
                dp[i][j]=p0[i][j]*2+p1[i][j]*(dp[i][j+1]+2)+p2[i][j]*(dp[i+1][j]+2);
                if(p0[i][j]==1)dp[i][j]=0;
                else           dp[i][j]/=1-p0[i][j];
            }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}
            
