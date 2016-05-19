#include <stdio.h>
#include <math.h>

int main()
{
    int T, n, k, i, s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1) {printf("0\n");continue;}
        k = (int)sqrt(n);
        s = 1;
        for(i=2; i<=k; i++)
        if(n%i==0)
        {
            if(i*i==n) s +=i;
            else s +=i +n/i;
        }
        printf("%d\n",s);
    }
    return 0;
}
