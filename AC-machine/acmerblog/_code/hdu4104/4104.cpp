#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

int a[1010];
int main()
{
    int i,n,sum;

    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        sum=0;
        for(i=0;i<n;i++)
        {
            if(sum+1<a[i])
                break;
            else
                sum+=a[i];
        }
        printf("%d\n",sum+1);
    }
    return 0;
}
