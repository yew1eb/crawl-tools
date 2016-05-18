#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b);

int main()
{
    int n, m;
    int diameter[20001], height[20001];
    int i, j, k, sum, head;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 &&m == 0)
            break;

        for (i = 0; i < n; i++)
            scanf("%d", &diameter[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &height[i]);

        if (n > m)
        {
            printf("Loowater is doomed!\n");
            continue;
        }

        qsort(diameter, n, sizeof(diameter[0]), compar);
        qsort(height, m, sizeof(height[0]), compar);

        head = sum = k = 0;
        for (i = 0; i < n; i++)
        {
            for (j = k; j < m; j++)
            {
                if (diameter[i] <= height[j])
                {
                    head++;
                    sum += height[j];
                    k = ++j;
                    break;
                }
            }
        }

        if (head == n)
            printf("%d\n", sum);
        else
            printf("Loowater is doomed!\n");
    }

    return 0;
}

int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}