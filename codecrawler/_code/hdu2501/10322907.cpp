/************************************************
 * Author: yew1eb
 * Created Time: 2014-3-17 19:12:20
 * File Name: HDU2501.cpp
 *************************************************/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
int main()
{
    int n, i;
    long long f[40];
    f[1] = 1; f[2] = 3;
    for(i=3; i<=30; ++i)
        f[i] = f[i-1] + 2*f[i-2];
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        printf("%I64d\n",f[x]);
    }
    return 0;
}
