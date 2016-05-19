/************
hdu3486
2016.1.19
748MS 18180K 1813 B C++
************/
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 200010
int  mx[MAXN][20], w[MAXN];
int n, k;
void rmqinit()
{
    for(int i = 1; i <= n; i++)  mx[i][0] = w[i];
    int m = (int)(log(n * 1.0) / log(2.0));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            mx[j][i] = mx[j][i - 1];
            if(j + (1 << (i - 1)) <= n) mx[j][i] = max(mx[j][i], mx[j + (1 << (i - 1))][i - 1]);
        }
}
int rmqmax(int l,int r)
{
    int m = (int)(log((r - l + 1) * 1.0) / log(2.0));
    return max(mx[l][m] , mx[r - (1 << m) + 1][m]);
}
int fun(int x,int y)//len num
{
    int ans=0;
    for(int i=1;i<=y;i++)
    {
        ans+=rmqmax((i-1)*x+1,i*x);
        if(ans>k) return ans;
    }
    return ans;
}
int main()
{
   // freopen("cin.txt","r",stdin);
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1) break;
        int sum=0,l,r,mid,ans=0;
        bool flag=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&w[i]);
            sum+=w[i];
            if(w[i]>=k)
            {

                flag=1;
            }
        }
        if(flag) {printf("1\n");continue;}
        if(sum<=k)
        {
            printf("-1\n");
            continue;
        }
        rmqinit();
        l=1,r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
          //  printf("l=%d,r=%d,mid=%d.",l,r,mid);
            int t=fun(n/mid,mid);//midæ¯æ¯ç»ä¸ªæ°
           // printf("t=%d\n",t);
            if(t>k)
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
