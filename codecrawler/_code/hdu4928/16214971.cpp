#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
#define N 100010

LL a[N];
int L,R,t,n,ans;

int main()
{
    int i,small,big;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
        L=1;
        R=n;
        for(ans=0;ans<n;ans++)
        {
            small=big=0;
            while(L<=R&&!a[L]) L++;
            if(L>1) L--;
            while(R>=L&&!a[R]) R--;
            if(R<n-ans) R++;
            if(L>=R) break;
            for(i=L;i<R;i++)
            {
                if(a[i]<a[i+1]) small=1;
                if(a[i]>a[i+1]) big=1;
            }
            if(small&&big)
            {
                if(!ans) puts("ugly series");
                else printf("%d\n",ans-1);
                ans=-1;
                break;
            }
            for(i=L;i<R;i++)
                a[i]=a[i+1]-a[i];
            R--;
        }
        if(ans!=-1) puts("nice series");
    }
    return 0;
}
