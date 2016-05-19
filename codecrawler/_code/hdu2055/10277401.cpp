#include <stdio.h>

int main()
{
    int n, a;
    char c;

    scanf("%d%*c", &n);
    while (n-- && scanf("%c%d%*c", &c, &a))
        printf("%d\n", a + (c < 97 ? c - 'A' + 1 : 'a' - c - 1));

    return 0;
}
