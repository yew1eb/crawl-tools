#include <stdio.h>

int main(void)
{
    int i, t, n;
    double s[2], c[2];
    scanf("%d", &t);
    while (t-- && scanf("%d", &n))
    {
        for (s[1]=c[1]=i=0; n--; )
        {
            scanf("%*s%lf%lf", c, s);
            if (i) continue;
            if (s[0] < 60 && s[0] >= 0) i = 1;
            s[1] += s[0]*c[0];
            c[1] += c[0];
        }
        printf(i?"Sorry!\n":"%.2f\n", s[1]/c[1]);
        if (t) putchar('\n');
    }
    return 0;
}
