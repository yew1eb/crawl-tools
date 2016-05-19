#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))

int a[1005];
int n,q,l,r;

int main ()
{
    int T;
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        for (int i=1; i<=n; i++)
            scanf ("%d",&a[i]);
        scanf ("%d",&q);
        int maxx;
        while (q--)
        {
            maxx=0;
            scanf ("%d%d",&l,&r);
            for (int i=l; i<=r; i++)
                maxx=max(maxx, a[i]);
            cout<<maxx<<endl;
        }
    }
}
