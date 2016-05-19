#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define ls 2*i
#define rs 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
const int mod = 10007;

int n,m;
double a[N];

int main()
{
    int i,j,k,x,y;
    double w;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 1; i<=n; i++)
            scanf("%lf",&a[i]);
        for(i = 1; i<=m; i++)
        {
            scanf("%d%d%lf",&x,&y,&w);
            w=w/2;
            a[x]+=w;
            a[y]+=w;
        }
        sort(a+1,a+1+n);
        double sum1=0,sum2=0;
        for(i = 1; i<=n; i++)
        {
            if(i%2==0)
                sum1+=a[i];
            else
                sum2+=a[i];
        }
        printf("%.0f\n",sum1-sum2);
    }

    return 0;
}
