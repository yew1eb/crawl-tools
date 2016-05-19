#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        __int64 sum = 0;
        int n,m,p,q;
        scanf("%d%d%d%d",&n,&m,&p,&q);
        if(p*m<=q)
        {
            printf("%d\n",p*n);
        }
        else
        {
            sum = (n/m)*q;
            n = n%m;
            if(n*p<q)
            {
                printf("%I64d\n",sum+n*p);
            }
            else
            {
                printf("%I64d\n",sum+q);
            }
        }
    }
    return 0;
}