#include<iostream>
using namespace std;
int main()
{
    int a[21]={0,1,2};
    int i;
    for(i=3;i<21;i++)
    {a[i]=a[i-1]+a[i-2];}
    int n,t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
        printf("%d\n",a[n]);
        }
    }
    return 0;
}