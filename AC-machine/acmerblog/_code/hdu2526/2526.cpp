# include <stdio.h>


int dp[1010][210] ;
int flag[200], m ;
char str[210] ;


int get(int a, int b, int c)
{
    return flag[a*100+b*10+c] ;
}


void output()
{
    int i, j, len = 0 ;
    for (i = 0 ; str[i]  ;i++)
    {
        dp[0][i] = str[i] - '0' ;
        len++ ;
    }
    for (i = 1 ; i < m ; i++)
    {
        dp[i][0] = get (0, dp[i-1][0], dp[i-1][1]) ;
        dp[i][len-1] = get(dp[i-1][len-2], dp[i-1][len-1], 0) ;
        for (j = 1 ; j < len-1 ; j++)
            dp[i][j] = get(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) ;
    }
    for (i = 0 ; i < m ; i++)
    {
        for (j = 0 ; j < len ; j++)
            printf ("%d", dp[i][j]) ;
        printf ("\n") ;
    }
}
int main ()
{
    int T, i, a, b ;
    scanf ("%d%*c", &T) ;
    while (T--)
    {
        scanf ("%d%*c", &m) ;
        for (i = 0 ; i < 8 ; i++)
        {
            scanf ("%d %d%*c", &a, &b) ;
            flag[a] = b ;
        }
        scanf ("%s%*c", str) ;
        output () ;
    }
    return 0 ;
}