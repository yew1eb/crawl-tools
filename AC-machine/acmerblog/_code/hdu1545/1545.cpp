const int MM = 11111;
#define debug puts("wrong")
typedef __int64 int64;
int N,M;
int64 dp[63][11][11];//j min(0-1) k max(0-1)

void solve() {
    int i,j,k;int64 tmp,t1,t2;
    memset(dp[0],0,sizeof(dp[0]));
    dp[0][M][M]=1;
    for(i=1;i<=N;i++) {
        memset(dp[i],0,sizeof(dp[i]));
        for(j=-M;j<=M;j++) {
            for(k=-M;k<=M;k++) {
                tmp=dp[i-1][j+M][k+M];
                if(tmp==0) continue;
                t1=f_min(j+1,1),t2=f_max(k+1,1);
                if(t1>=(-M) && t2<=M)dp[i][t1+M][t2+M]+=tmp; //0
                t1=f_min(j-1,-1),t2=f_max(k-1,-1);
                if(t1>=(-M) && t2<=M)dp[i][t1+M][t2+M]+=tmp; //1
            }
        }
    }
    int64 ans=0;
    for(i=-M;i<=M;i++) for(j=-M;j<=M;j++) {
        ans+=dp[N][i+M][j+M];
//        printf("%d %d %d\n",i,j,dp[2][i+M][j+M]);
    }
    printf("%I64d\n",ans);
}