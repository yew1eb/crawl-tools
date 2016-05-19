#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<sstream>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<functional>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define me(s)  memset(s,0,sizeof(s))
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair <int, int> P;



int main()
{
    int T;
    int rnd=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        double sum=0.0;
        for(int i=0;i<n;i++)
        {
            double x;
            scanf("%lf",&x);
            sum+=x;
        }
        for(int i=0;i<n;i++)
        {
            double x;
            scanf("%lf",&x);
        }
        printf("Case #%d: %.6lf\n",++rnd,(double)(n+1)/sum);
    }
}
