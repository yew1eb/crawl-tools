#include <math.h>
#include <stdio.h>
#define s(x) ((x)*(x))
int main(void)
{
    int x, y;

    while (scanf("%d%d", &x, &y), x+y)
        puts(s(x)-4*y >= 0 && s(x)-4*y - s((int)sqrt(s(x)-4*y)) == 0 ? "Yes" : "No");
    return 0;
}