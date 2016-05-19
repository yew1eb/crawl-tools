#include <stdio.h>
#include <string.h>

int prime[1000000];

void sushu(void)
{
    memset(prime,1,sizeof(prime));
    int i,j;
    for(i = 2; i<=500000; i++)
    {
        if(prime[i])
        {
            for(j = i+i; j<1000000; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    int n,cas = 1,k = 0;
    sushu();
    while(~scanf("%d",&n) && n>=0)
    {
        int cnt = 0,i;
        if(k)
            printf("\n");
        printf("Case %d.\n",cas++);
        k++;
        if(prime[n])
        {
            printf("%d 1 \n",n);
            continue;
        }
        else if(n%2 == 0)
        {
            while(n%2 == 0)
            {
                n/=2;
                cnt++;
            }
            printf("2 %d ",cnt);
            for(i = 3; i<=n; i+=2)
            {
                cnt = 0;
                if(prime[i])
                {
                    while(n%i == 0)
                    {
                        n/=i;
                        cnt++;
                    }
                    if(cnt)
                        printf("%d %d ",i,cnt);
                }
            }
            printf("\n");
        }
        else
        {
            for(i = 3; i<=n; i+=2)
            {
                cnt = 0;
                if(prime[i] && n%i == 0)
                {
                    while(n%i == 0)
                    {
                        n/=i;
                        cnt++;
                    }
                    if(cnt)
                    {
                        printf("%d %d ",i,cnt);
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}
