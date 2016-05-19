#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int get_fac(int n)
{
    int tot = 0;
    for(int i = 1; i <= n; i++) if(n % i == 0) tot++;
    return tot;
}

int main()
{
    int a, b;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &a, &b);
        int max = 0;
        int ans = 0;
        for(int i = a; i <= b; i++)
        {
            if(get_fac(i) > max)
            {
                max = get_fac(i);
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
}
