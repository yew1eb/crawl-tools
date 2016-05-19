#include<stdio.h>
#include<math.h>
#include <queue>
#include<algorithm>
#include <iostream>
#include <string.h>
using namespace std;

 bool prime(int n)
 {
     int i;
     for(i=2;i<=sqrt(n*1.0);i++)
     {
         if(n%i==0)return 0;
     }
     return 1;
 }

int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        int ans=0;
        while(t--)
        {
            int temp;
            scanf("%d",&temp);
            if(prime(temp))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
