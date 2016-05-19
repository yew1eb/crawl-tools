#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 101
int a[maxn],b[maxn];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++) scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int sa=0,sb=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>b[i]) sa+=2;
            else if(a[i]<b[i]) sb+=2;
            else
            {
                sa++;
                sb++;
            }
        }
        printf("%d vs %d\n",sa,sb);
    }
    return 0;
}
