#include <stdio.h>

int main(void)
{
    int c[9], k, n, i;
    int count;
    int t[9], a, b;
    int total = 40;

    scanf("%d", &k);
    while (k-- && scanf("%d%d", &total, &n))
    {
        for (count = i = 0; i < 9; t[i++] = 0);
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            t[a] = b;
        }
        for (c[8] = 0; c[8] <= t[8] && c[8] * 8 <= total; c[8]++)
        for (c[7] = 0; c[7] <= t[7] && c[8] * 8 + c[7] * 7 <= total; c[7]++)
        for (c[6] = 0; c[6] <= t[6] && c[8] * 8 + c[7] * 7 + c[6] * 6 <= total; c[6]++)
        for (c[5] = 0; c[5] <= t[5] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5 <= total; c[5]++)
        for (c[4] = 0; c[4] <= t[4] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4 <= total; c[4]++)
        for (c[3] = 0; c[3] <= t[3] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4  + c[3] * 3 <= total; c[3]++)
        for (c[2] = 0; c[2] <= t[2] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4  + c[3] * 3  + c[2] * 2 <= total; c[2]++)
        {
            c[1] = total - (c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4  + c[3] * 3  + c[2] * 2);
            if (c[1] >= 0 && c[1] <= t[1]) count++;
        }
        printf("%d\n", count);
    }
    

    return 0;
}
