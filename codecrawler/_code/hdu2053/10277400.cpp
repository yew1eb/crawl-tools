#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int n, m;
    while(~scanf("%d",&n))
    {
        int m = (int)sqrt(n + 0.5);
        if(m * m == n) puts("1");
        else puts("0");
    }
    return 0;
}
