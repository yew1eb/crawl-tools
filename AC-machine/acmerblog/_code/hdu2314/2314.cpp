#include <stdio.h>
#include <stdlib.h>

int compar(const void *a,const void *b);

int main()
{
    int n;
    int total, num, sum, offer[1024]= {0};
    int i, j, k;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum = 0;
        scanf("%d %d", &total, &num);
        for (j = 0; j < num; j++)
            scanf("%d",&offer[j]);

        qsort(offer,num,sizeof(offer[0]),compar);

        printf("Scenario #%d:\n", i);
        for (k = 0; k < num; k++)
        {
            sum += offer[k];
            if(sum >= total)
                break;
        }
        if(k == num)
            printf("impossible\n\n");
        else
            printf("%d\n\n", k+1);
    }

    return 0;
}
int compar(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}