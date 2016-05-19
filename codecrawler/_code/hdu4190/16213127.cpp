#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int a[500010];

int main()
{
    int city, box, res, r, l, mid;
    int sum;
    bool flag;
    while(scanf("%d%d", &city, &box))
    {
        if(city == - 1 && box == -1)
            break;
        res = 0;
        for(int i = 0; i < city; ++i)
        {
            scanf("%d", &a[i]);
            res = max(res, a[i]);
        }
        if(city == box)
        {
            printf("%d\n", res);
            continue;
        }
        l = 1, r = res;
        while(l < r)
        {
            flag = true;
            sum = 0;
            mid = (l + r) >> 1;
            for(int i = 0; i < city; ++i)
            {
                sum += ceil(a[i] * 1.0 / mid); //æµè¯ä¸­é´å¼
                if(sum > box)
                    flag = false;
            }
            if(flag)    r = mid; //ä¸­é´å¼å¯ä»¥å°±åå
            else    l = mid + 1; //ä¸å¯ä»¥åmid+1
        }
        printf("%d\n", r);
    }
    return 0;
}