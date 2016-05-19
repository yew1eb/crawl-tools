#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T, Case = 0;
    scanf("%d", &T);
    while (T--)
    {
        Case++;
        int n, k1, k2;
        __int64 k;
        __int64 sum = 0, sum1 = 0;
        scanf("%d %d %d %I64d", &n, &k1, &k2, &k);
        int i;
        __int64 tmp;
        for (i=0; i<n; i++)
        {
            scanf("%I64d", &tmp);
            sum += tmp;
        }
        printf("Case #%d: ", Case);

        sum1 = sum;
        for(i=0;;i++)
        {
            if(sum1 > k)
            {
                printf("%d\n",i);
                break;
            }
            sum = sum1;
            sum1 = sum*(k1+k2);
            if((sum >0 &&(k1+k2)>0 && sum1 <0))
            {
                printf("%d\n",i+1);
                break;
            }
            if((sum <0 &&(k1+k2)<0 && sum1 <0))
            {
                printf("%d\n",i+1);
                break;
            }
            if(i>100000)
            {
                printf("inf\n");
                break;
            }
        }
    }
    return 0;
}