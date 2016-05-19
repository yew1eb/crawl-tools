#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-8
#define M 1000100
//#define LL __int64
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535898

const int maxn = 100010;
using namespace std;

int x1[maxn], Y1[maxn], x2[maxn], y2[maxn];

int main()
{
    int T, n;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            int l1 = -INF;
            int l2 = -INF;
            int r1 = INF;
            int r2 = INF;
            int ll1 = -INF;
            int ll2 = -INF;
            int rr1 = INF;
            int rr2 = INF;
            scanf("%d",&n);
            for(int i = 0; i < n; i++)
            {
                scanf("%d %d %d %d",&x1[i], &Y1[i], &x2[i], &y2[i]);
                if(l1 < x1[i])
                {
                    l2 = l1;
                    l1 = x1[i];
                }
                else if(l2 < x1[i])
                    l2 = x1[i];

                if(r1 > x2[i])
                {
                    r2 = r1;
                    r1 = x2[i];
                }
                else if(r2 > x2[i])
                    r2 = x2[i];

                if(ll1 < Y1[i])
                {
                    ll2 = ll1;
                    ll1 = Y1[i];
                }
                else if(ll2 < Y1[i])
                    ll2 = Y1[i];

                if(rr1 > y2[i])
                {
                    rr2 = rr1;
                    rr1 = y2[i];
                }
                else if(rr2 > y2[i])
                    rr2 = y2[i];
            }
            if(n == 1)
            {
                printf("0\n");
                continue;
            }
            int xx1, xx2, yy1, yy2;
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(x1[i] == l1)
                    xx1 = l2;
                else
                    xx1 = l1;

                if(x2[i] == r1)
                    xx2 = r2;
                else
                    xx2 = r1;

                if(Y1[i] == ll1)
                    yy1 = ll2;
                else
                    yy1 = ll1;

                if(y2[i] == rr1)
                    yy2 = rr2;
                else
                    yy2 = rr1;
                if(xx1 < xx2 && yy1 < yy2)
                    cnt = max(cnt, ((xx2-xx1)*(yy2-yy1)));
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
