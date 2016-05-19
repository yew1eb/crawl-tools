#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t;
    int sum[510];
    scanf("%d",&t);
    while (t--)
    {
        int n,Max=0,ans=0;
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        while (n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            sum[a]+=b;//aç±»æå¤å°ä¸ª
            if (a>Max)
                Max=a;
        }
        for (int i=0; i<=Max; i++)
        {
            if (sum[i]==0)
                continue;
            if (sum[i]%64==0)
                ans+=sum[i]/64;
            else
                ans+=(sum[i]/64)+1;
        }
        int aans;
        if (ans%36==0)
            aans=ans/36;
        else
            aans=(ans/36)+1;
        printf ("%d\n",aans);
    }
    return 0;
}
