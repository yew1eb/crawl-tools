# include <stdio.h>
 # include <string.h>
 
 
 char str[100] ;
 char t[] = " !$%()*" ;
 int p[] = {0x20, 0x21, 0x24, 0x25, 0x28, 0x29, 0x2a} ;
 
 
 int main ()
 {
     int i, j ;
     while (gets (str))
     {
         if (!strcmp(str, "#")) break ;
         for (i = 0 ; str[i] ; i++)
         {
             for (j = 0 ; j < 7 ; j++) if (str[i] == t[j])
             {
                 printf ("%%%x", p[j]) ;
                 break ;
             }
             if (j >= 7) printf ("%c", str[i]) ;
         }
         puts ("") ;
     }
     return 0 ;
 }