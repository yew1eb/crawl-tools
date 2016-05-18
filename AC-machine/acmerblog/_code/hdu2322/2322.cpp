#include <stdio.h>

bool black_white(int x, int y);

int main()
{
    int k, i, a, b, c, d, t;

    scanf("%d", &k);
    for (i = 1; i <= k; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (black_white(a, b) != black_white(c, d) )
            t = 1;
        else
            t = 0;
        printf("Scenario #%d:\n", i);
        printf("%d\n\n", t);
    }
    return 0;
}

bool black_white(int x, int y)
{
    if ((x + y) % 2 == 0)
        return 0;
    return 1;
}