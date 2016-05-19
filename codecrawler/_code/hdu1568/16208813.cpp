#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int f[21] = {0, 1, 1};

int main()
{
    int n;
    for(int i = 2; i < 21; ++i)
        f[i] = f[i - 1] + f[i - 2];
    while(scanf("%d", &n) != EOF)
    {
        if(n <= 20)
        {
            printf("%d\n", f[n]);
            continue;
        }
        else
        {
            double temp = -0.5 * log(5.0) / log(10.0) + ((double)n) * log((sqrt(5.0)+1.0)/2.0) / log(10.0);
            temp -= floor(temp);
            temp = pow(10.0, temp);
            while(temp < 1000)
                temp *= 10;
            printf("%d\n", (int)temp);
        }
    }
    return 0;
}