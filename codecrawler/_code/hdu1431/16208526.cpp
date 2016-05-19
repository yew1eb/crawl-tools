#include <stdio.h>
#include <stdio.h>
using namespace std;

bool a[9989900];
int prime[1005];

void set()
{
    int i,j;
    for(i = 2; i<=9989899; i+=2)
        a[i] = true;
    for(i = 3; i<=3161; i++)
    {
        if(a[i])
            continue;
        for(j = i+i; j<=9989899; j+=i)
            a[j] = true;
    }
}

int huiwen(int n)
{
    int a = 0,b = n;
    while(b)
    {
        int r = b%10;
        a = a*10+r;
        b/=10;
    }
    if(a == n)
        return 1;
    return 0;
}

int main()
{
    int n,m,i,k = 2;
    set();
    prime[0] = 5;
    prime[1] = 7;
    for(i = 11; i<=9989899; i+=2)
    {
        if(!a[i] && huiwen(i))
            prime[k++] = i;
    }
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i<k; i++)
        {
            if(prime[i]<n)
                continue;
            else if(prime[i]>m)
                break;
            else
                printf("%d\n",prime[i]);
        }
        printf("\n");
    }
    return 0;
}
