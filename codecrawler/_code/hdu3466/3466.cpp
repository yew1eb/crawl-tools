#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <complex>
#include <numeric>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

using namespace std;

#pragma pack(4)

const double  eps = 1e-8;
const double   pi = acos(-1.0);
const int     inf = 0x7f7f7f7f;

#define loop(a,n)                            \
    for(int i=0;n>i;i++)                     \
        cout<<a[i]<<(i!=n-1?' ':'\n')
#define loop2(a,n,m)                         \
    for(int i=0;n>i;i++)                     \
        for(int j=0;m>j;j++)                 \
            cout<<a[i][j]<<(j!=m-1?' ':'\n')

#define   at(a,i) ((a)&(1<<(i)))
#define   nt(a,i) ((a)^(1<<(i)))
#define set1(a,i) ((a)|(1<<(i)))
#define set0(a,i) ((a)&(~(1<<(i))))

#define cmp(a,b) (fabs((a)-(b))<eps?0:(((a)-(b))>eps?+1:-1))

#define lmax(a,b) ((a)>(b)?(a):(b))
#define lmin(a,b) ((a)<(b)?(a):(b))
#define fmax(a,b) (cmp(a,b)>0?(a):(b))
#define fmin(a,b) (cmp(a,b)<0?(a):(b))

const int MAXV = 5002;

struct node
{
    int p,q,v;
    bool operator < (node argu) const
    {
        return q-p>argu.q-argu.p;
    }
}a[502];

int n,m,dp[MAXV];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Proud Merchants.txt","r",stdin);
    #else
    #endif

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;n>i;i++)
        {
            scanf("%d %d %d",&a[i].p,&a[i].q,&a[i].v);
        }
        sort(a,a+n);
        memset(dp,-1,sizeof(dp)); dp[m]=0;
        int ans=0;
        for(int i=0;n>i;i++)
        {
            for(int j=max(0,a[i].q-a[i].p);m>=j+a[i].p;j++)
            {
                if(dp[j+a[i].p]!=-1)
                {
                    dp[j]=max(dp[j],dp[j+a[i].p]+a[i].v);
                    ans=max(ans,dp[j]);
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}