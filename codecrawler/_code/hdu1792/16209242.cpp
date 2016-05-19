#include"stdio.h"
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1)
        printf("%d %d\n",n*m-n-m,(n-1)*(m-1)/2);
    return 0;
}