# include <stdio.h>
 # include <string.h>
 
 
 char str[110] ;
 
 int main ()
 {
     int i, cnt, len ;
     
     
     while (gets (str))
     {
         if (strcmp(str, "#") == 0) break ;
         len = strlen(str) ;
         for(i = 0, cnt = 0 ; i < len-1 ; i++)
             if (str[i] == '1') cnt++ ;
         if ((cnt%2 == 0 && str[len-1] == 'o') ||
             (cnt%2 == 1 && str[len-1] == 'e'))
             str[len-1] = '1' ;
         else str[len-1] = '0' ;
         puts (str) ;
     }
     return 0 ;
 }