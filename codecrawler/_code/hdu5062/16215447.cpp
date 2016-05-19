//0ms
#include <cstdio>
#include <cstring>
#include <iostream>
int a[7]={1,9,18,54,90,174,258};
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
}