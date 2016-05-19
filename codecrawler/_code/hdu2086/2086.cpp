# include <stdio.h>
# include <string.h>


typedef struct NODE{
    double a0, a1 ;
    double c ;
}NODE ;


NODE node[3010] ;
double c[3010] ;
int n ;


double calc(double a, double b)
{
    int i ;
    memset(node, 0, sizeof(node)) ;
    node[0].a0 = node[1].a1 = 1 ;
    for (i = 2 ; i <= n+1 ; i++)
    {
        node[i].a0 = 2*node[i-1].a0 - node[i-2].a0 ;
        node[i].a1 = 2*node[i-1].a1 - node[i-2].a1 ;
        node[i].c = 2 * node[i-1].c - node[i-2].c + 2*c[i-1] ;
    }
    return (b - a*node[n+1].a0 - node[n+1].c)/node[n+1].a1 ;
}


int main ()
{
    int i ;
    double a, b ;
    while (~scanf ("%d", &n))
    {
        scanf ("%lf%lf", &a, &b) ;
        for (i = 1 ; i<= n ; i++)
            scanf ("%lf", &c[i]) ;
        printf ("%.2lf\n", calc(a,b)) ;
    }
    return 0 ;
}