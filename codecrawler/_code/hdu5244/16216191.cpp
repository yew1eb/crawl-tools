#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int mmax = (1<<21);
const int inf = 0x3fffffff;
typedef __int64 LL;
LL b[mmax],a[mmax];
void cdq(int l,int r)
{
    if(l==r)
    {
        a[l]=b[l];
        return ;
    }
    int mid=(l+r)>>1;
    for(int i=l;i<=mid;i++)
    {
        LL tmp=b[i]+b[i+(r-l+1)/2];
        b[i]=(tmp-(b[r]-b[mid]))/2;
        b[i+(r-l+1)/2]-=b[i];
    }
    cdq(l,mid);
    cdq(mid+1,r);
}
int get(int x)
{
    int cnt=0;
    while(x)
    {
        if(x&1)
            cnt++;
        x/=2;
    }
    return cnt;
}
int c[mmax];
void test(int k)
{
    for(int i=0;i<(1<<k);i++)
    {
        int sum=0;
        for(int j=0;j<(1<<k);j++)
            if( get((i|j)^i ) %2==0 )
                sum+=a[j+1];
        b[i+1]=sum;
    }
}
int main()
{
    int t,k,ca=0;
    cin>>t;
    while(t--)
    {
        scanf("%d",&k);
        for(int i=1;i<=(1<<k);i++)
            scanf("%I64d",&b[i]);
//        for(int i=1;i<=(1<<k);i++)
//            scanf("%d",&a[i]);
//        test(k);
        cdq(1,(1<<k));
        printf("Case #%d: ",++ca);
        for(int i=1;i<=(1<<k);i++)
            printf("%I64d%c",a[i],i==(1<<k)?'\n':' ');
        //test(k);
    }
    return 0;
}



