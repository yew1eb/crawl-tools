# include <stdio.h>
 
 
int main ()
{
    long long n ;
    scanf ("%I64d", &n) ;
     while (~scanf ("%I64d", &n))
     {
         n = n*n % 10000 ;
         printf ("%I64d\n", n) ;
     }
    return 0 ;
}