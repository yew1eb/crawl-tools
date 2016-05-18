#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n,a;
    while(scanf("%d",&n)&&n)
    {
        int sum=0,mx=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&a);
            if(sum<0)
                sum=a;
            else sum+=a;
            if(sum>mx) mx=sum;
        }
        if(mx>0)
            printf("The maximum winning streak is %d.\n",mx);
        else
            printf("Losing streak.\n");
    }
    return 0;
}