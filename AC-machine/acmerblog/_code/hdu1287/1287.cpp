# include <stdio.h>


int num[10010] ;
int n ;

int test (int x)
{
    int i ;
    for (i = 0 ; i < n ; i++)
        if ((num[i]^x) < 65 || (num[i]^x) >= (65+26)) return 0 ;
    return 1 ;
}


int main ()
{
    int i, j ;
    while (~scanf ("%d", &n))
    {
        for (i = 0 ; i < n ;i++)
            scanf ("%d", num+i) ;
        for (i = 65 ; i < 65+26 ; i++)
            if (test(i)) break ;
        for (j = 0 ; j < n ; j++)
            putchar (num[j] ^ i) ;
        printf ("\n") ;
    }
    return 0 ;
}