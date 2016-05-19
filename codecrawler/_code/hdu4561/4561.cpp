#include<stdio.h>
int a[50000+100],n;
int solve(int s,int e)
{
    int i,cnt=0,st,ed,flag=1,ans=0;
    if(s==n+1) return 0;
     for(i=s;i<e;i++)
     {

         if(a[i]==-2)
         {
             if(flag)  {flag=0;st=i;}
             ed=i;
             cnt++;
         }
     }
    if(cnt%2==0) return e-s;
    if(ans<st-s) ans=st-s;
    if(ans<e-st-1) ans=e-st-1;
    if(ans<e-ed-1) ans=e-ed-1;
    if(ans<ed-s)  ans=ed-s;
    return ans;
}
int main()
{
    int cas,i,k,ans;
    scanf("%d",&cas);
    for(k=1;k<=cas;k++)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)  scanf("%d",&a[i]);
        a[0]=0;
        for(i=0;i<=n;)
        {
            if(a[i]==0)
            {
               int ii=i+1;
                while(1)
                {
                    i++;
                    if(i==n+1||a[i]==0)
                        {
                             int mid=solve(ii,i);
                             if(ans<mid)  ans=mid;
                              break;
                        }
                }
            }
        }
        printf("Case #%d: %d\n",k,ans);
    }
   return 0;
}
