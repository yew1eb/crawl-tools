# include <stdio.h>
 
 
 long long dp[45] = {3,3} ;
 
 
 int main ()
 {
     int T, n, i ;
     for (i = 2 ; i <= 40 ; i++)
         dp[i] = 2*dp[i-1]+dp[i-2] ;
     scanf ("%d", &T) ;
     while (T--)
     {
         scanf ("%d", &n) ;
         printf ("%I64d\n", dp[n]) ;
     }
     return 0 ;
 }