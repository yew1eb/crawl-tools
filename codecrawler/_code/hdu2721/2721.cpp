# include <stdio.h>
 # include <string.h>
 
 
 int vis[70000] ;
 
 
 int main ()
 {
     int a, b, c, s, i, bit ;
     char ch[20] ;
     
     while (~scanf ("%d", &a) && a)
     {
         scanf ("%d%d%d", &b, &c, &s) ;
         memset (vis, 0, sizeof(vis)) ;
         for (i = 0 ; i < 16 ; i++)
             ch[i] = ((s>>(15-i)) & 1) + '0' ;
         while (!vis[s])
         {
             vis[s] = 1 ;
             for (i = 0 ; i < 16 ; i++)
             {
                 bit = ((s>>(15-i)) & 1) ;
                 if (ch[i]-'0' != bit) ch[i] = '?' ;
             }
             s = (((a*s)%c) + (b%c))%c ;
         }
         for (i = 0 ; i < 16 ; i++)
             printf ("%c", ch[i]) ;
         printf ("\n") ;
     }
     return 0 ;
 }