#include<stdio.h>
#include<string.h>
#define MM 32769
bool is_prime[MM] = {false};
int n=0;
int init_prime()
{
    memset(is_prime,true,sizeof(is_prime));
    for(int i=1;i<=MM-1;i++) if(i%2==0) is_prime[i]=false;
    for(int i=3;i<=MM/2+1;i++) for(int j=i+i;j<=MM-1;j+=i) if(j<=MM-1) is_prime[j]=false;
    is_prime[1]=false;
    is_prime[2]=true;
    return(0);
}
int main()
{
    init_prime();
    while(scanf("%d",&n)!=EOF&&n>0)
    {
        int cnt=0;
        for(int i=2;i<=n/2;i++)
        {
            if(is_prime[i]&&is_prime[n-i]) cnt++;
        }
        printf("%d\n",cnt);
    }
    return(0);
}
