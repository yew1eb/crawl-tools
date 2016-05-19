#include <iostream>
#include <algorithm>
using namespace std;

const int N = 505;

__int64 ab[N * N];
int num;

int search(__int64 x)
{
    int f = 0, l = num - 1;
    int mid;
    while(f <= l)
    {
        mid = (f + l) / 2;
        if(ab[mid] == x)
            return 1;
        else if(ab[mid] < x)
            f = mid + 1;
        else
            l = mid - 1;
    }
    return 0;
}

int main()
{
    int n, m, l, flag = 0, s;
    __int64 a[N], b[N], c[N], x;
    while(cin >> n >> m >> l)
    {
        flag++;
        num = 0;
        for(int i = 0; i < n; i++)
            scanf("%I64d", &a[i]);
        for(int i = 0; i < m; i++)
            scanf("%I64d", &b[i]);
        for(int i = 0; i < l; i++)
            scanf("%I64d", &c[i]);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ab[num++] = a[i] + b[j];
        sort(ab, ab+num);
        sort(c, c+l);
        scanf("%d", &s);
        printf("Case %d:\n", flag);
        while(s--)
        {
            scanf("%I64d", &x);
            if(x < ab[0] + c[0] || x > ab[num-1] + c[l-1])
                printf("NO\n");
            else
            {
                __int64 p;
                int j;
                for(j = 0; j < l; j++)
                {
                    p = x - c[j];
                    if(search(p))
                    {
                        printf("YES\n");
                        break;
                    }
                }
                if(j == l)
                    printf("NO\n");
            }
        }
    }
    return 0;
}