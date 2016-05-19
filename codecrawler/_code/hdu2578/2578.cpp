#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000005
int a[N],n,k;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int Find(int x)
{
    int l,r;
    l=1;r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<x) l=mid+1;
        else if(a[mid]>x) r=mid-1;
        else return 1;
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        qsort(a+1,n,sizeof(a[0]),cmp);
        int j=1;
        a[j++]=a[1];
        for(int i=2;i<=n;i++)
            if(a[i]!=a[i-1]) a[j++]=a[i];
        n=j-1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int temp;
            if(a[i]*2==k)
            {
                ans++;
                continue;
            }
            temp=k-a[i];
            if(Find(temp)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}