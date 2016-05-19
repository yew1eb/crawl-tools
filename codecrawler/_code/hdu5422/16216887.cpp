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
#define ll long long
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n,m;
int mat[105][105];

int main ()
{
    int a,b,flag;
    while (scanf ("%d%d",&n,&m)==2)
    {
        flag=0;
        memset(mat, 0, sizeof(mat));
        for (int i=0; i<m; i++)
        {
            scanf ("%d%d",&a,&b);
            if ((a==1&&b==n)||(a==n&&b==1))
                flag=1;
            if (a!=b&&!mat[a][b])
            {
                mat[a][b] = 1;
                mat[b][a] = 1;
            }
        }
        if (!flag)
            printf ("1 1\n");
        else
            printf ("1 %d\n",n*(n-1)/2);
    }
    return 0;
}
