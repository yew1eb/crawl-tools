# include <stdio.h>

int a[20] ;
int ans ;


int gao()
{
    int i, j, n ;
    int cnt = 0 ;
    ans = 0 ;
    while (~scanf ("%d", &n))
    {
        if (n == -1) return 0 ;
        if (n == 0) break ;
        a[cnt++] = n ;
    }
    for (i = 0 ; i < cnt ; i++)
    {
        for (j = 0 ; j < cnt ; j++)
            if (a[j] == a[i]*2) ans++ ;
    }
    return 1 ;
}

int main ()
{
    while (gao())
    {
        printf ("%d\n", ans) ;
    }
    return 0 ;
}