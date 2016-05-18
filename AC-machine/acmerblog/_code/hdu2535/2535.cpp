# include <stdio.h>
# include <stdlib.h>


int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*) b ;
}


int main ()
{
    int n, i, sum ;
    int a[110] ;
    while (~scanf ("%d", &n) && n)
    {
        for (i = 0 ; i < n ; i++)
            scanf ("%d", a+i) ;
        qsort (a, n, 4, cmp) ;
        sum = 0 ;
        for (i = 0 ; i < (n/2 + 1) ; i++)
            sum += a[i]/2 + 1;
        printf ("%d\n", sum) ;
    }
    
    return 0 ;
}