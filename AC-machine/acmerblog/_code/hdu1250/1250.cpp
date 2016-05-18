# include <stdio.h>


int a[6][2100] ;
int buff[2100] ;


void add(int x[], int y[])
{
    int i, *p, *q, cc = 0 ;
    if (x[0] < y[0]) p = x, q  = y ;
    else p = y, q = x ;
    
    for (i = 1 ; i <= q[0] ; i++)
    {
        if (i <= p[0]) buff[i] = p[i] ;
        else buff[i] = 0 ;
        buff[i] += q[i] + cc ;
        cc = buff[i] / 10 ;
        buff[i] %= 10 ;
    }
    if (cc != 0) buff[i++] = cc ;
    buff[0] = i-1 ;
    for (i = 0 ; i <= buff[0] ; i++)
        x[i] = buff[i] ;
}


void cpy(int a[], int b[])
{
    int i ;
    for (i = 0 ; i <= b[0] ; i++)
        a[i] = b[i] ;
}


void output (int a[])
{
    int i ;
    for (i = a[0]  ; i>= 1 ; i--)
        printf ("%d", a[i]) ;
    printf ("\n") ;
}


int main ()
{
    int n, i, j ;
    while (~scanf ("%d", &n))
    {
        if (n <= 4){
            puts ("1") ;
            continue ;
        }
        for (i = 0 ; i < 4 ; i++)
            a[i][0] = a[i][1] = 1 ;
        for (i = 0 ; i < n -4 ; i++)
        {
            a[4][0] = 1, a[4][1] = 0 ;
            for (j = 0 ; j < 4 ; j++)
                add(a[4], a[j]) ;
            for (j = 1 ; j < 5 ; j++)
                cpy (a[j-1], a[j]) ;
        }
        output (a[4]) ;
    }
    return 0 ;
}