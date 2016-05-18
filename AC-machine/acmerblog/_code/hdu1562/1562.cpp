# include <stdio.h>


int main ()
{
    int T, a, b, c, i ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d%d%d", &a, &b, &c) ;
        for (i = 1000 ;  i<= 9999 ; i++)
            if (i%a == 0 && (i+1)%b == 0 && (i+2)%c==0) break ;
        if (i == 10000) puts ("Impossible") ;
        else printf ("%d\n", i) ;
    }
    return 0 ;
}