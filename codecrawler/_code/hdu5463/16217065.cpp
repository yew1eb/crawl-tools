#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
const int maxn=500+10;
const int inf=(1<<30);
int res[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(res,0,sizeof(res));
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            res[a]+=b;
        }
        int ans=0;
        for(int i=1;i<=maxn;i++)
        {
            if(res[i]!=0)
            {
                if(res[i]%64==0)
                    ans+=res[i]/64;
                else
                    ans+=(res[i]/64)+1;
            }
        }
        if(ans%36==0)
            printf("%d\n",ans/36);
        else
            printf("%d\n",ans/36+1);
    }
    return 0;
}