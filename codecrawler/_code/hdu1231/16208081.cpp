/*
æ¬é¢çç¶ææ¹ç¨ï¼sum = sum > 0 ? sum+a[i] :a[i];
*/
#include<stdio.h>
#define MAXN 10002
int a[MAXN];

int main()
{
    int k, i, sum, ans, st, ed, y, x;
    while(scanf("%d", &k), k)
    {
        for(i=0; i<k; i++)
        {
            scanf("%d", &a[i]);
        }
        sum = ans = st = ed = x = y =a[0];
        for(i=1; i<k; i++)
        {
            if(sum > 0)
            {
                sum += a[i];
                ed = a[i];
            }
            if(sum <= 0)
            {
                sum = a[i];
                st = a[i];
                ed = a[i];
            }
            if(sum > ans)
            {
                ans = sum;
                x = st;
                y = ed;
            }
        }
        if(ans >= 0)
            printf("%d %d %d\n", ans, x, y);
        else
            printf("%d %d %d\n", 0, a[0], a[k-1]);
    }
    return 0;
}
