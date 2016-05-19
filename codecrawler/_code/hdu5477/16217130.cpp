#include <stdio.h>
int l[105], r[105];
int main()
{
    int t, i, A, B, n, L, min, tmp, k;
    scanf("%d", &t);
    k = 1;
    while(t--)
    {
        scanf("%d %d %d %d", &n, &A, &B, &L);
        for(i = 0;i < n;i++)
            scanf("%d %d", &l[i], &r[i]);
        min = 0;
        tmp = 0;
        for(i = 0;i < n;i++)
        {
            if(i == 0) tmp = tmp + (l[i] - 0) * B;
            tmp = tmp - (r[i] - l[i]) * A;
            min = min>tmp?tmp:min;
            if(i != n - 1) tmp = tmp + (l[i + 1] - r[i]) * B;
            //if(i == n - 1&&r[i] < L) 
        }
        printf("Case #%d: %d\n", k++,  -min);
    }
}