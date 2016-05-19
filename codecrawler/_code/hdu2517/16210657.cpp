#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using  namespace std; 
const int inf=6400*6400;
const int N=8;
int sum[10][10];  ///ï¿½ï¿½ï¿½ï¿½(1,1)ï¿½ï¿½ï¿½ï¿½ - (i,j)ï¿½ï¿½ï¿½ï¿½ ï¿½Äºï¿½
double s[10][10][10][10]; /// ï¿½ï¿½ï¿½ÎºÍµï¿½Æ½ï¿½ï¿½
double dp[10][10][10][10][16];
double DFS(int x1,int y1,int x2,int y2,int k){
    if(k==1) return s[x1][y1][x2][y2];
    if(dp[x1][y1][x2][y2][k]!=-1) return dp[x1][y1][x2][y2][k];
    double ret=(double)inf;
    /// ï¿½ï¿½ï¿½Ð¸ï¿½ ï¿½Ö³ï¿½ï¿½ï¿½ï¿½Ó¿ï¿½ (x1,y1)-(i,y2)  \ (i+1,y1)-(x2,y2)
    for(int a=x1; a<x2; a++) {
        ret=min(ret,DFS(x1,y1,a,y2,k-1)+s[a+1][y1][x2][y2]);
        ret=min(ret,DFS(a+1,y1,x2,y2,k-1)+s[x1][y1][a][y2]);
    }
    /// ï¿½ï¿½ï¿½Ð¸ï¿½ ï¿½Ö³ï¿½ï¿½ï¿½ï¿½Ó¿ï¿½ (x1,y1)-(x2,i)  \ (x1,i+1)-(x2,y2)
    for(int b=y1; b<y2; b++) { //ï¿½ï¿½Ö±ï¿½ï¿½ï¿½ï¿½ï¿½Ð¸ï¿½
        ret=min(ret,DFS(x1,y1,x2,b,k-1)+s[x1][b+1][x2][y2]);
        ret=min(ret,DFS(x1,b+1,x2,y2,k-1)+s[x1][y1][x2][b]);
    }
    dp[x1][y1][x2][y2][k]=ret;
    return ret;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<=N;++i) sum[i][0]=sum[0][i]=0;
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j){
                int a; scanf("%d",&a);
                sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a;
            }
        double avr=double(sum[N][N])/n;
        for(int i=1;i<=N;++i)  ///ï¿½ï¿½ï¿½ï¿½(i,k)-(j,t)ï¿½Íµï¿½ Æ½ï¿½ï¿½
            for(int k=1;k<=N;++k)
                for(int j=i;j<=N;++j)
                    for(int t=k;t<=N;++t){
                        double u=(double)(sum[j][t]-sum[j][k-1]-sum[i-1][t]+sum[i-1][k-1]);
                        s[i][k][j][t]=u*u;
                        for(int p=0;p<=16;++p)dp[i][k][j][t][p]=-1;
                    }
        double ans=DFS(1,1,N,N,n);
        printf("%.3lf\n",sqrt(ans/n-avr*avr));
    }
    return 0;
}
