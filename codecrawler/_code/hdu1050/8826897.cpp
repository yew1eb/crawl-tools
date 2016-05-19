#include <stdio.h>
#include <string.h>

int main()
{
    int t, s, e, i, n, max, tmp;
    int mark[205];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(mark, 0, sizeof(mark));
        while (n--) {
            scanf("%d%d", &s, &e);
            if (s > e) {
                tmp = s;
                s = e;
                e = tmp;
            }
            s = (s - 1) >> 1;
            e = (e - 1) >> 1;
            for (i = s; i <= e; i++)
                mark[i]++;
        }
        max = 0;
        for (i = 0; i <= 200; i++)
            if (max < mark[i]) max = mark[i];
        printf("%d\n", max * 10);
    }
    return 0;
}
