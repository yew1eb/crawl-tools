#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<math.h>
#define nn 110
#define inff 0x3fffffff
typedef __int64 LL;
using namespace std;
int n,b,q;
vector<int>a,c;
double solve()
{
    bool ok=false;
    if(q==1)
    {
        while(b)
        {
            if(n==b)
            {
                ok=true;
                break;
            }
            b/=10;
        }
    }
    else
    {
        b*=10000;
        while(b)
        {
            if(n==b)
            {
                ok=true;
                break;
            }
            b/=10;
        }
    }
    if(ok)
        return 1.0;
    else
        return 0.0;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        cin>>n>>b>>q;
        printf("Case #%d: ",cas++);
        if(q==1||q==10||q==100||q==1000)
        {
            printf("%.5lf\n",solve());
        }
        else
        {
            double ans=log10(n+1.0)-log10(n*1.0);
            printf("%.5lf\n",ans);
        }
    }
    return 0;
}
