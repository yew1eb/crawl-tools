# include <stdio.h>
 # include <string.h>
 
 
 int main ()
 {
     int T, i, len ;
     char s1[55], s2[55] ;
     scanf ("%d", &T) ;
     while (T--)
     {
         scanf ("%s%s", s1, s2) ;
         len = strlen(s1) ;
         for (i = 0 ; i < len/2 ; i++) putchar (s1[i]) ;
         for (i = 0 ; s2[i] ; i++) putchar (s2[i]) ;
         for (i = len/2 ; s1[i] ; i++) putchar (s1[i]) ;
         putchar ('\n') ;
     }
     return 0 ;
 }