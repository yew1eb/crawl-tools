#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits.h>

using namespace std;

int lowbit(int t){return t&(-t);}
int countbit(int t){return (t==0)?0:(1+countbit(t&(t-1)));}
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
#define LL long long
#define PI acos(-1.0)
#define N  1010
#define MAX INT_MAX
#define MIN INT_MIN
#define eps 1e-8
#define FRE freopen("a.txt","r",stdin)
int n,m,x,y;
int a[N][N];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        int i,j;
        int ans=-1;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
                if(i>=x && j>=y)
                {
                    int tmp=a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y];
                    if(tmp>ans)ans=tmp;
                }
            }        }
        printf("%d\n",ans);
    }
    return 0;
}