//公式为：((n-2)*(n-4)*(n-6)*(n-8)*(n-10)*........)/((n-1)*(n-3)*(n-5)*(n-7)*(n-9)*........)
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        double ans=1.0;
        for(i=2;i<=n-2;i+=2)
            ans*=(double)i/(double)(i+1);
        printf("%.5lf/n",ans);
    }
    return 0;
}