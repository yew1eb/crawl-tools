#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
const int maxn=1e6+10;
double a[maxn];
int main()
{
    int T,n,i;
    double d,q;
    int ans;
    int l,r;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&a[i]);
        if(n==1){
            puts("1");
            continue;
        }
        d=a[1]-a[0];
        q=a[1]/a[0];
        l=r=ans=2;
        for(i=2;i<n;i++){
           if(a[i]-a[i-1]==d)
            l++;
           else{
            d=a[i]-a[i-1];
            ans=max(ans,l);
            l=2;
           }
           if(a[i]/a[i-1]==q)
            r++;
           else{
            q=a[i]/a[i-1];
           ans=max(ans,r);
           r=2;
           }
        }
        ans=max(ans,max(l,r));
        printf("%d\n",ans);
    }
    return 0;
}