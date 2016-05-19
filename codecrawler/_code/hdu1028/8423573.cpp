#include <stdio.h>
int main()
{
    int N;
    int i, j, k;
    int a[121], b[121];
    while(scanf("%d",&N) !=EOF)
    {
        for(i=0; i<=N; i++)
        {
            a[i] = 1;
            b[i] = 0;
        }
        for(i=2; i<=N; i++)
        {
            for(j=0; j<=N; j++)
                for(k=0; k+j<=N; k+=i)
                {
                    b[k+j] +=a[j];
                }
                for(j=0; j<=N; j++)
                {
                    a[j] = b[j];
                    b[j] = 0;
                }
        }
        printf("%d\n",a[N]);
    }
    return 0;
}
