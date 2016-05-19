#include <stdio.h>


int main()
{
    int x, y;
    int xl, yl, xr, yr;
    const int t = 500;
    while(~scanf("%d%d",&x,&y))
    {
        if(x == 0 && y == 0) break;
        xl = yl = 500;
        xr = yr = -500;
        while(true)
        {
            if(x == 0 && y == 0) break;
            if(xl > x) xl = x;
            if(xr < x) xr = x;
            if(yl > y) yl = y;
            if(yr < y) yr = y;
            scanf("%d%d",&x,&y);
        }
        printf("%d %d %d %d\n", xl, yl, xr, yr);
    }
    return 0;
}

