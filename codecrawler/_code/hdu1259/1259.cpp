# include <stdio.h>


int main ()
{
    int  i, T, m, a, b, t ;
    int tab[10] ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &m) ;
        for (i = 1 ; i<= 7 ; i++)
            tab[i] = i ;
        while (m--)
        {
            scanf ("%d%d", &a, &b) ;
            t = tab[a], tab[a] = tab[b], tab[b] = t ;
        }
        for (i = 1 ; i <= 7 ; i++)
            if (tab[i] == 2) printf ("%d\n", i) ;
    }
    return 0 ;
}