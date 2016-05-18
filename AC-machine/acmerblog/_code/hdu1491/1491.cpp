# include <stdio.h>


int getdays (int m, int d)
{
    int i, rtn = 0, month [12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30} ;
    for (i = 0 ; i < m ; i++)
        rtn += month[i] ;
    return rtn + d ;
}


int main ()
{
    int T ;
    int days, target, m, d ;
    scanf ("%d", &T) ;
    target = getdays (10, 21) ;
    while (T--)
    {
        scanf ("%d %d", &m, &d) ;
        days = getdays (m, d) ;
        if (days > target) puts ("What a pity, it has passed!") ;
        else if (days == target) puts ("It's today!!") ;
        else printf ("%d\n", target - days) ;
    }
    return 0 ;
}