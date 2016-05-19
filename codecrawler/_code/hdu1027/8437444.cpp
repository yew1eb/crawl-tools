#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a[1005];
    int n, m, i;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<n; i++) a[i] = i+1;
        i = 0;
        while(++i<m)
        {
            next_permutation(a,a+n);
        }
        for(i=0;i<n-1; i++) printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}
