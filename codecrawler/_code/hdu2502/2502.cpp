# include <stdio.h>
# include <stdlib.h>


int dp[25] = {0, 1} ;


int main ()
{
    int i ;
    for (i = 2 ; i <= 20 ; i++)
        dp[i] = dp[i-1] * 2 + (1 << (i-1)) ;
    scanf ("%d", &i) ;
    while (~scanf ("%d", &i))
    {
        printf ("%d\n", dp[i-1] + (1 << (i-1))) ;
    }
    return 0 ;
}