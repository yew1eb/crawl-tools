#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,a,b,min;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        min=99999999;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            int temp=n%a?(n/a+1):(n/a);
            min=temp*b<min?temp*b:min;
        }
        printf("%d\n",min);
    }
    return 0;
}