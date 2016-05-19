#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T,n,i,j,k,a[100005],k1,k2,ans[100005],len,b[100005],flag;
    scanf("%d",&T);
    while(T--)
    {
        flag=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        k1=k2=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
             ans[1]=a[1];
             len=1;
                for(i=2;i<=n;i++){
                if(a[i]>=ans[len])
                    ans[++len]=a[i];

            else {
                int pos=upper_bound(ans+1,ans+len+1,a[i])-ans;
                ans[pos]=a[i];
            }
        }
        if(len==n-1||len==n)
           {printf("YES\n");continue;}
                for(i=1;i<=n;i++)
                    b[i]=a[n-i+1];
                ans[1]=b[1];
                len=1;
                for(i=2;i<=n;i++){
                if(b[i]>=ans[len])
                    ans[++len]=b[i];

            else {
                int pos=upper_bound(ans+1,ans+len+1,b[i])-ans;
                ans[pos]=b[i];
            }
        }
        if(len==n-1||len==n)
          printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
