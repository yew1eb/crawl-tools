#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;

//计算x ≥ 1, y ≥ 1, x * y ≤ c时S内有多少个整数点
int count(int c)
{
    int ans = 0;
    for(int i=1;i<=c;i++)
    {
        ans += c/i;
    }
    return ans;
}
//二分法求lower_bound
int calc(int n)
{
    int low = 1;
    int high = n;
    int pos = 1;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(count(mid)<n)
        {
            low = mid + 1;
            pos = low;
        }
        else
        {
            high = mid;
            pos = mid;
        }
    }
    return pos;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int t;
    int n;
    int c;
    scanf(" %d",&t);
    for(int i=0;i<t;i++)
    {
        scanf(" %d",&n);
        if(n == 0)
        {
            printf("0.0000\n");
            continue;
        }

        c = calc(n);
        printf("%.4lf\n",c*log(c) - (c - 1));
    }

    return 0;
}