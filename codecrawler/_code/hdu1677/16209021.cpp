#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 20005
struct node
{
    int h;
    int w;
}a[N];
int dp[N];
int stack[N];
int cmp(node a,node b)
{
    if(a.w==b.w)
    return a.h<b.h;
    return a.w>b.w;
}
int lis(int n)
{
    memset(dp,0,sizeof(dp));
    memset(stack,0,sizeof(stack));
    int top=0;
    stack[top]=-99999999;
    int maxx=-1;
    for(int i=1; i<=n; i++)
    {
        if(a[i].h>=stack[top])
        {
            stack[++top]=a[i].h;
            dp[i]=top;
        }
        else
        {
            int l=1,r=top;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(a[i].h>=stack[mid])
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            stack[l]=a[i].h;
            dp[i]=l;
        }
        if(dp[i]>maxx)
        maxx=dp[i];
    }
    return maxx;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i].w,&a[i].h);
        }
        sort(a+1,a+n+1,cmp);
        int ans=lis(n);
        printf("%d\n",ans);
    }
    return 0;
}

