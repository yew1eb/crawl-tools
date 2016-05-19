# include <stdio.h>


int a[1010] ;


int main ()
{
    int T, n, pos, i, ans ;
    scanf("%d", &T) ;
    while (T--)
    {
        scanf ("%d%d", &n, &pos) ;
        for (i = 1; i <= n ; i++)
            scanf ("%d", &a[i]) ;
        ans = 0 ;
        for (i = 1 ; i <= n ; i++)
            if (a[i] > a[pos]) ans++ ;
        printf ("%d\n", ans) ;
    }
    return 0 ;
}