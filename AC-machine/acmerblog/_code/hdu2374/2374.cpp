# include <stdio.h>


long long num[60] ;


int main ()
{
    int i, j, n ;
    long long rtn ;
    while (~scanf ("%d", &n),n)
    {
        rtn = 0 ;
        num[n] = 0 ;
        for(i = 0 ; i < n ; i++)
            scanf ("%I64d", &num[i]) ;
        for (i = n-1 ; i>= 0 ; i--)
        {
            rtn += num[i] ;
            for (j = i-1 ; j>= 0; j--)
                num[j] += num[i] ;
        }
        printf ("%I64d\n", rtn) ;
    }
    return 0 ;
}