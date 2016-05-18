#include "stdio.h"
int deal(int n, int m)
{
int a, b;
long long r;
int res = 0;
for (a = 1; a < n; a++)
{
       for (b = a + 1; b < n; b++)
              {
                     r = (a * a + b * b + m) % (a * b);
                     if (!r)
                            res += 1;
              }
       }
       return res;
}

int main()
{
       int N;
       bool mark = 0;
       scanf ("%d", &N);
       int n, m;
       while (N--)
       {
              int i = 1;
              (mark) ? printf ("\n") : mark = 1;
              while (scanf ("%d %d", &n, &m) != EOF && (n || m))
                     printf ("Case %d: %d\n", i++, deal(n, m));
       }
       return 0;
}