# include <stdio.h>
# include <stdlib.h>

int a[610] ;
int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a ;
}


int main ()
{
    int i, L, n ;
    while (~scanf ("%d%d", &L, &n))
    {
        for (i = 1 ; i <= n ; i++)    
            scanf ("%d", a+i) ;
        qsort(a+1, n, 4, cmp) ;
        for (i = 1 ; i <= n ;i++)
        {
            a[i] += a[i-1] ;
            if (a[i] >= L)
                break ;
        }
        if (i < n+1 && a[i] >=L) printf ("%d\n", i) ;
        else puts ("impossible") ;
    }
}