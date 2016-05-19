#include <stdio.h>
#include <string.h>
#include <algorithm>

int a[20];

inline int abs(int x)
{
    if(x > 0) return x;
    return -x;
}

int main()
{
//    freopen("in", "r", stdin);
    int c, s, n, cas = 1;
    while(~scanf("%d %d", &c, &s))
    {
        memset(a, 0, sizeof(a));
        n = (c << 1) - s;
        int ave = 0;
        for(int i = n; i < (c << 1); i++)
        {
            scanf("%d", &a[i]);
            ave += a[i];
        }
    //    printf("ave = %lf\n", ave);
        std::sort(a, a + (c << 1));
        printf("Set #%d\n", cas++);
        double sum = 0;
        for(int i = 0; i < c; i++)
        {
            printf(" %d:", i);
            sum += abs(c * a[i] + c * a[(c << 1) - i - 1] - ave);
            if(a[i]) printf(" %d", a[i]);
            if(a[(c << 1) - i - 1]) printf(" %d", a[(c << 1) - i - 1]);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", sum / c);
    }
    return 0;
}