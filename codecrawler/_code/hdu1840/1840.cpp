# include <stdio.h>
 
 
 void work()
 {
     int a, b, c, delta ;
     scanf ("%d%d%d", &a, &b, &c) ;
     if (a==0)
         if (b == 0)
             if (c == 0) puts ("INF") ;
             else puts ("0") ;
         else puts ("1") ;
     else
         if (b*b > 4*a*c) puts ("2") ;
         else if (b*b == 4*a*c) puts ("1") ;
         else puts ("0") ;
 }
 
 
 int main ()
 {
     int T ;
     scanf ("%d", &T) ;
     while (T--)
         work() ;
     return 0 ;
 }