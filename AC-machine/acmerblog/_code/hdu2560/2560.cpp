# include <stdio.h>


int main ()
{
    int T, n, m, i, num, sum ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d%d", &n, &m) ;
        sum = 0 ;
        for (i = 0 ; i < n*m ; i++)
        {
            scanf ("%d", &num) ;
            sum += num ;
        }
        printf ("%d\n", sum) ;
    }
    return 0 ;
}