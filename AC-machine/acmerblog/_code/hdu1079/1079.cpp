# include <stdio.h>
# include <string.h>

int dp[2200][15][35] ;
int month[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}} ;

int leap(int y){return (y%4==0 && y%100!= 0) || (y%400==0) ;}

int gao(int y, int m, int d)
{
    int yy = y, mm = m, dd = d ;
    if (y > 2001) return 1 ;
    if (y == 2001 && m > 11) return 1 ;
    if (y == 2001 && m == 11 && d > 4) return 1 ;
    if (dp[y][m][d] != -1) return dp[y][m][d] ;

    //next day
    dd = d+1 ;
    if (dd > month[leap(y)][m])
        dd = 1, mm++ ;
    if (mm > 12)
        mm = 1, yy++ ;
    if (gao(yy, mm, dd) == 0) return dp[y][m][d] = 1 ;

    //next month
    dd = d, mm = m+1, yy = y ;
    if (mm > 12) mm = 1, yy++ ;
    if (dd <= month[leap(yy)][mm]) //日期存在 
        if (gao(yy, mm, dd) == 0) return dp[y][m][d] = 1 ;
    return dp[y][m][d] = 0 ;
}

int main ()
{
    int T, yy, mm, dd ;
    memset (dp, -1, sizeof(dp)) ;
    dp[2001][11][4] = 0 ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d %d %d", &yy, &mm, &dd) ;
        puts (gao(yy, mm, dd) ? "YES" : "NO") ;
    }
    return 0 ;
}