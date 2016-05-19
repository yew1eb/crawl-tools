#include<stdio.h>
#include<string.h>
int d[500005];
int l[500005];
int bis(int len,int x)
{
    int low=0,high=len-1,mid;
    while(low<=high)
    {
        mid=(low+high)>>1;
        if(d[mid]>x)
            high=mid-1;
        else if(d[mid]<x)
            low=mid+1;
        else return mid;
    }
    return low;
}
int main()
{
    int ca=1,len,i,n,a,b,x,pos;
    while(scanf("%d",&n)!=EOF)
    {
        d[0]=5000006;
        len=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            l[a]=b;
        }
        for(i=1;i<=n;i++)
        {
            x=l[i];
            if(x>d[len-1])
                d[len++]=x;
            else
            {
                pos=bis(len,x);
                d[pos]=x;
            }
        }
        printf("Case %d:\nMy king, at most %d %s can be built.\n\n",ca++,len,len>1?"roads":"road");
    }
    return 0;
}