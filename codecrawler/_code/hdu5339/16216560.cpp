#include <stdio.h>
#include <ctime>
#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <assert.h>

using namespace std;

int n, a, b[300],ans;

bool cmp11(int a, int b)
{
    return a > b;
}

void dfs(int x,int num,int A)
{
    if (x == 0)
    {
        ans = min(ans, A); return;
    }
    if (num == n) return;

    //printf("    %d\n",x);
    dfs(x % b[num + 1], num + 1, A + 1);
    dfs(x, num + 1, A);
}

int main()
{
    //printf("3 % 7");
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d", &n, &a);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        sort(b + 1, b + 1 + n, cmp11);
        ans = 500;
        dfs(a, 0, 0);
        if (ans == 500) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}