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

int main ()
{
    int x,y,w,n;
    while (scanf ("%d%d%d%d",&x,&y,&w,&n)==4)
    {
        int t;
        if (x < w)
            t = (x+y)*(n-1);
        else
        {
            int a=x/w+1;
            if (n%a==0)
                t = (n/a)*(x+y)-y-x%w;
            else
                t = (n/a)*(x+y)+(n%a-1)*w;
        }
        printf ("%d\n",t);
    }
    return 0;
}
