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

const int N=1005;
bitset<N>bs[N];

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            bs[i].reset();
            bs[i][i]=1;
        }
        int num,v;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&v);v--;
                bs[i][v]=1;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            if(bs[j][i])
                bs[j]|=bs[i];
        double ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
                if(bs[j][i])cnt++;
            ans+=1.0/cnt;
        }
        printf("Case #%d: %.5lf\n",kase,ans);
    }
}
