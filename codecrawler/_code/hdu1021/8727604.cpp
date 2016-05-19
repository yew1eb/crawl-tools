#include <stdio.h>
#include <string.h>

int a[8]={1,2,0,2,2,1,0,1};

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(a[n%8]==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
