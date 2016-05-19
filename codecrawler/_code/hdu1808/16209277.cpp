#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 10;
int  mod[maxn], fl[maxn], c, n;
long long sum[maxn];
int main()
{
    while(scanf("%d %d", &c, &n))
    {
        if(!(c + n)) break;
        int xbegin = 1, xend;
        memset(sum, 0, sizeof(sum));
        memset(fl, 0, sizeof(fl));
        for(int i = 1;i <= n; i++)
        {
            scanf("%d", &sum[i]);
            sum[i] += sum[i-1];
            //cout << sum[i] << endl;
            mod[i] = sum[i] % c;
            if(mod[i] == 0)
            {
                xbegin = 1;
                xend = i;
            }
            else if(fl[mod[i]])
            {
                xbegin = fl[mod[i]];
                xend = i;
            }
            fl[mod[i]] = i + 1;
        }
        for(int i = xbegin;i <= xend; i++)
        {
            cout << i;
            if(i != xend) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
