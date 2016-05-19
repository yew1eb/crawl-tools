# include <stdio.h>
 # include <math.h>
 
 
 int calc(long long n)
 {
     double ans = n * log10(n) ;
     ans -= (long long)ans ;
     return (int)pow(10,ans) ;
 }
 
 
 int main ()
 {
     int T, n ;
     scanf("%d",&T);
     while(T--)
     {
         scanf("%d",&n) ;
         printf("%d\n",calc(n)) ;
     }
     return 0 ;
 }