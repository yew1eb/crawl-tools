#include <stdio.h>

int main()
{
    int   i;
    int   a, b;
    int   c;
    
    while (scanf("%d%d", &a, &b), a + b)
    {
          for (c=i=0; i<100; ++i)
          {
              if ((a * 100 + i) % b == 0)
                 printf(c++ ? " %02d" : "%02d", i);
          }
           putchar('\n');
    }
}