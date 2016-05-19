# include <stdio.h>
 
 
 int dp[20010] = {0,1} ;
 
 
 int IsPrime(int x)
 {
     int i ;
     for (i = 2 ; i*i <= x ; i++)
         if (x %i == 0) return 0 ;
     return 1  ;
 }
 
 
 int main ()
 {
     int i, j, ans ;
     for (i = 2 ; i <= 20000 ; i++)if (IsPrime(i))
     {
         for (j = i ; j <= 20000 ; j+=i)
             dp[j] = i ;
     }
     while(~scanf ("%d", &j)){
     ans = 0 ;
     while (j--)
     {
         scanf ("%d", &i) ;
         if (dp[i] > dp[ans]) ans = i ;
     }
     printf ("%d\n", ans) ;
     }
     return 0 ;
 }