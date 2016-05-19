#include <stdio.h>
#include <string.h>
#include <math.h>

int calc(int n)
{
    int i, s = 0, m = (int)sqrt(n);
    for (i = 1; i <= m; i++)
        if (n % i == 0) {
            if (i * i == n) s++;
            else s += 2;
        }
    return s;
}
int main()
{
    int t, a, i, b, num, max, sum;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        max = -100;
        for (i = a; i <= b; i++) {
            sum = calc(i);
            if (max < sum) {
                max = sum;
                num = i;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
