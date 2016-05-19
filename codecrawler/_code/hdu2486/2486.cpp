#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1000010 ;
int a[maxn],b[maxn];
int n,k;
int solve(int n)
{
    int i=0,j=0;
    a[0]=1,b[0]=1;
    while(a[i]<n)
    { // a[i]表示当前能用来构造的最大项
      // b[i]表示由0...i,由a中数列所构成的最大值
        i++;
        a[i]=b[i-1]+1; // b[i-1]+1不能表示成a中的前i-1中某不连续几项的和，故需要构造
        while(a[j+1]*k<a[i])
            j++; // 找到最近的恰好与第i项差值在k倍以上的
        if(a[j]*k<a[i])
            b[i]=b[j]+a[i]; //用到了a中前i-2项，保证和为a中某不连续的话，可以取当前的j
        else // 倒数第二项和最后一项差值恰好为k倍时，能构造的最大项不变
            b[i]=a[i];
    }
    if(n==a[i])
        return -1;
    int ans;
   while(n)
   {
       if(n>=a[i])
            n-=a[i],ans=a[i];
       i--;
   }
   return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&k);
        int ans = solve(n);
        printf("Case %d: ",cas);
        if(ans==-1)
            printf("lose\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}