#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

double k[1010];

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%lf",&k[i]);
        int c;
        for (int i=0;i<n;i++)
            scanf("%d",&c);
        double ans=0;
        for (int i=0;i<n;i++)
            ans+=k[i];
        ans=(n+1)/ans;
        printf("Case #%d: %.6lf\n",t,ans);
    }
    return 0;
}
