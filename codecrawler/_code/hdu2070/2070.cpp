# include <stdio.h>
# include <math.h>


long long dp[55] = {0, 1} ;


int main ()
{
    int i, n ;
    for (i = 2 ; i<= 50 ; i++)
        dp[i] = dp[i-1]+dp[i-2] ;

    while (~scanf ("%d", &n))
    {
        if (n < 0) break ;
        printf ("%I64d\n", dp[n]) ;
    }
}