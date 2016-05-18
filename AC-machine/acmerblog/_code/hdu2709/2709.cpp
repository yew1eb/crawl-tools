# include <stdio.h>
 
 
 int tab[1000010] = {1, 1, 2} ;
 
 
 int main ()
 {
     int i ;
     for (i = 3 ; i <= 1000000 ; i++)
         tab[i] = (tab[i-2] + tab[i/2] ) % 1000000000 ;
     while (~scanf ("%d", &i))
         printf ("%d\n", tab[i]) ;
     return 0 ;
 }