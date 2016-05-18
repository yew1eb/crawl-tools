#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define mod 200907
int n;
struct node
{
    __int64 map[3][3];
}unit,s;
node Mul(node a,node b)
{
    node c;
    int i,j,k;
    for(i = 0; i < 3; i ++)
    for(j = 0; j < 3; j ++)
    {
        c.map[i][j] = 0;
        for(k = 0; k < 3; k ++)
        c.map[i][j] += (a.map[i][k]*b.map[k][j])%mod;
        c.map[i][j] %= mod;
    }
    return c;
}
void Matrix()
{
    while(n)
    {
        if(n&1) unit = Mul(unit,s);
        n >>= 1;
        s = Mul(s,s);
    }
}
int main()
{
    int i,f[3] = {1,1,2};
    while(scanf("%d",&n),n)
    {
        if(n <= 2)
        {
            printf("%d\n",f[n]);
            continue;
        }
        memset(s.map,0,sizeof(s.map));
        s.map[0][0] = 1; s.map[0][1] = 2; s.map[0][2] = 1;
        s.map[1][0] = 1; s.map[2][2] = 1;
        memset(unit.map,0,sizeof(unit.map));
        for(i = 0; i < 3; i ++)
        unit.map[i][i] = 1;
        n -= 2;
        Matrix();
        __int64 ans = 0;
        for(i = 0; i < 3; i ++)
        ans += unit.map[0][i]*f[2-i], ans %= mod;
        printf("%I64d\n",ans);
    }
    return 0;
}