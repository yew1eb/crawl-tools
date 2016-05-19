# include <stdio.h>


double point(double p)
{
    if (p >= 90) return 4 ;
    if (p >= 80) return 3 ;
    if (p >= 70) return 2 ;
    if (p >= 60) return 1 ;
    return 0 ;
}


int main ()
{
    int n ;
    double s, p ;
    double a, g ;
    while (~scanf ("%d", &n))
    {
        a = g = 0 ;
        while (n--)
        {
            scanf ("%lf%lf", &s, &p) ;
            if (p == -1) continue ;
            a += s ;
            g += s * (point(p)) ;
        }
        if (a == 0) puts ("-1") ;
        else printf ("%.2lf\n", g/a) ;
    }
    return 0 ;
}