#include <cstdio>
#include <iostream>
#include <cmath>
#include<cstdlib>
using namespace std;

int main()
{
    int t, n, a[55];
    scanf("%d", &t);
    while(t--)
    {
        double sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int k;
        for(int i = 0; i < n-1; i++)
        {
          k = i;
          for(int j = i+1; j < n; j++)
          {
            if(a[k] < a[j])
              k = j;
          }
          if(k != i)
          {
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
          }
        }
        for(int i = 0; i< n; i++)
        {
          sum += a[i] * pow(0.95, i);
        }
        printf("%.10lf\n", sum);
    }
    return 0;
}
