#include"stdio.h"
int main()
{
    double ans[100000];
    int i;
    int n;
    ans[1]=0.5;
    for(i=2;i<100000;i++)    ans[i]=ans[i-1]+1.0/2/i;
    printf("# Cards  Overhang\n");
    while(scanf("%d",&n)!=-1)    printf("%5d%10.3lf\n",n,ans[n]);
    return 0;
}