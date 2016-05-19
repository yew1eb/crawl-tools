# include <stdio.h>


int factorial[15] = {1, 1} ;


int main ()
{
    int i, T, a, b ;
    char ch ;
    for(i = 2 ; i <= 10 ; i++)
        factorial[i] = factorial[i-1] * i ;
    scanf ("%d%*c", &T) ;
    while (T--)
    {
        scanf ("%c %d %d%*c", &ch, &a, &b) ;
        if (ch == 'A') printf ("%d\n", factorial[a] / factorial[a-b]) ;
        else printf ("%d\n", factorial[a] / factorial[b] / factorial[a-b]) ;
    }
    return 0 ;
}