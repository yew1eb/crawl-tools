# include <stdio.h>

int dp[] = {1, 1, 2, 3, 5, 9} ;

int main ()
{
    int T, i, n, m, nn, mm, ans ;
    scanf ("%d", &T) ;
    while (T--)
    {
         scanf ("%d%d", &n, &m) ;
        ans = 0 ;
        for (i = 0 ; i <= n && 5*i <= m ; i++)
        {
            mm = m - 5*i ;
            nn = n - i ;
            if (mm >= nn && mm <= 2*nn) ans++ ;
        }
        printf ("%d\n", ans) ;
    }
    return 0 ;
}