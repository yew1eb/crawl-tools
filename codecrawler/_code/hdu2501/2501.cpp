# include <stdio.h>


int dp[35] = {1, 1} ;


int main ()
{
    int i, T ;
    for (i = 2 ; i<= 30 ; i++)
        dp[i] = dp[i-1] + dp[i-2]*2 ;
    scanf ("%d", &T) ;
    while(~scanf ("%d", &T))
        printf ("%d\n", dp[T]) ;
    return 0 ;
}