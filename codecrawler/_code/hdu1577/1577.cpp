# include <stdio.h>


int abs(int n){return n<0?-n:n;}
int gcd(int a, int b){return a%b==0?b:gcd(b,a%b);}

int main ()
{
    int l, px, py, sx, sy ;
    while (~scanf ("%d", &l), l)
    {
        scanf ("%d%d%d%d", &sx, &sy, &px, &py) ;
        if (abs(px)>l || abs(py) > l)
        {
            puts ("Out Of Range") ;
            continue ;
        }
        px = abs(px-sx), py = abs(py-sy) ;
        if (px == 0) puts (py <= 1 ? "Yes" : "No") ;
        else if (py == 0) puts (px <= 1 ? "Yes": "No") ;
        else puts (gcd(px, py)==1 ? "Yes" : "No") ;
    }
    return 0 ;
}