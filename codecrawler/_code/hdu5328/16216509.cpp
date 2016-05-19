#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;
const ll maxn=1000005;
int T,n,m;
double a[maxn],b[maxn],c[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            if (i) 
            {
                b[i]=a[i]-a[i-1];
                if (a[i-1]>1e-7) c[i]=a[i]/a[i-1];
            }
        }
        int l=1,r=1,ans=1;
        for (int i=2;i<n;i++)
        {
            if (b[i]==b[i-1]) l++; else l=1;
            if (c[i]==c[i-1]) r++; else r=1;
            ans=max(ans,max(l,r));
        }
        printf("%d\n",min(ans+1,n));
    }
}