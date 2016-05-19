#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
int ans;
int main()
{
    int test;
    scanf("%d",&test);
    for(int item = 1; item <= test; item++)
    {
        int n,a[1010];
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);

        ans = abs(a[1]);

        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = i; j <= n; j++)
            {
                sum += a[j];
                if(ans > abs(sum))
                    ans = abs(sum);
            }
        }
        printf("Case %d: %d\n",item,ans);
    }
    return 0;
}
