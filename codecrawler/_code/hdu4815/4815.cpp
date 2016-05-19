typedef  long long LL ;
int  x[48] ;
LL   dp[40008] ;
int  num[40008] ;
LL   cnt[40008] ;

int  main(){
     double p ;
     int  sum , n  , i , j , k  , t ;
     cin>>t ;
     while(t--){
          scanf("%d%lf" , &n , &p) ;
          sum = 0 ;
          for(i = 1 ; i <= n ; i++){
                scanf("%d" , &x[i]) ;
                sum += x[i] ;
          }
          memset(dp , 0 , sizeof(dp)) ;
          dp[0] = 1 ;
          for(i = 1 ; i <= n ; i++){
              for(j = sum ; j >= x[i] ; j--){
                  if(dp[j - x[i]]) dp[j] += dp[j-x[i]] ;
              }
          }
         k = 0 ;
         for(i = 0 ; i <= sum ; i++){
             if(dp[i] == 0)  continue ;
             k++ ;
             num[k] =  i ;
             cnt[k] =  dp[i] ;
         }
         double all = pow(2.0 , n)  , s ;
         int L = 0 , R = sum  , M  , ans  ;
         while(L <= R){
              M = (L + R) >> 1 ;
              s = 0 ;
              for(i = 1 ; i <= k ; i++){
                   if(num[i] > M) break ;
                   s += cnt[i] ;
              }
              if(s >= p * all){
                   ans = M ;
                   R = M-1 ;
              }
              else  L = M+1 ;
         }
         printf("%d\n" , ans) ;
     }
     return 0  ;
}