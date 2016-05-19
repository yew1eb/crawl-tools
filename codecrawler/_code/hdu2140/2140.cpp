# include <stdio.h>


char tab[300] ;
char str[10010] ;


int main ()
{
    int i ;
    char s1[] = "bqtmicael", s2[] = " ,!leacim" ;

    for (i = 0 ; i < 9 ; i++)
        tab[s1[i]] = s2[i] ;
    while (gets (str))
    {
        for (i = 0 ; str[i] ; i++)
        {
            if (tab[str[i]] == 0) putchar (str[i]) ;
            else putchar (tab[str[i]]) ;
        }
        printf ("\n") ;
    }
}