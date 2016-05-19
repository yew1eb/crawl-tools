#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
typedef unsigned long long LLU;

const int maxn=1010;
LL t[2*maxn], M[3*maxn][2*maxn];
int n;

void solve()
{
    for(int i=n+1; i<=3*n-1; i++)
    {
        M[i][0]=0;
        for(int j=1; j<2*n; j++)
            if(i-j>0 && (i-j)<=(2*n-1))
                M[i][j]=t[j]*t[i-j]+M[i][j-1];
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1; i<=2*n-1; i++)
            scanf("%d", &t[i]);
        solve();

        LL ANS=0, ans=0;
        int r, c, m;
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d%d", &r, &c);
            r=(r+ANS)%n+1;
            c=(c+ANS)%n+1;
            ANS=M[2*n-r+c][2*n-r]-M[2*n-r+c][n+1-r-1];
            ans+=ANS;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
