# include <stdio.h>


int n ;
char grid[15][15] ;


int ABS(int n){return n<0?-n:n;}
void r(char a[15][15], char b[15][15])
{
    int i, j ;
    char c[15][15] ;
    for (i = 0 ; i< n ; i++)
    {
        for (j = 0 ; j < n ; j++)
            c[j][n-i-1] = grid[i][j] ;
    }

    for (i = 0 ; i < n ; i++)
        for (b[i][n] = '\0', j = 0 ; j < n ; j++)
            b[i][j] = c[i][j] ;
}


int main ()
{
    int m, i, j ;
    while (~scanf ("%d %d%*c", &n, &m))
    {
        if (m > 0) m %= 4 ;
        else m = (4 - (ABS(m)%4))%4 ;
        for(i = 0 ; i < n ; i++)
            gets(grid[i]) ;
        for (i = 0 ; i < m ; i++)
            r(grid, grid) ;
        for (i = 0 ; i < n ; i++)
            puts (grid[i]) ;
    }
    return 0 ;
}