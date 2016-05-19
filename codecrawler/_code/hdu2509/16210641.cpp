#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,i;
    int sum1,sum2,ans;
    int a[55];
    while(~scanf("%d",&n))
    {
        sum1 = sum2 = ans = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%d",&a[i]);
            ans^=a[i];
            if(a[i]>=2)
                sum2++;
            else
                sum1++;
        }
        if((ans && sum2) || (!ans && !sum2))
            printf("Yes\n");
        if((ans && sum1%2 && !sum2) || (!ans && sum2>=2))
            printf("No\n");
    }

    return 0;
}
