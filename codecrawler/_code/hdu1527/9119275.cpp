#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double Golden = (1 +sqrt(5)) / 2;
int main()
{
    int n, m, k;
    while(~scanf("%d%d",&n,&m))
    {
        if(n<m) swap(n,m);
        k = n - m;
        if(m == (int)(k*Golden)) puts("0");
        else puts("1");
    }
    return 0;
}
