# include <stdio.h>
# include <String.h>


int dp[15][15] ;


void gao(int n)
{
    int i, tab[4][2] = {0, 1, 1, 0, 0 , -1, -1, 0} ;
    int d = 0, x, y ;
    memset (dp, 0, sizeof(dp)) ;
    dp[1][1] = 1 ;
    x = 1, y = 2 ;
    for (i = 2 ; i <= (n-1)*4 ; i++)
    {
        dp[x][y] = i ;
        if ((i-1)%(n-1)==0) d++ ;
        x += tab[d][0] ;
        y += tab[d][1] ;
    }
}


void output(int n)
{
    int i, j ;
    for (i = 1 ; i <= n ; i++)
    {
        for (j = 1 ; j<= n ; j++)
        {
            if (dp[i][j] == 0) printf ("") ;
            else printf ("%3d", dp[i][j]) ;
        }
        printf ("\n") ;
    }
}



int main ()
{
    int n ;
    while (~scanf ("%d", &n))
    {
        gao(n) ;
        output(n) ;
    }
    return 0 ;
}