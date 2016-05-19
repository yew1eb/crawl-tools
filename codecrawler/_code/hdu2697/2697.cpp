/*
 DP
 dp[i][j]:从前i个中挑出某些且cost不超过j的最大val。
 */
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<algorithm>
 #include<iostream>
 #include<queue>
 #include<map>
 #include<stack>
 #include<set>
 #include<math.h>
 using namespace std;
 typedef long long int64;
 //typedef __int64 int64;
 typedef pair<int64,int64> PII;
 #define MP(a,b) make_pair((a),(b)) 
 const int maxn = 105;
 const int inf = 0x7fffffff;
 const double pi=acos(-1.0);
 const double eps = 1e-8;
 int dp[ maxn ][ maxn ];
 int a[ maxn ];
 int main(){
     int T;
     scanf("%d",&T);
     while( T-- ){
         int n,sum;
         scanf("%d%d",&n,&sum);
         int MinCost = inf;
         for( int i=1;i<=n;i++ ){
             scanf("%d",&a[i]);
             if( a[i]<MinCost ) MinCost = a[i];
         }
         if( MinCost>sum ){
             printf("0\n");
             continue;
         }
         if( MinCost==sum ){
             puts("1");
             continue;
         }
         int ans = 0;
         memset( dp,0,sizeof( dp ) );
         for( int i=1;i<=n;i++ ){
             for( int j=0;j<=sum;j++ ){
                 int cnt = 0;
                 for( int k=1;k<=i;k++ ){
                     cnt += a[ i+1-k ];
                     if( cnt>j ) break;
                     dp[i][j] = max( dp[i][j],dp[i-k][j-cnt]+k*k );
                 }
                 dp[i][j] = max( dp[i][j],dp[i-1][j] );
                 ans = max( ans,dp[i][j] );
             }
         }
         printf("%d\n",ans);
     }
     return 0;
 }