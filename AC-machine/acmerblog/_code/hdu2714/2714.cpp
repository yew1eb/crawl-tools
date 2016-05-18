# include <stdio.h>
 
 
 int main ()
 {
     char str[20] ;
     int sum, i, pos ;
     while (gets(str))
     {
         sum = 0 ;
         for (i = 0 ; str[i] ; i++)
         {
             if (str[i] == '?') pos = i ;
             else if (str[i] == 'X') sum += 10 ;
             else sum += (10-i) * (str[i]-'0') ;
         }
         if (pos == 9)
         {
             if ((sum+10)%11==0) puts ("X") ;
             else{
                 for (i = 0 ; i <= 9 ; i++){
                     if ((sum + i)%11==0){ printf ("%d\n", i) ;
                     break ;}
                 }
             }
         }
         else
         {
             for (i =0 ; i <= 9 ; i++)
             {
                 if ((sum + (10-pos)*i)%11 == 0)
                 {
                     printf("%d\n", i) ;
                     break ;
                 }
             }
             if (i >=10) puts ("-1") ;
         }
     }
     return 0 ;
 }