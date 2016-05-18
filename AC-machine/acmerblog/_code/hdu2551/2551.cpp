# include <stdio.h>


long long calc(long long x)
{
    long long i, sum = 0 ;
    for (i = 1 ; ; i++)
    {
        sum += i*i*i ;
        if (sum >= x) break ;
    }
    return i ;
}


int main ()
{
    int T, x ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &x) ;
        printf ("%I64d\n", calc(x)) ;
    }
    return 0 ;
}