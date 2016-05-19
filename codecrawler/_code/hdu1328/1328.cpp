# include <stdio.h>


int main ()
{
    int T, i, nCase = 1 ;
    char str[55] ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%s", str) ;
        for(i = 0 ; str[i] ; i++)
            str[i] = (str[i]-'A'+1)%26+'A' ;
        printf ("String #%d\n", nCase++) ;
        puts (str) ;
        putchar ('\n') ;
    }
    return 0 ;
}