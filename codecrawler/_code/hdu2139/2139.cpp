# include <stdio.h>


int main ()
{
    long long n, p ;
    while (~scanf ("%I64d", &n))
    {
        p = (n-1) / 2 ;
        printf ("%I64d\n", (4*p*p*p+12*p*p+11*p+3)/3) ;
    }
    return 0 ;
}