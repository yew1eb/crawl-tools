/************************************************
 * Author: yew1eb
 * Created Time: 2014-3-17 18:57:32
 * File Name: HDU2553.cpp
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
int cnt;
bool vis[3][50];

void dfs(int k, int n)
{
    if(k==n)
    {
        cnt++;
        return ;
    }
    for(int i=0; i<n; ++i)
    {
        if(!vis[0][i] && !vis[1][k+i] && !vis[2][k-i+n] )
        {
            vis[0][i] = vis[1][k+i] = vis[2][k-i+n] = 1;
            dfs(k+1,n);
            vis[0][i] = vis[1][k+i] = vis[2][k-i+n] = 0;
        }
    }
}
int main()
{
    int n, i;
    int f[20];
    for(i=1; i<=10; ++i)
    {
        cnt = 0;
        memset(vis, 0, sizeof vis );
        dfs(0,i);
        f[i] = cnt;
    }
    while(scanf("%d",&n),n)
    {
        printf("%d\n",f[n]);
    }

    return 0;
}
