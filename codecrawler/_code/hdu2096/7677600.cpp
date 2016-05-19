#include <stdio.h>

int main()
{
    int n;
    int a, b;
    
    scanf("%d", &n);
    while (n--)
    {
          scanf("%d%d", &a, &b);
          printf("%d\n", (a % 100 + b % 100) % 100);
    }
    
    return 0;
}
