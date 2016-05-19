#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 51

bool is_square(int t)
{
    return int(sqrt(t*1.)) - sqrt(t*1.) == 0;
}
int main()
{
    int h[N],arr[N],i,j,t,n;//arr[i] è¡¨ç¤ºi+1ä¸ªpegæä¸é¢çæ°ççç¼å·
    for(int k = 1; k < N; ++k)
    {
        memset(arr,-1,sizeof(arr));
        for(i = 0,n = 1;i != k;++n)
        {
            for(i = 0; i < k;++i)
                if(arr[i] == -1 || is_square(n+arr[i]))
                {
                    arr[i] = n;
                    break;
                }
        }
        h[k] = n - 2;//åæå¥½å¾ªç¯åæ³¨æè¿éæ¯-2
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",h[n]);
    }
    return 0;
}
