#include <stdio.h>
#include <string.h>
const int N = 1000005;
int prime[N];
int ans[N];

void set_prime()
{
    int i,j;
    memset(prime,0,sizeof(prime));
    memset(ans,0,sizeof(ans));
    //printf("%d\n",prime[3]);
    prime[0] = prime[1] = 1;
    for(i = 2; i<N; i++)
    {
        if(prime[i])
            continue;
        for(j = i+i; j<N; j+=i)
            prime[j] = 1;
    }
}

int set_sum(int t)
{
    int r,sum = 0;
    while(t)
    {
        r = t%10;
        sum+=r;
        t/=10;
    }
    return sum;
}

void set_ans()
{
    int i;
    ans[0] = ans[1] = 0;
    for(i = 2; i<N; i++)
    {
        if(!prime[i] && !prime[set_sum(i)])
            ans[i] = ans[i-1]+1;
        else
            ans[i] = ans[i-1];
    }
}

int main()
{
    int T,cas = 1,l,r;
    set_prime();
    set_ans();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        printf("Case #%d: %d\n",cas++,ans[r]-ans[l-1]);
    }

    return 0;
}