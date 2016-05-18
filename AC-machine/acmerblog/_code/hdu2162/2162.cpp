# include <stdio.h>


int main ()
{
    int n, sum, num ;
    int nCase = 1 ;
    while (~scanf ("%d", &n) && n > 0)
    {
        sum = 0 ;
        while (n--)
        {
            scanf ("%d", &num) ;
            sum += num ;
        }
        printf ("Sum of #%d is %d\n", nCase++, sum) ;
    }
    return 0 ;
}