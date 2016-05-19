#include<stdio.h>
#include<algorithm>
using namespace std;
void cal(int n,int m)
{
    long long ans=1;
    m=min(m,n-m);
    int j=m;
    for(int i=n;m>0;m--,i--)
    {
        ans*=i;
    }
    for(int i=1;i<=j;i++)
    {
        ans/=i;
    }
    printf("%I64d\n",ans);
}
int main()
{
    int _case;
    int n,m;
    scanf("%d",&_case);
    while(_case--)
    {
        scanf("%d%d",&n,&m);
        if(m>n)printf("0\n");
        else cal(n,m);
    }
    return 0;
}