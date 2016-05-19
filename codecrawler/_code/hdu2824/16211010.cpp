#include<stdio.h>
#include<math.h>
#define maxn 3000000
int phi[3000000+100];
void get_PHI()
{
    int i,j;
    for (i = 1; i <= maxn; i++) phi[i] = i;
    for (i = 2; i <= maxn; i += 2) phi[i] /= 2;
    for (i = 3; i <= maxn; i += 2) if(phi[i] == i)
    {
        for (j = i; j <= maxn; j += i)
            phi[j] = phi[j] / i * (i - 1);
    }
}
    int main()
    {
        int a,b,i;
        get_PHI();
        while(scanf("%d%d",&a,&b)!=EOF)
        {
            __int64 sum=0;
            for(i=a;i<=b;i++)
                sum+=phi[i];
            printf("%I64d\n",sum);
        }
        return 0;
    }
