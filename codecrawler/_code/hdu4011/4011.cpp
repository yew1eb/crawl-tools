#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define PI acos(-1.0)
#define eps 1e-8
#define LL long long
#define moo 1000000007
#define INF -999999999
using namespace std;
#define maxn 101000
int main()
{
    int t;
    cin>>t;
    int n,b;
    long long sum,ans,a;
    int s[maxn];
    int Case=1;
    while(t--)
    {
        scanf("%d%I64d%d",&n,&a,&b);
        sum=b+a*2;
        ans=a*2+b;
        for(int i=1;i<=n;i++)
            scanf("%d",s+i);
            for(int i=1;i<n;i++)
                s[i]=s[i+1]-s[i];
                for(int i=1;i<n;i++)
                {
                    if(s[i]*b>=ans)
                        sum+=ans;
                    else sum+=s[i]*b;
                }
                printf("Case #%d: %I64d\n",Case++,sum);

    }
    return 0;
}
