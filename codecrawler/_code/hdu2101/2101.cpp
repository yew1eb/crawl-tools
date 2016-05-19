# include <stdio.h>


int main ()
{
    int a, b ;
    while (~scanf ("%d%d", &a, &b))
        puts (((a+b)%86) ? "no" : "yes") ;
    return 0 ;
}