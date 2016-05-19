#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
const int maxn = 100005;
using namespace std;
int d[maxn],n;
int main()
{
    int t,ans;
    scanf("%d",&t);
    for(int k = 1; k <= t; k++)
    {
        ans = 1;
        int x,j = 0;
        scanf("%d",&n);
        memset(d,0,sizeof(d));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            for(int j = 1; j*j<=x; j++)
            {
                if(x%j == 0)
                {
                    d[j]++;
                    if(x/j != j)
                        d[x/j]++;
                }

            }

        }
        for(int i = 100000;i>=1;i--)
        {
            if(d[i]>=2)
            {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
