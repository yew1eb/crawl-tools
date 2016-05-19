#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
const int maxn=200;
int a[maxn];
int main()
{
    int n,b,c;
    while(~scanf("%d%d%d",&n,&b,&c))
    {
        int cnt=0;
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<n;i++)
        {
            for(int k=i+1;k<n;k++)
            {
                if(abs(a[k]-a[i])%b==c)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }


    return 0;
}