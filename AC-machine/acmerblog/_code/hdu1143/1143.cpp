# include <stdio.h>


int dp[35] = {1, 0, 3, 0} ;


int main ()
{
    int i, n ;
    for (i = 4 ; i<= 30 ; i+= 2)
        dp[i] = 4*dp[i-2] - dp[i-4] ;

    while (~scanf ("%d", &n))
    {
        if (n < 0) break ;
        printf ("%d\n", dp[n]) ;
    }
    return 0 ;
}