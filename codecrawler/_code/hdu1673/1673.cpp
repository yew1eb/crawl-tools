# include <stdio.h>
 
 
 int main ()
 {
     int T, n, num ;
     int max, min ;
     scanf ("%d", &T) ;
     while (T--)
     {
         scanf ("%d", &n) ;
         max = -1, min = 1000 ;
         while (n--)
         {
             scanf ("%d", &num) ;
             if (num > max) max = num ;
             if (num < min) min = num ;
         }
         printf ("%d\n", (max-min)*2) ;
     }
     
     return 0 ;
 }