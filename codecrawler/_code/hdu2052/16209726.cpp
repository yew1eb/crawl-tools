#include <stdio.h>
#include <string.h>
int main()
{
    int w,h,i,j;
    while(scanf("%d%d", &w, &h)!=EOF)
    {
        printf("+");
        for(i=1; i<=w; i++)
        {
            printf("-");
        }
        printf("+\n");

        for(i=1; i<=h; i++)
        {
            printf("|");
            for(j=1; j<=w; j++)
            {
                printf(" ");
            }
            printf("|\n");
        }

        printf("+");
        for(i=1; i<=w; i++)
        {
            printf("-");
        }
        printf("+\n");

        printf("\n");
    }
    return 0;
}
