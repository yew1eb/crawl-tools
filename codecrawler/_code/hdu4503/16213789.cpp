#include <iostream>
#include <cstdio>
using namespace std;

int C(int n, int m)
{
    if(m > n)
        return 0;
    else if(m == n)
        return 1;
    else
    {
        int ans = 1;
        for(int i=n-m+1; i<=n; i++)
            ans *= i;
        for(int i=1; i<=m; i++)
            ans /= i;
        return ans;
    }
}

int main()
{
    int T, n;
    int a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        a = b = 0;
        int temp;
        double ans = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            ans += (double)temp*(n-1-temp);
        }
        ans /= 2.0;
        ans = ans/(double)(C(n, 3));
        printf("%.3lf\n", 1-ans);
    }
    return 0;
}
