#include <iostream>
using namespace std;

const int maxn = 50000;

__int64 a[maxn+5], b[maxn+5], c[maxn+5];
__int64 d[maxn+5];
char str[maxn+5];

inline __int64 max(__int64 a, __int64 b)
{
    if (a>=b) return a;
    else return b;
}

inline __int64 min(__int64 a, __int64 b)
{
    if (a<=b) return a;
    else return b;
}

inline __int64 get(__int64 x, __int64 y, __int64 z)
{
    return (y-x)/z+1;
}

int solve(__int64 mid, int n)
{
    int i;
    int al = 0, ar = 0;
    int t, ct;
    for (i=0; i<n; i++)
    {
        ct = 0;
        if (mid>=a[i])
        {
            t = min(mid, b[i]);
            ct += get(a[i], t, c[i]);
        }
        al += ct;
        ar += d[i] - ct;
    }
    if (al%2==1) return 1;
    else if (ar%2==1) return -1;
    else return 0;
}

int main()
{
    int i;
    int n;
    __int64 low, high, mid;
	__int64 ans, act;
    bool flag = true;
    while(flag)
    {
        i = 0;
        flag = false;
        while(gets(str) && (flag=true))
        {
            if (str[0]>='0' && str[0]<='9') break;
            flag = false;
        }
        if (!flag) break;
		flag = false;
        do
        {
            sscanf(str, "%d %d %d", &a[i], &b[i], &c[i]);
            i++;
			flag = false;
        }while(gets(str) && (flag=true) && str[0]>='0' && str[0]<='9');
        n = i;
        for (i=0; i<n; i++) d[i] = get(a[i], b[i], c[i]);
        low = (__int64)INT_MAX*2;
        high = (__int64)INT_MIN;
        for (i=0; i<n; i++)
        {
            low = min(low, a[i]);
            high = max(high, (d[i]-1)*c[i]+a[i]);
        }
        low--;
        high++;
        bool f = false;
        while(low<=high)
        {
            mid = (low+high)>>1;
            switch(solve(mid, n))
            {
            case -1:
                low = mid + 1;
                break;
            case 0:
                f = true;
                break;
            case 1:
                ans = mid;
                high = mid-1;
                break;
            }
            if (f) break;
        }
        if (f) printf("None.\n");
        else
        {
            act = 0;
            for (i=0; i<n; i++)
            {
                if (ans>=a[i] && ans<=b[i] && (ans-a[i])%c[i]==0)
                    act++;
            }
            printf("%I64d %I64d\n", ans, act);
        }
    }
    return 0;
}