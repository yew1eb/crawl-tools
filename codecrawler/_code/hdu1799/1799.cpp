# include <stdio.h>

int dp[2010][2010] ;


void init()
{
    int i, j ;
    dp[0][0] = 1 ;
    for (i = 1 ; i <= 2000 ; i++)
    {
        dp[i][0] = 1 ;
        for (j = 1 ; j <= i ; j++)
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 1007 ;
    }
}


int main ()
{
    int T, n, m ;
    init() ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d%d", &m, &n) ;
        printf ("%d\n", dp[n][m]) ;
    }
    return 0 ;
}