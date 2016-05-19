#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 105
int a[N];
int main()
{
    int t,i,n;
//    freopen("text.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",(a[n-1]-a[0])*2);
        
    }
    return 0;
} 