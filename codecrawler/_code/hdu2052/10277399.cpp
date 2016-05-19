#include <stdio.h>

int main(void)
{
    int w, h, i, j;
    while (scanf("%d%d", &w, &h) != EOF)
    {        
        putchar('+');
        for (i = 0; i < w; i++)
            putchar('-');
        putchar('+');
        putchar('\n');
        for (j = 0; j < h; j++)
        {
            putchar('|');
            for (i = 0; i < w; i++)
                putchar(' ');
            putchar('|');
            putchar('\n');
        }
        putchar('+');
        for (i = 0; i < w; i++)
            putchar('-');
        printf("+\n\n");
    }

    return 0;
}
