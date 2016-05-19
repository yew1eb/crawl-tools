#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        if(n>6)
            a = a+(n-6)*8+27;
        else
            a = a+(15-n)*n/2;
        if(a>=b)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
