# include <stdio.h>


int main ()
{
    double vul, d ;
    int i, ans ;
    while (~scanf ("%lf%lf", &vul, &d))
    {
        for (i = 1 ; ; i++)
            if (i*(i+1)/2 >= vul / d) break ;
        ans = (i-1)*i/2 ;
        vul -= ans*d ;
        ans += (int)((vul-1e-9)/d+1) + (i-1) ;
        printf ("%d\n", ans) ;
    }
}