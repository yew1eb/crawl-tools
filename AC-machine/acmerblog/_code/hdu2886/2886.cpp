#include<iostream>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if (n < 5)
        {
            printf("%d\n",n);
            continue;
        }
        int two=1;
        while(n%3)
            two*=2,n-=2;
        int a=3,b=n/3,k=1;
        while(b>1)
        {
            if(b&1)
                k=k*a%2009;
            a=a*a%2009;
            b>>=1;
        }
        printf("%d\n",two*a*k%2009);
    }
    return 0;
}