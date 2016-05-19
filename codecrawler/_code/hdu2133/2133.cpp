# include <stdio.h>


int mon[2][13] = {    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;


int isleap(int y){return (y%4==0&&y%100!=0)||(y%400==0);}


int illegal(int y, int m, int d)
{
    if (m*d == 0) return 1 ;
    if (d > mon[isleap(y)][m]) return 1 ;
    return 0 ;
}


int thisyear(int y, int m, int d)
{
    int i, rtn = 0 ;
    for (i = 0 ; i < m ; i++)
        rtn += mon[isleap(y)][i] ;
    return (rtn + d) % 7 ;
}


int calc(int y, int m, int d)
{
    int i, rtn = 0 ;
    for(i=0;i<y;i++)
        rtn += isleap(i)?366:365 ;
    return (rtn + thisyear(y,m,d)+4) % 7 ;
}


int main ()
{
    int y, m, d ;
    char tab[7][10] = {    "Monday",
                        "Tuesday",
                        "Wednesday",
                        "Thursday",
                        "Friday",
                        "Saturday",
                        "Sunday"} ;
    while (~scanf ("%d %d %d%*c", &y, &m, &d))
    {
        if (illegal(y,m,d)) puts ("illegal") ;
        else puts (tab[calc(y,m,d)]) ;
    }
    return 0 ;
}